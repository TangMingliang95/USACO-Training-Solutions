#include <fstream>
#include <algorithm>

using namespace std;

const int c_maxStallNum = 200;
int cows[c_maxStallNum];
int intervals[c_maxStallNum];

int main()
{
	int M = 0;
	int S = 0;
	int C = 0;

	ifstream fin("barn1.in");
	fin >> M >> S >> C;
	for (int i = 0; i < C; ++i)
	{
		fin >> cows[i];
	}
	fin.close();

	int count = 0;
	if (M >= C)
	{
		count = C;
	}
	else
	{
		sort(cows, cows + C);

		for (int i = 0; i < C - 1; ++i)
		{
			intervals[i] = cows[i + 1] - cows[i] - 1;
		}
		sort(intervals, intervals + C - 1);

		count = cows[C - 1] - cows[0] + 1;
		for (int i = 0; i < M; ++i)
		{
			count -= intervals[C - 1 - i];
		}
	}
	
	ofstream fout("barn1.out");
	fout << count << endl;
	fout.close();

	return 0;
}
