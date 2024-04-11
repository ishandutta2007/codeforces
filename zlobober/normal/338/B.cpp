#include <cstdio>
#include <vector>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 100500;

vector<int> E[N];
bool bad[N];
int mxd[N];

const int inf = 1e9;

void DFS1(int x, int p = -1)
{
	mxd[x] = -inf;
	if (bad[x])
		mxd[x] = 0;
	for (int i = 0; i < E[x].size(); i++)
	{
		int y = E[x][i];
		if (y == p)
		{
			E[x].erase(E[x].begin() + i), --i;
			continue;
		}
		DFS1(y, x);
		mxd[x] = max(mxd[x], mxd[y] + 1);
	}
}

int pt = 0;
int mxl[2 * N], mxr[2 * N];

bool good[N];

int n, m, d;

void DFS2(int x, int up = -inf)
{
	if (bad[x])
		up = max(up, 0);
	mxl[pt] = -inf;
	for (int i = 0; i < E[x].size(); i++)
	{
		int y = E[x][i];
		mxl[pt + i + 1] = max(mxl[pt + i], 1 + mxd[y]);
	}
	mxr[pt + E[x].size()] = -inf;
	for (int i = E[x].size(); i > 0; i--)
	{
		int y = E[x][i - 1];
		mxr[pt + i - 1] = max(mxr[pt + i], 1 + mxd[y]);
	}
	int opt = pt;
	pt += E[x].size() + 1;
	if (max(mxd[x], up) <= d)
		good[x] = true;
	for (int i = 0; i < E[x].size(); i++)
	{
		int y = E[x][i];
		DFS2(y, 1 + max(up, max(mxl[opt + i], mxr[opt + i + 1])));
	}
	pt -= E[x].size() + 1;
}

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);	
		bad[t] = true;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS1(1);
	DFS2(1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (good[i])
			ans++, eprintf("%d ", i);
	}
	eprintf("\n");
	printf("%d\n", ans);
}