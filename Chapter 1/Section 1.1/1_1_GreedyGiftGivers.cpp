#include <fstream>
#include <string>

using namespace std;

struct Person
{
	string name;
	int money;
};

Person &FindPersonByName(string name, Person person[], int NP);

int main() 
{	
	int NP;
	Person person[10];	
	ifstream fin("gift1.in");

	fin >> NP;
	for (int i = 0; i < NP; ++i)
	{
		fin >> person[i].name;
		person[i].money = 0;
	}

	for (int i = 0; i < NP; ++i)
	{
		string name;
		int moneyOut, giftNum;
		fin >> name >> moneyOut >> giftNum;
		int giftValue = (giftNum == 0) ? 0 : moneyOut / giftNum;

		FindPersonByName(name, person, NP).money -= giftValue * giftNum;
		
		for (int i = 0; i < giftNum; ++i)
		{
			fin >> name;
			FindPersonByName(name, person, NP).money += giftValue;
		}
	}

	fin.close();

	ofstream fout("gift1.out");
	for (int i = 0; i < NP; ++i)
	{
		fout << person[i].name << " " << person[i].money << endl;
	}
	fout.close();

	return 0;
}

Person &FindPersonByName(string name, Person person[], int NP)
{
	for (int i = 0; i < NP; ++i)
	{
		if (name == person[i].name)
		{
			return person[i];
		}
	}
}
