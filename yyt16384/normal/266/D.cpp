#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 205;
const int INF = 0x3f3f3f3f;

int n;
int g[MAXN][MAXN];
int f[MAXN][MAXN];

void input()
{
	int m;
	scanf("%d%d", &n, &m);
	memset(g, INF, sizeof(g));
	for (int i = 0; i < n; ++i)
		g[i][i] = 0;
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		w *= 2;
		g[x][y] = g[y][x] = w;
	}
}

void init()
{
	memcpy(f, g, sizeof(f));
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
}

bool cmp(const std::pair<int, int> &x, const std::pair<int, int> &y)
{
	return x.first < y.first;
}

void solve()
{
	static std::pair<int, int> d[MAXN];
	int ans = INF;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (g[i][j] < INF)
			{
				for (int k = 0; k < n; ++k)
					d[k] = std::make_pair(f[i][k], f[j][k]);
				std::sort(d, d + n, cmp);
				for (int k = n - 1, sufmax = 0, now; k >= 0; --k)
				{
					if (abs(d[k].first - sufmax) <= g[i][j])
						now = (sufmax + d[k].first + g[i][j]) / 2;
					else
						now = std::max(sufmax, d[k].first);
					if (now < ans)
						ans = now;
					if (d[k].second > sufmax)
						sufmax = d[k].second;
				}
			}
	printf("%f\n", ans / 2.0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("266D.in", "r", stdin);
	freopen("266D.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}