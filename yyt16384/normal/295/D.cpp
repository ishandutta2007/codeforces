#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 2005;
const int MAXM = 2005;
const int MOD = 1000000007;

int n, m;
int f[MAXN][MAXM];
int g[MAXN][MAXM];

void init()
{
	scanf("%d%d", &n, &m);
}

void solve()
{
	for (int i = 0; i < m - 1; ++i)
		f[1][i] = 1;

	for (int i = 2; i <= n; ++i)
	{
		static int s1[MAXM];
		static int s2[MAXM];

		s1[0] = f[i-1][0];
		s2[0] = 0;
		for (int j = 1; j < m - 1; ++j)
		{
			s1[j] = (s1[j-1] + f[i-1][j]) % MOD;
			s2[j] = (s2[j-1] + (long long)j * f[i-1][j]) % MOD;
		}
		for (int j = 0; j < m - 1; ++j)
			f[i][j] = ((long long)(j + 1) * s1[j] - s2[j] + MOD) % MOD;

		s1[m-2] = g[i-1][m-2];
		s2[m-2] = 0;
		for (int j = m - 3; j >= 0; --j)
		{
			s1[j] = (s1[j+1] + g[i-1][j]) % MOD;
			s2[j] = (s2[j+1] + (long long)(m - 2 - j) * g[i-1][j]) % MOD;
		}
		for (int j = 0; j < m - 1; ++j)
			g[i][j] = ((long long)(m - 1 - j) * s1[j] - s2[j] + MOD) % MOD;

		static int tmp[MAXM];
		for (int j = 0; j < m - 1; ++j)
			tmp[j] = (long long)f[i-1][j] * (m - j - 1) % MOD;
		s1[m-2] = tmp[m-2];
		s2[m-2] = 0;
		for (int j = m - 3; j >= 0; --j)
		{
			s1[j] = (s1[j+1] + tmp[j]) % MOD;
			s2[j] = (s2[j+1] + (long long)(m - 2 - j) * tmp[j]) % MOD;
		}
		for (int j = 0; j < m - 1; ++j)
			g[i][j] = (g[i][j] + (long long)(m - 1 - j) * s1[j] - s2[j] - tmp[j] + 2 * MOD) % MOD;
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m - 1; ++j)
			ans = (ans + (n - i + 1) * ((long long)(m - 1 - j) * f[i][j] + g[i][j]) % MOD) % MOD;

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9174.in", "r", stdin);
	freopen("9174.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}