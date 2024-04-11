#include <algorithm>
#include <cmath>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 105;
const int MAXM = 5005;
const long double EPS = 1e-10;

int n, m;
int x[MAXM];
int y[MAXM];
int w[MAXM];
long double f[MAXN][MAXN];
long double d[MAXM];

void addedge(int u, int v)
{
	if (u == 0 || u == n - 1)
		return;
	++f[u][u];
	--f[u][v];
}

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		--x[i]; --y[i];
		addedge(x[i], y[i]);
		addedge(y[i], x[i]);
	}
	f[0][0] = 1;
	f[n - 1][n - 1] = 1;
	f[n - 1][n] = 1;
}

void solve()
{
	long double tmp;
	for (int i = 0; i < n; ++i)
	{
		int r = i;
		for (int j = i + 1; j < n; ++j)
			if (fabs(f[j][i]) > fabs(f[r][i]))
				r = j;
		if (fabs(f[r][i]) < EPS)
			continue;
		for (int j = i; j <= n; ++j)
			std::swap(f[i][j], f[r][j]);
		tmp = f[i][i];
		for (int j = i; j <= n; ++j)
			f[i][j] /= tmp;
		for (int j = 0; j < n; ++j)
			if (j != i && fabs(f[j][i]) > EPS)
			{
				tmp = f[j][i];
				for (int k = i; k <= n; ++k)
					f[j][k] -= tmp * f[i][k];
			}
	}

	for (int i = 0; i < m; ++i)
		d[i] = f[y[i]][n] - f[x[i]][n];

	long double min = 1e100;
	for (int i = 0; i < m; ++i)
		min = std::min(min, w[i] / fabsl(d[i]));

	long double sum = 0;
	for (int i = 0; i < m; ++i)
	{
		if (x[i] == 0)
			sum += d[i] * min;
		else if (y[i] == 0)
			sum -= d[i] * min;
	}
	printf("%f\n", (double)sum);
	if (fabs(sum) < EPS)
	{
		for (int i = 0; i < m; ++i)
			printf("0\n");
		return;
	}
	for (int i = 0; i < m; ++i)
		printf("%f\n", (double)(d[i] * min));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("267C.in", "r", stdin);
	freopen("267C.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}