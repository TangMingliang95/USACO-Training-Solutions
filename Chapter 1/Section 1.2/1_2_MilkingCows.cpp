#include <algorithm>
#include <fstream>

using namespace std;

struct MilkTime
{
	int begin;
	int end;
};

MilkTime milkTimes[5000];
int N;
int maxMilkInterval = 0;
int maxRestInterval = 0;

bool CompareMilkTime(MilkTime a, MilkTime b);
void UpdateMaxMilkInterval(int milkIntervalBegin, int milkIntervalEnd);
void UpdateMaxRestInterval(int milkIntervalEnd, int index);

int main()
{
	ifstream fin("milk2.in");
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		fin >> milkTimes[i].begin >> milkTimes[i].end;
	}
	fin.close();

	sort(milkTimes, milkTimes + N, CompareMilkTime);

	int milkIntervalBegin = milkTimes[0].begin;
	int milkIntervalEnd = milkTimes[0].end;
	for (int i = 1; i < N; ++i)
	{
		if (milkTimes[i].begin <= milkIntervalEnd)
		{
			milkIntervalEnd = milkIntervalEnd > milkTimes[i].end ? milkIntervalEnd : milkTimes[i].end;
		}
		else
		{
			UpdateMaxMilkInterval(milkIntervalBegin, milkIntervalEnd);
			UpdateMaxRestInterval(milkIntervalEnd, i);

			milkIntervalBegin = milkTimes[i].begin;
			milkIntervalEnd = milkTimes[i].end;
		}
	}
	UpdateMaxMilkInterval(milkIntervalBegin, milkIntervalEnd);

	ofstream fout("milk2.out");
	fout << maxMilkInterval << " " << maxRestInterval << endl;
	fout.close();

	return 0;
}

bool CompareMilkTime(MilkTime a, MilkTime b)
{
	return a.begin < b.begin;
}

void UpdateMaxMilkInterval(int milkIntervalBegin, int milkIntervalEnd)
{
	int milkInterval = milkIntervalEnd - milkIntervalBegin;
	maxMilkInterval = maxMilkInterval > milkInterval ? maxMilkInterval : milkInterval;
}

void UpdateMaxRestInterval(int milkIntervalEnd, int index)
{
	int restInterval = milkTimes[index].begin - milkIntervalEnd;
	maxRestInterval = maxRestInterval > restInterval ? maxRestInterval : restInterval;
}
