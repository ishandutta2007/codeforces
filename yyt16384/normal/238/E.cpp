#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 105;
const int MAXK = 105;
const int MAXS = 20005;
const int INF = 0x3f3f3f3f;

int n, s0, t0, q;
bool g[MAXN][MAXN];
int s[MAXK];
int t[MAXK];
int dist[MAXN][MAXN];
bool ok[MAXK][MAXN];
bool must[MAXK][MAXN];
int f[MAXK][MAXN];

void input()
{
	int m;
	scanf("%d%d%d%d", &n, &m, &s0, &t0);
	--s0; --t0;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x][y] = true;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d", &s[i], &t[i]);
		--s[i]; --t[i];
	}
}

void init()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (i == j) dist[i][j] = 0;
			else if (g[i][j]) dist[i][j] = 1;
			else dist[i][j] = INF;
		}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (int i = 0; i < q; ++i)
	{
		if (dist[s[i]][t[i]] == INF) continue;
		int cnt[MAXN] = {0};
		for (int j = 0; j < n; ++j)
			if (dist[s[i]][j] + dist[j][t[i]] == dist[s[i]][t[i]])
				ok[i][j] = true, ++cnt[dist[s[i]][j]];
		for (int j = 0; j < n; ++j)
			if (dist[s[i]][j] + dist[j][t[i]] == dist[s[i]][t[i]] && cnt[dist[s[i]][j]] == 1)
				must[i][j] = true;
	}
}

void solve()
{
	static int que[MAXS][2];
	static int badcnt[MAXK][MAXN];
	static bool vis[MAXK][MAXN];
	int qb = 0, qe = 0;

	for (int i = 0; i < q; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (ok[i][j] && g[j][k] && dist[j][t[i]] == dist[k][t[i]] + 1)
					++badcnt[i][j];

	memset(f, -1, sizeof(f));
	for (int i = 0; i < q; ++i)
	{
		f[i][t0] = 0;
		que[qe][0] = i;
		que[qe][1] = t0;
		qe = (qe + 1) % MAXS;
	}

	while (qb != qe)
	{
		int x = que[qb][0], y = que[qb][1];
		qb = (qb + 1) % MAXS;
		if (vis[x][y]) continue;
		vis[x][y] = true;
		if (must[x][y])
		{
			for (int i = 0; i < q; ++i)
				if (f[i][y] == -1)
				{
					f[i][y] = f[x][y] + 1;
					que[qe][0] = i;
					que[qe][1] = y;
					qe = (qe + 1) % MAXS;
				}
		}
		for (int i = 0; i < n; ++i)
			if (ok[x][i] && g[i][y] && dist[i][t[x]] == dist[y][t[x]] + 1)
			{
				--badcnt[x][i];
				if (badcnt[x][i] == 0)
				{
					f[x][i] = f[x][y];
					qb = (qb + MAXS - 1) % MAXS;
					que[qb][0] = x;
					que[qb][1] = i;
				}
			}
	}

	int ans = -1;
	for (int i = 0; i < q; ++i)
		if (must[i][s0] && f[i][s0] != -1 && (ans == -1 || f[i][s0] + 1 < ans))
			ans = f[i][s0] + 1;

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8772.in", "r", stdin);
	freopen("8772.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}