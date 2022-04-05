// SPD_LAB2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>


class Task
{
public:
	int P;
	int W;
	int D;

	Task();
	~Task();

private:

};

Task::Task()
{
}

Task::~Task()
{
}

void display(std::vector<Task> tasks) {
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "P: " << tasks[i].P << "\tW: " << tasks[i].W << "\tD: " << tasks[i].D << std::endl;
    }
}

std::vector<Task> getValues(int index)
{
    std::vector<Task> task;
    std::string tmp;
    std::string find = "data." + std::to_string(index) + ":";
    //std::cout << find << std::endl;
    

    int count;
    Task tmp2;
    std::ifstream data("witi.data.txt");

    while (tmp != find)
    {
        data >> tmp;
    }
    data >> count;
    for (int i = 0; i < count; i++)
    {
        data >> tmp2.P;
        data >> tmp2.W;
        data >> tmp2.D;
        task.push_back(tmp2);
    }
    data.close();
    return task;
}



int K(int index, int ending, std::vector<Task> X)
{
	
	int k = std::max(ending - X[index].D, 0) * X[index].W;
    return k;
}

std::pair<int,std::pair<int, int>> F(int binaryIndex, std::vector<Task>& X, std::vector<int>& Wyniki)
{
	int best = -1;
    int bestIndex = -1;
	int newF;
	int n = X.size();
	//binary = 0b0001

	int ending = 0;
    
	for (int i = 0; i < n; ++i)
	{
		if (binaryIndex & (1 << i))
			ending += X[i].P;
	}

	

	for (int i = 0; i < n; i++)
	{

		

		if (binaryIndex & (1 << i))
		{
			newF = Wyniki[binaryIndex - (1 << i)] + K(i, ending, X);

            

            if (best == -1)
            {
                best = newF;
                bestIndex = i;
            }
            else if (newF <= best)
            {
                best = newF;
                bestIndex = i;
                
            }
		}	
	}

    auto wynik = std::make_pair( best, std::make_pair(bestIndex, binaryIndex - (1 << bestIndex)) );
    return wynik;
}

int main()
{
    
    std::vector<std::vector<Task>> tasks;
    std::vector<int> Wyniki;
    std::vector<int> Indeksy;
    std::vector<int> IndeksyPoprzedniego;
    std::vector<int> Kolejnosc;
    
    int start = 10;
    int stop = 21;
    int count = stop - start;
    int x = start;

    //wczytywanie danych
    while(x <= stop)
    {
        std::vector<Task> temp;
        temp = getValues(x);
        tasks.push_back(temp);
        x++;
    }


    for (int k = 0; k < count; k++)
    {
        int taskNum = k;
        int N = tasks[taskNum].size();
        Wyniki.resize(std::pow(2, N));
        Indeksy.resize(std::pow(2, N));
        IndeksyPoprzedniego.resize(std::pow(2, N));
        Kolejnosc.resize(N);


        for (int i = 1; i < std::pow(2, N); i++)
        {
            auto x = F(i, tasks[taskNum], Wyniki);
            Wyniki[i] = x.first;
            Indeksy[i] = x.second.first;
            IndeksyPoprzedniego[i] = x.second.second;

        }
        //kolejnoœæ
        Kolejnosc[N - 1] = Indeksy[std::pow(2, N) - 1];
        int next = IndeksyPoprzedniego[std::pow(2, N) - 1];

        for (int i = 2; i <= N; i++)
        {
            Kolejnosc[N - i] = Indeksy[next];
            next = IndeksyPoprzedniego[next];
        }

        int wynik = Wyniki[std::pow(2, N) - 1];

        
        std::cout << "data." << k << ":" << std::endl;
        std::cout << wynik << std::endl;;
        for (int i = 0; i < N; i++)
        {
            std::cout << Kolejnosc[i] + 1 << " ";
        }
        std::cout << std::endl;
    }
    

    

    
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
