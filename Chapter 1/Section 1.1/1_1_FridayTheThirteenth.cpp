#include <fstream>

using namespace std;

bool IsLeapYear(int year);

const int dayNum = 7;
const int monthNum = 12;
const int leapMonthIndex = 2;
const int leapMonthLength = 28;
const int beginYear = 1900;
// Dec 13, 1899 is Wed
const int beginIndex = 4;
// Dec go first, then Jan, Feb, ...
int monthLength[monthNum] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int main() 
{	
	int N;
	ifstream fin("friday.in");
	fin >> N;
	fin.close();

	int dayCount[dayNum];
	for (int i = 0; i < dayNum; ++i)
	{
		dayCount[i] = 0;
	}

	int index = beginIndex;
	for (int i = 0; i < N; ++i)
	{
		monthLength[leapMonthIndex] = IsLeapYear(beginYear + i) ? leapMonthLength + 1 : leapMonthLength;
		for (int j = 0; j < monthNum; ++j)
		{
			index = (index + monthLength[j]) % dayNum;
			++dayCount[index];
		}
	}

	ofstream fout("friday.out");
	for (int i = 0; i < dayNum - 1; ++i)
	{
		fout << dayCount[i] << " ";
	}
	fout << dayCount[dayNum - 1] << endl;
	fout.close();

	return 0;
}

bool IsLeapYear(int year)
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}
