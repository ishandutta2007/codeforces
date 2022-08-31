#include <iostream>
#include <list>
#include <cstdio>
using namespace std;

#define HASFILES 1

#define TASK ololo

const int N = 200000;

bool was[N];

list<pair<int, int> > E[N];

int cwas = 0;
long long ans = 0;

long long D[N][2];

void DFS(int x)
{
	was[x] = 1;
	long long best = 1e10;
	for (list<pair<int, int> >::iterator it = E[x].begin(); it != E[x].end(); it++)
	{
		if (!was[it->first])
		{
			DFS(it->first),	D[x][1] += D[it->first][1] + 2 * it->second;
			best = min(best, D[it->first][0] - D[it->first][1] - it->second);
		}
	}
	if (best == 1e10)
	{
		D[x][0] = D[x][1] = 0;
		return;
	}
	D[x][0] = D[x][1] + best;
}

void sDFS()
{
	DFS(1);
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	int x, y, w;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y >> w;
		E[x].push_back(make_pair(y, w));
		E[y].push_back(make_pair(x, w));
	}
	sDFS();
	cout << D[1][0];
	return 0;
}