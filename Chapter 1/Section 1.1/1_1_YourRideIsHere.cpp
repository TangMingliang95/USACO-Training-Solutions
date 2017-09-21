#include <fstream>
#include <string>

using namespace std;

int main() 
{	
	ifstream fin("ride.in");
	string cometName, groupName;
	fin >> cometName >> groupName;
	fin.close();

	int cometProduct = 1;
	for (int i = 0; i < cometName.length(); ++i)
	{
		cometProduct *= cometName[i] - 'A' + 1;
	}

	int groupProduct = 1;
	for (int i = 0; i < groupName.length(); ++i)
	{
		groupProduct *= groupName[i] - 'A' + 1;
	}

	string result = ((cometProduct - groupProduct) % 47 == 0) ? "GO" : "STAY";

	ofstream fout("ride.out");
	fout << result << endl;
	fout.close();

	return 0;
}
