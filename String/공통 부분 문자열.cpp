#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sInput1, sInput2;
int Answer;
int DP[4001][4001];

int main()
{
	cin >> sInput1 >> sInput2;

	for (int i = 0; i < sInput1.size(); i++)
	{
		for (int j = 0; j < sInput2.size(); j++)
		{
			if (sInput1[i] == sInput2[j])
			{
				if (i == 0 || j == 0)
				{
					DP[i][j] = 1;
				}

				else
				{
					DP[i][j] = DP[i - 1][j - 1] + 1;
				}

				Answer = max(Answer, DP[i][j]);
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}