#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1005;
const int MAXS = 2 * MAXN;

struct rect
{
	int x1, y1;
	int x2, y2;

	rect() {}
	rect(int x1_, int y1_, int x2_, int y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_)
	{
		if (x1 > x2) std::swap(x1, x2);
		if (y1 > y2) std::swap(y1, y2);
		++x2; ++y2;
	}
};

int n, m1, m2;
rect a[MAXN];
int r1[MAXS];
int r2[MAXS];
bool g[MAXS][MAXS];

void input()
{
	scanf("%d", &n);
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i)
	{
		char type;
		int len;
		scanf(" %c%d", &type, &len);
		if (type == 'L') a[i] = rect(x, y, x - len, y), x -= len;
		else if (type == 'R') a[i] = rect(x, y, x + len, y), x += len;
		else if (type == 'U') a[i] = rect(x, y, x, y - len), y -= len;
		else if (type == 'D') a[i] = rect(x, y, x, y + len), y += len;
	}
}

void init()
{
	for (int i = 0; i < n; ++i)
	{
		r1[2 * i] = a[i].x1;
		r1[2 * i + 1] = a[i].x2;
	}
	std::sort(r1, r1 + 2 * n);
	m1 = std::unique(r1, r1 + 2 * n) - r1;
	for (int i = 0; i < n; ++i)
	{
		a[i].x1 = std::lower_bound(r1, r1 + m1, a[i].x1) - r1;
		a[i].x2 = std::lower_bound(r1, r1 + m1, a[i].x2) - r1;
	}
	--m1;

	for (int i = 0; i < n; ++i)
	{
		r2[2 * i] = a[i].y1;
		r2[2 * i + 1] = a[i].y2;
	}
	std::sort(r2, r2 + 2 * n);
	m2 = std::unique(r2, r2 + 2 * n) - r2;
	for (int i = 0; i < n; ++i)
	{
		a[i].y1 = std::lower_bound(r2, r2 + m2, a[i].y1) - r2;
		a[i].y2 = std::lower_bound(r2, r2 + m2, a[i].y2) - r2;
	}
	--m2;
}

void fill(const rect &x)
{
	for (int i = x.x1; i < x.x2; ++i)
		for (int j = x.y1; j < x.y2; ++j)
			g[i][j] = true;
}

void solve()
{
	const int DR[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for (int i = 0; i < n; ++i)
		fill(a[i]);
	static int que[MAXS * MAXS][3];
	static bool vis[MAXS][MAXS];
	int qb = 0, qe = 0;
	for (int i = 0; i < m1 - 1; ++i)
		if (!g[i][0])
			que[qe][0] = i, que[qe][1] = 0, ++qe, vis[i][0] = true;
	for (int i = 1; i < m1; ++i)
		if (!g[i][m2 - 1])
			que[qe][0] = i, que[qe][1] = m2 - 1, ++qe, vis[i][m2 - 1] = true;
	for (int i = 1; i < m2; ++i)
		if (!g[0][i])
			que[qe][0] = 0, que[qe][1] = i, ++qe, vis[0][i] = true;
	for (int i = 0; i < m2 - 1; ++i)
		if (!g[m1 - 1][i])
			que[qe][0] = m1 - 1, que[qe][1] = i, ++qe, vis[m1 - 1][i] = true;

	while (qb < qe)
	{
		int x = que[qb][0], y = que[qb][1];
		++qb;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + DR[i][0], ny = y + DR[i][1];
			if (nx >= 0 && nx < m1 && ny >= 0 && ny < m2 && !g[nx][ny] && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				que[qe][0] = nx;
				que[qe][1] = ny;
				++qe;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < m1; ++i)
		for (int j = 0; j < m2; ++j)
			if (!vis[i][j])
				ans += (long long)(r1[i + 1] - r1[i]) * (r2[j + 1] - r2[j]);

	printf("%"LLFORMAT"d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8745.in", "r", stdin);
	freopen("8745.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}