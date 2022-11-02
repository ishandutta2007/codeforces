#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

int powermod(int x, int y, int m)
{
	int s = 1;
	while (y)
	{
		if (y & 1)
			s = (long long)s * x % m;
		x = (long long)x * x % m;
		y >>= 1;
	}
	return s;
}

const int MAXN = 1005;
const int MOD = 1000000007;

int n, m;
int f[MAXN][MAXN][4];
int fac[MAXN];
int facr[MAXN];
int g[MAXN];

void init()
{
	scanf("%d%d", &n, &m);
}

void solve()
{
	f[0][0][2] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < 4; ++k)
				if (int tmp = f[i][j][k])
				{
					{
						int nextk = ((k << 1) | 1) & 3;
						(f[i + 1][j + 1][nextk] += tmp) %= MOD;
					}

					if ((k & 2) == 0)
					{
						int nextk = (k << 1) & 3;
						(f[i + 1][j + 1][nextk] += tmp) %= MOD;
					}

					{
						int nextk = (k << 1) & 3;
						(f[i + 1][j][nextk] += tmp) %= MOD;
					}
				}

	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	facr[n] = powermod(fac[n], MOD - 2, MOD);
	for (int i = n; i >= 1; --i)
		facr[i - 1] = (long long)facr[i] * i % MOD;

	for (int i = 0; i <= n; ++i)
		g[i] = (long long)(f[n][i][0] + f[n][i][2]) * fac[n - i] % MOD;

	for (int i = n - 1; i >= 0; --i)
		for (int j = i + 1; j <= n; ++j)
			g[i] = ((g[i] - (long long)g[j] * fac[j] % MOD * facr[i] % MOD * facr[j - i]) % MOD + MOD) % MOD;

	printf("%d\n", g[m]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9173.in", "r", stdin);
	freopen("9173.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}