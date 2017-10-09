#include <fstream>

using namespace std;

int g_multipliers1[1000];
int g_multipliers2[100];
int g_digits[10];
int g_digitLength;

int GenerateNum(int num, int nums[], int count, int digits[], int digitsLength, int digitNum);
bool IsLegalNum(int num, int digitNum, int digits[], int digitsLength);
bool IsLegalDigit(int digit, int digits[], int digitsLength);

int main()
{
	ifstream fin("crypt1.in");
	fin >> g_digitLength;
	for (int i = 0; i < g_digitLength; ++i)
	{
		fin >> g_digits[i];
	}
	fin.close();

	int count1 = GenerateNum(0, g_multipliers1, 0, g_digits, g_digitLength, 3);
	int count2 = GenerateNum(0, g_multipliers2, 0, g_digits, g_digitLength, 2);

	int result = 0;
	for (int i = 0; i < count1; ++i)
	{
		for (int j = 0; j < count2; ++j)
		{
			int digit0 = g_multipliers2[j] % 10;
			int digit1 = g_multipliers2[j] / 10;
			if (IsLegalNum(digit0 * g_multipliers1[i], 3, g_digits, g_digitLength)
				&& IsLegalNum(digit1 * g_multipliers1[i], 3, g_digits, g_digitLength)
				&& IsLegalNum(g_multipliers2[j] * g_multipliers1[i], 4, g_digits, g_digitLength))
			{
				result += 1;
			}
		}
	}
	
	ofstream fout("crypt1.out");
	fout << result << endl;
	fout.close();

	return 0;
}

int GenerateNum(int num, int nums[], int count, int digits[], int digitsLength, int digitNum)
{
	if (digitNum == 1)
	{
		for (int i = 0; i < digitsLength; ++i)
		{
			nums[count] = num * 10 + digits[i];
			++count;
		}
	}
	else
	{
		for (int i = 0; i < digitsLength; ++i)
		{
			if (num == 0 && digits[i] == 0)
			{
				continue;
			}
			count = GenerateNum(num * 10 + digits[i], nums, count, digits, digitsLength, digitNum - 1);
		}
	}
	
	return count;
}

bool IsLegalNum(int num, int digitNum, int digits[], int digitsLength)
{
	while (num != 0)
	{
		int digit = num % 10;
		if (!IsLegalDigit(digit, digits, digitsLength))
		{
			return false;
		}
		num /= 10;
		--digitNum;
	}
	return digitNum == 0 ? true : false;
}

bool IsLegalDigit(int digit, int digits[], int digitsLength)
{
	for (int i = 0; i < digitsLength; ++i)
	{
		if (digit == digits[i])
		{
			return true;
		}
	}
	return false;
}
