#include <fstream>
#include <algorithm>

using namespace std;

struct Farmer
{
	int price;
	int amount;
};

const int c_maxFarmerNum = 5000;
Farmer farmers[c_maxFarmerNum];

bool CompareFarmer(const Farmer &a, const Farmer &b);

int main()
{
	int N = 0;
	int M = 0;

	ifstream fin("milk.in");

	fin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		fin >> farmers[i].price >> farmers[i].amount;
	}

	fin.close();

	sort(farmers, farmers + M, CompareFarmer);

	int pay = 0;
	for (int i = 0; N > 0; ++i)
	{
		int amount = farmers[i].amount < N ? farmers[i].amount : N;
		pay += amount * farmers[i].price;
		N -= amount;
	}

	ofstream fout("milk.out");
	fout << pay << endl;
	fout.close();

	return 0;
}

bool CompareFarmer(const Farmer &a, const Farmer &b)
{
	return a.price < b.price;
}
