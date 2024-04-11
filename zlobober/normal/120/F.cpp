#include <iostream>
#include <list>
#include <cstdio>
using namespace std;

const int N = 150;
list<int> E[N];

int ans = 0;

void DFS(int x, int p, int d)
{
	ans = max(ans, d);
	for (list<int>::iterator it = E[x].begin(); it != E[x].end(); it++)
	{
		if (*it == p)
			continue;
		DFS(*it, x, d + 1);
	}
}


int count()
{
	ans = 0;
	for (int i = 0; i < N; i++)
		E[i].clear();
	int m;
	cin >> m;
	int a, b;
	for (int i = 0; i < m - 1; i++)
		cin >> a >> b, E[a].push_back(b), E[b].push_back(a);
	for (int i = 1; i <= m; i++)
		DFS(i, -1, 0);
	return ans;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		t += count();
	}
	t;
	cout << t;
}