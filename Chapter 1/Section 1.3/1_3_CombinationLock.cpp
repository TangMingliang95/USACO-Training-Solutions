#include <fstream>

using namespace std;

const int c_givenCombinationNum = 2;
const int c_dialsNum = 3;
const int c_errorRange = 2;
const int c_maxCombinationNum = 1000;

int g_numbers[c_givenCombinationNum][c_dialsNum];
int g_combinations[c_maxCombinationNum][c_dialsNum];

int DeduplicationCount(int combinations[][c_dialsNum], int length);
bool IsEqual(int comb1[], int comb2[]);
int GenerateCombinationsFromAll(int numbers[][c_dialsNum], int combinations[][c_dialsNum], int N);
int GenerateCombinationsFromOne(int numbers[], int combinations[][c_dialsNum], int N, int combination[], int count, int index);

int main()
{
	int N;
	ifstream fin("combo.in");
	fin >> N;
	for (int i = 0; i < c_givenCombinationNum; ++i)
	{
		for (int j = 0; j < c_dialsNum; ++j)
		{
			fin >> g_numbers[i][j];
		}
	}
	fin.close();

	int count = GenerateCombinationsFromAll(g_numbers, g_combinations, N);
	count = DeduplicationCount(g_combinations, count);
	
	ofstream fout("combo.out");
	fout << count << endl;
	fout.close();

	return 0;
}

int DeduplicationCount(int combinations[][c_dialsNum], int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		bool isRepeat = false;
		for (int j = 0; j < i; ++j)
		{
			if (IsEqual(combinations[i], combinations[j]))
			{
				isRepeat = true;
				break;
			}
		}

		if (!isRepeat)
		{
			++count;
		}
	}
	return count;
}

bool IsEqual(int comb1[], int comb2[])
{
	for (int i = 0; i < c_dialsNum; ++i)
	{
		if (comb1[i] != comb2[i])
		{
			return false;
		}		
	}
	return true;
}

int GenerateCombinationsFromAll(int numbers[][c_dialsNum], int combinations[][c_dialsNum], int N)
{
	int combination[c_dialsNum];
	int count = 0;

	for (int i = 0; i < c_givenCombinationNum; ++i)
	{
		count = GenerateCombinationsFromOne(numbers[i], combinations, N, combination, count, 0);
	}

	return count;
}

int GenerateCombinationsFromOne(int numbers[], int combinations[][c_dialsNum], int N, int combination[], int count, int index)
{
	if (index == c_dialsNum)
	{
		for (int i = 0; i < c_dialsNum; ++i)
		{
			combinations[count][i] = combination[i];
		}
		return count + 1;
	}

	for (int error = -c_errorRange; error <= c_errorRange; ++error)
	{
		int value = (numbers[index] + error) % N;
		combination[index] = value > 0 ? value : value + N;
		count = GenerateCombinationsFromOne(numbers, combinations, N, combination, count, index + 1);
	}
	return count;
}
