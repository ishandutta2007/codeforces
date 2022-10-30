#include <climits>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 35;

int n;
int a[MAXN][MAXN];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
}

void solve()
{
	int m = (n + 1) >> 1;
	int ans = INT_MIN;

	for (int i = 0; i < (1 << m); ++i)
	{
		int c[MAXN];
		int sum = 0;

		for (int j = 0; j < m; ++j)
			c[j] = (i >> j) & 1;
		for (int j = m; j < n; ++j)
			c[j] = c[j - m] ^ c[m - 1];

		for (int j = 0; j < n; ++j)
			if (c[j]) c[j] = -1;
			else c[j] = 1;

		for (int j = 0; j < n; ++j)
			sum += c[j] * a[m - 1][j];

		for (int j = 0; j < m - 1; ++j)
		{
			int now = 0;
			for (int k = -1; k <= 1; k += 2)
			{
				int ss = a[j][m - 1] * k + a[j + m][m - 1] * (k * c[m - 1]);
				for (int p = 0; p < m - 1; ++p)
				{
					int tmp = a[j][p] + a[j][p + m] * k + a[j + m][p] * c[p] + a[j + m][p + m] * (k * c[p + m]);
					if (tmp < 0) tmp = -tmp;
					ss += tmp;
				}
				if (ss > now) now = ss;
			}
			sum += now;
		}

		if (sum > ans) ans = sum;
	}

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8787.in", "r", stdin);
	freopen("8787.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}