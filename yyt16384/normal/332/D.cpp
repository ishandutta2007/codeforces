#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 2005;

int n, k;
int g[MAXN][MAXN];
int deg[MAXN];

void init()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			scanf("%d", &g[i][j]);
			if (g[i][j] != -1)
			{
				++deg[i];
				++deg[j];
			}
		}
}

void solve()
{
	long long sum = 0;
	int cnt;

	if (k == 1)
	{
		cnt = n;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (g[i][j] != -1)
					sum += 2 * g[i][j];
	}
	else if (k == 2)
	{
		cnt = n * (n - 1) / 2;
		int center = -1;
		for (int i = 0; i < n; ++i)
			if (deg[i] == n - 1)
			{
				center = i;
				break;
			}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (g[i][j] != -1)
				{
					if (i == center || j == center)
						sum += (long long)(n - 1) * g[i][j];
					else
						sum += 2 * g[i][j];
				}
	}
	else if (k == n - 1)
	{
		cnt = n;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (g[i][j] != -1)
					sum += 2 * g[i][j];
	}

	printf("%"LLFORMAT"d\n", sum / cnt);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9212.in", "r", stdin);
	freopen("9212.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}