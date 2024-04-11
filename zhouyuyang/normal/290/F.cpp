#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 25;

bool v[MAXN], gra[MAXN][MAXN];
vector <int> adj[MAXN];
int n, m, d[MAXN];

inline void DFS(int x)
{
	v[x] = 1;
	for (auto y : adj[x])
		if (!v[y])
			return DFS(y);
}

int main()
{
	n = Read(), m = Read();
	for (int i = 1, x, y; i <= m; i ++)
	{
		x = Read(), y = Read();
		if (x == y || gra[x][y])
			continue;
		gra[x][y] = gra[y][x] = true;
		adj[x].pb(y), adj[y].pb(x);
		d[x] ++, d[y] ++;
	}
	for (int i = 1; i <= n; i ++)
		sort(adj[i].begin(), adj[i].end(), [&](int x, int y) { return mp(d[x], x) < mp(d[y], y); });
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= n; j ++)
			v[j] = 0;
		DFS(i);
		bool flg = true;
		for (int j = 1; j <= n; j ++)
			flg &= v[j];
		if (flg)
			return puts("Yes"), 0;
	}
	return puts("No"), 0;
}