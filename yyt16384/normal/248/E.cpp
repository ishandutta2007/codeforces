#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXC = 105;
const int MAXS = 500105;
const int MAXK = 6;

int n;
int a[MAXN];
int ori[MAXN];
double c[MAXS][MAXK];
double f[MAXN][MAXC];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		f[i][a[i]] = 1;
		ori[i] = a[i];
	}
}

void solve()
{
	c[0][0] = 1;
	for (int i = 1; i < MAXS; ++i)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i && j < MAXK; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}

	double ans = 0;
	for (int i = 0; i < n; ++i)
		ans += f[i][0];

	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		--x; --y;
		double f2[MAXC] = {0};
		for (int i = 0; i <= ori[x]; ++i)
			for (int j = 0; j <= k && j <= i; ++j)
				f2[i - j] += f[x][i] * c[i][j] * c[a[x] - i][k - j] / c[a[x]][k];
		ans += f2[0] - f[x][0];
		memcpy(f[x], f2, sizeof(f[x]));
		a[x] -= k;
		a[y] += k;
		printf("%.12f\n", ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("248E.in", "r", stdin);
	freopen("248E.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}