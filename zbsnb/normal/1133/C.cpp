//https://www.lydsy.com/JudgeOnline/problem.php?id=2038
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	map<int,int> a;
	int n; cin >> n;
	while (n--)
	{
		int tmp; cin >> tmp;
		for (int i = 0; i <= 5; i++)
		{
			a[tmp + i]++;
		}
	}
	int maxn = 0;
	for (map<int, int>::iterator it = a.begin(); it != a.end(); it++)
	{
		maxn = max(maxn, it->second);
	}
	cout << maxn << endl;
}