// SPD_LAB2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Zadanie
{
public:
	int P;
	int W;
	int D;

	Zadanie();
	~Zadanie();

private:

};

Zadanie::Zadanie()
{
}

Zadanie::~Zadanie()
{
}


int K(int index, int ending, int n, std::vector<Zadanie> X)
{
	int k = (ending - X[index].D) * X[index].W;
    return k;
}

int F(int binaryIndex, int n, std::vector<Zadanie> &X, std::vector<int>& Wyniki)
{
	int best;
	for (int i = 1; i < n; i++)
	{
		best = F(binaryIndex - (1 << n), );
	}
}

int main()
{
	std::vector<Zadanie> X;
	X.reserve(100);
	std::vector<int> Wyniki;

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
