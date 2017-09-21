#include <fstream>
#include <string>

using namespace std;

const int c_maxDigits = 17;

bool IsPalindromicInBase(int num, int base);
string GetNumStringInBase(int num, int base);
int GetAllDigitsInBase(int *digits, int num, int base);

int main()
{
	int B;
	ifstream fin("palsquare.in");
	fin >> B;
	fin.close();

	ofstream fout("palsquare.out");
	for (int i = 1; i < 301; ++i)
	{
		int square = i * i;
		if (IsPalindromicInBase(square, B))
		{
			fout << GetNumStringInBase(i, B) << " " << GetNumStringInBase(square, B) << endl;
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

string GetNumStringInBase(int num, int base)
{
	int digits[c_maxDigits];
	int digitNum = GetAllDigitsInBase(digits, num, base);

	string numString;
	for (int i = digitNum - 1; i >= 0; --i)
	{
		numString += char(digits[i] + (digits[i] > 9 ? 'A' - 10: '0'));
	}
	return numString;
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
