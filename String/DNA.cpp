#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, M;

int Calcul_HammingDistance(string str1, string str2)
{
	int nValue = 0;

	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] != str2[i])
		{
			nValue++;
		}
	}

	return nValue;
}

bool cmp(pair<char, int> p1, pair<char, int> p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}

	return p1.second > p2.second;
}

int main()
{
	cin >> N >> M;

	vector<string> vecStr;
	map<char, int> mapStr;
	string Answer = "";
	int cnt_Answer = 0;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecStr.push_back(sTemp);
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			mapStr[vecStr[i][j]]++;
		}

		vector<pair<char, int>> vecTemp(mapStr.begin(), mapStr.end());
		sort(vecTemp.begin(), vecTemp.end(), cmp);
		mapStr.clear();

		Answer += vecTemp.front().first;
	}	

	for (int i = 0; i < N; i++)
	{
		cnt_Answer += Calcul_HammingDistance(vecStr[i], Answer);
	}

	cout << Answer << '\n';
	cout << cnt_Answer << '\n';	

	return 0;
}