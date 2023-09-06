#include <bits/stdc++.h>
using namespace std;

const int max_n = 40;
bool che[max_n + 1];

vector<int> era(int max_n)
{
	vector<int> v;
	for (int i = 2; i <= max_n; i++)
	{
		if (che[i])
			continue;
		for (int j = 2 * i; j <= max_n; j += i)
		{
			cout << j << "\n ";
			che[j] = 1;
		}
	}
	for (int i = 2; i <= max_n; i++)
	{
		if (che[i] == 0)
			v.push_back(i);
	}
	return v;
}

int main()
{
	vector<int> a = era(max_n);
	for (int i : a)
		cout << i << " ";
}