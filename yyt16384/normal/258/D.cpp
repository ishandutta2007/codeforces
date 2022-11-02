#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1005;
const int MAXM = 1005;

int n, m;
int a[MAXN];
int q[MAXM][2];
double f[MAXN][MAXN];

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &q[i][0], &q[i][1]);
		--q[i][0]; --q[i][1];
	}
}

void solve()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			f[i][j] = (a[i] > a[j]);

	for (int i = 0; i < m; ++i)
	{
		int x = q[i][0];
		int y = q[i][1];
		for (int j = 0; j < n; ++j)
			if (j != x && j != y)
			{
				f[j][x] = f[j][y] = (f[j][x] + f[j][y]) / 2;
				f[x][j] = f[y][j] = 1 - f[j][x];
			}
		f[x][y] = f[y][x] = 0.5;
	}

	double ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			ans += f[i][j];
	printf("%.10f\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9195.in", "r", stdin);
	freopen("9195.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}