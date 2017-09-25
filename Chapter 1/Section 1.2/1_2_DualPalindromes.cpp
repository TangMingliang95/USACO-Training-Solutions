#include <fstream>

using namespace std;

const int c_maxDigits = 20;
const int c_baseBegin = 2;
const int c_baseEnd = 11;

bool IsPalindromicInBase(int num, int base);
int GetAllDigitsInBase(int *digits, int num, int base);

int main()
{
	int N = 0;
	int S = 0;
	ifstream fin("dualpal.in");
	fin >> N >> S;
	fin.close();

	ofstream fout("dualpal.out");
	for (int num = S + 1; N > 0; ++num)
	{
		int count = 0;
		for (int base = c_baseBegin; base < c_baseEnd; ++base)
		{
			if (IsPalindromicInBase(num, base))
			{
				++count;
			}

			if (count > 1)
			{
				break;
			}
		}

		if (count > 1)
		{
			--N;
			fout << num << endl;
		}
	}
	fout.close();

	return 0;
}

bool IsPalindromicInBase(int num, int base)
{
	int digits[c_maxDigits];
	int digitNum = GetAllDigitsInBase(digits, num, base);

	for (int i = 0; i * 2 < digitNum - 1; ++i)
	{
		if (digits[i] != digits[digitNum - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int GetAllDigitsInBase(int *digits, int num, int base)
{
	int digitNum = 0;
	while (num > 0)
	{
		digits[digitNum] = num % base;
		num /= base;
		++digitNum;
	}
	return digitNum;
}
