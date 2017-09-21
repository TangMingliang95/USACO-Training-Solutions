#include <fstream>
#include <string>

using namespace std;

const int c_maxDictEntryNum = 5000;
const string c_letters = "ABCDEFGHIJKLMNOPRSTUVWXY";
string g_nameDict[c_maxDictEntryNum];
int g_dictEntryNum = 0;

string GetNumStringFromName(const string &letters, const string &name);
int GetNumberFromLetter(const string &letters, char letter);

int main()
{
	string numString;
	ifstream fin("namenum.in");
	fin >> numString;
	fin.close();

	fin.open("dict.txt");
	g_dictEntryNum = 0;
	while (fin >> g_nameDict[g_dictEntryNum])
	{
		++g_dictEntryNum;
	}
	fin.close();

	int count = 0;
	ofstream fout("namenum.out");

	for (int i = 0; i < g_dictEntryNum; ++i)
	{
		if (numString == GetNumStringFromName(c_letters, g_nameDict[i]))
		{
			fout << g_nameDict[i] << endl;
			++count;
		}
	}
	if (count == 0)
	{
		fout << "NONE" << endl;
	}

	fout.close();

	return 0;
}

string GetNumStringFromName(const string &letters, const string &name)
{
	string numString = "";
	for (int i = 0; i < name.length(); ++i)
	{
		numString += GetNumberFromLetter(letters, name[i]) + '0';
	}
	return numString;
}

int GetNumberFromLetter(const string &letters, char letter)
{
	for (int i = 0; i < letters.length(); ++i)
	{
		if (letter == letters[i])
		{
			return i / 3 + 2;
		}
	}
	return -1;
}
