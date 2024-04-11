#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1005;
const int MAXC = 265;

int n, m, d;
char s[MAXN][MAXN];
int cnt;
int x[MAXC];
int y[MAXC];
int vis[MAXN][MAXN];
int col;

void init()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'R')
			{
				x[cnt] = i;
				y[cnt] = j;
				++cnt;
				if (cnt > 4 * d * d + 4 * d + 2)
					return;
			}
	}
}

void BFS(int x0, int y0)
{
	const int DR[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	static int que[MAXC][2];
	static int dist[MAXN][MAXN];
	int qb = 0, qe = 1;
	que[0][0] = x0;
	que[0][1] = y0;
	vis[x0][y0] = ++col;
	dist[x0][y0] = 0;
	while (qb < qe)
	{
		int xx = que[qb][0];
		int yy = que[qb][1];
		++qb;
		if (dist[xx][yy] < d)
		{
			for (int k = 0; k < 4; ++k)
			{
				int nx = xx + DR[k][0];
				int ny = yy + DR[k][1];
				if (s[nx][ny] != 'X' && vis[nx][ny] != col)
				{
					vis[nx][ny] = col;
					dist[nx][ny] = dist[xx][yy] + 1;
					que[qe][0] = nx;
					que[qe][1] = ny;
					++qe;
				}
			}
		}
	}
}

void solve()
{
	if (cnt > 4 * d * d + 4 * d + 2)
	{
		printf("-1\n");
		return;
	}
	for (int x1 = std::max(x[0] - d, 0); x1 <= std::min(x[0] + d, n - 1); ++x1)
		for (int y1 = std::max(y[0] - d, 0); y1 <= std::min(y[0] + d, m - 1); ++y1)
			if (s[x1][y1] != 'X' && abs(x1 - x[0]) + abs(y1 - y[0]) <= d)
			{
				BFS(x1, y1);
				static int novis[MAXC];
				int nvn = 0;
				for (int p = 0; p < cnt; ++p)
					if (vis[x[p]][y[p]] != col)
						novis[nvn++] = p;
				int r = novis[0];
				if (nvn == 0)
					r = 0;
				for (int x2 = std::max(x[r] - d, 0); x2 <= std::min(x[r] + d, n - 1); ++x2)
					for (int y2 = std::max(y[r] - d, 0); y2 <= std::min(y[r] + d, m - 1); ++y2)
						if (s[x2][y2] != 'X' && abs(x2 - x[r]) + abs(y2 - y[r]) <= d && !(x1 == x2 && y1 == y2))
						{
							BFS(x2, y2);
							bool flag = true;
							for (int p = 0; p < nvn; ++p)
								if (vis[x[novis[p]]][y[novis[p]]] != col)
								{
									flag = false;
									break;
								}
							if (flag)
							{
								printf("%d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
								return;
							}
						}
			}
	printf("-1\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("254D.in", "r", stdin);
	freopen("254D.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}