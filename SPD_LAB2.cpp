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

std::vector<Task> getValues(int n) {
    std::vector<Task> task;
    std::string tmp;
    std::string find;

    switch (n) {
    case 10:
        find = "data.10:"; break;
    case 11:
        find = "data.11:"; break;
    case 12:
        find = "data.12:"; break;
    case 13:
        find = "data.13:"; break;
    case 14:
        find = "data.14:"; break;
    case 15:
        find = "data.15:"; break;
    case 16:
        find = "data.16:"; break;
    case 17:
        find = "data.17:"; break;
    case 18:
        find = "data.18:"; break;
    case 19:
        find = "data.19:"; break;
    case 20:
        find = "data.20:"; break;
    default:
        break;
    }

    int count;
    Task tmp2;
    std::ifstream data("witi.data.txt");

    while (tmp != find) {
        data >> tmp;
    }
    data >> count;
    for (int i = 0; i < count; i++) {
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

int F(int binaryIndex, std::vector<Task> &X, std::vector<int>& Wyniki)
{
	int best = -1;
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
				best = newF;
			else if (newF < best)
				best = newF;
		}
		
	}
}

int main()
{
    
    std::vector<std::vector<Task>> tasks;
    std::vector<int> Wyniki;
    int count = 10;

    while(count < 21)
    {
        std::vector<Task> temp;
        temp = getValues(count);
        tasks.push_back(temp);
        count++;
    }

    int wynik = F(0b1111111111, tasks[0], Wyniki);
    std::cout << Wyniki[std::pow(2,10)];
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
