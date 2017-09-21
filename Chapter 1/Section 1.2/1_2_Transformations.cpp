#include <fstream>

using namespace std;

const int maxN = 10;
int N = 0;
char patternBefore[maxN][maxN];
char patternAfter[maxN][maxN];

int g_row;
int g_col;

void GetIndex(int row, int col, int method);
void GetIndexFromReflectionAndRotation(int row, int col, int rotationTimes, bool isReflect);
void GetIndexFromRotation(int row, int col, int rotationTimes);
void GetIndexFromRotation90(int row, int col);
void GetIndexFromRefelection(int row, int col);

int main()
{
	ifstream fin("transform.in");
	fin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			fin >> patternBefore[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			fin >> patternAfter[i][j];
		}
	}
	fin.close();

	int result = 9;
	for (int k = 1; k < 9; ++k)
	{
		bool transformSuccess = true;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				GetIndex(i, j, k);
				if (patternBefore[i][j] != patternAfter[g_row][g_col])
				{
					transformSuccess = false;
					break;
				}
			}
			if (!transformSuccess)
			{
				break;
			}
		}
		if (transformSuccess)
		{
			result = k;
			break;
		}
	}

	switch (result)
	{
	case 6:
	case 7:
		result = 5;
		break;
	case 8:
	case 9:
		result -= 2;
		break;
	default:
		break;
	}

	ofstream fout("transform.out");
	fout << result << endl;
	fout.close();

	return 0;
}

void GetIndex(int row, int col, int method)
{
	switch (method)
	{
	case 1:    // #1
		GetIndexFromReflectionAndRotation(row, col, 1, false);
		break;
	case 2:    // #2
		GetIndexFromReflectionAndRotation(row, col, 2, false);
		break;
	case 3:    // #3
		GetIndexFromReflectionAndRotation(row, col, 3, false);
		break;
	case 4:    // #4
		GetIndexFromReflectionAndRotation(row, col, 0, true);
		break;
	case 5:    // #5-1
		GetIndexFromReflectionAndRotation(row, col, 1, true);
		break;
	case 6:    // #5-2
		GetIndexFromReflectionAndRotation(row, col, 2, true);
		break;
	case 7:    // #5-3
		GetIndexFromReflectionAndRotation(row, col, 3, true);
		break;
	case 8:    // #6
		GetIndexFromReflectionAndRotation(row, col, 0, false);
		break;
	default:
		break;
	}
}

void GetIndexFromReflectionAndRotation(int row, int col, int rotationTimes, bool isReflect)
{
	g_row = row;
	g_col = col;

	if (isReflect)
	{
		GetIndexFromRefelection(g_row, g_col);
	}

	GetIndexFromRotation(g_row, g_col, rotationTimes);
}

void GetIndexFromRotation(int row, int col, int rotationTimes)
{
	g_row = row;
	g_col = col;
	for (int i = 0; i < rotationTimes; ++i)
	{
		GetIndexFromRotation90(g_row, g_col);
	}
}

void GetIndexFromRotation90(int row, int col)
{
	g_row = col;
	g_col = N - 1 - row;
}

void GetIndexFromRefelection(int row, int col)
{
	g_row = row;
	g_col = N - 1 - col;
}
