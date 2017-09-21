#include <fstream>
#include <string>

using namespace std;

const char c_color1 = 'b';
const char c_color2 = 'r';

int FindFirstColorIndex(const string &necklace);
bool FindNextColorIndex(const string &necklace, int pointIndex[]);

int main()
{
	int N;
	string necklace;
	ifstream fin("beads.in");
	fin >> N >> necklace;
	fin.close();

	necklace += necklace;	
	
	// r ... b ... b ... r ... r ... b
	int pointIndex[6];
	int maxLength = 0;

	// Initialize
	for (int i = 0; i < 3; ++i)
	{
		pointIndex[i] = -1;
	}
	pointIndex[3] = FindFirstColorIndex(necklace);

	// All beads are white
	if (pointIndex[3] == -1)
	{
		maxLength = N;
	}
	else
	{
		while (FindNextColorIndex(necklace, pointIndex))
		{
			int length = pointIndex[5] - 1 - pointIndex[0];

			maxLength = maxLength > length ? maxLength : length;

			for (int i = 0; i < 4; ++i)
			{
				pointIndex[i] = pointIndex[i + 2];
			}
		}

		// All beads are blue or red
		if (pointIndex[2] == -1)
		{
			maxLength = N;
		}		
	}

	maxLength = maxLength < N ? maxLength : N;
	ofstream fout("beads.out");
	fout << maxLength << endl;
	fout.close();

	return 0;
}

int FindFirstColorIndex(const string &necklace)
{
	for (int i = 0; i < necklace.length(); ++i)
	{
		if (necklace[i] == c_color1 || necklace[i] == c_color2)
		{
			return i;
		}
	}
	return -1;
}

bool FindNextColorIndex(const string &necklace, int pointIndex[])
{
	char color = necklace[pointIndex[3]];
	char stopColor = color == c_color1 ? c_color2 : c_color1;

	for (int i = pointIndex[3]; i < necklace.length(); ++i)
	{
		if (necklace[i] == color)
		{
			pointIndex[4] = i;
		}
		else if (necklace[i] == stopColor)
		{
			pointIndex[5] = i;
			return true;
		}
	}
	return false;
}
