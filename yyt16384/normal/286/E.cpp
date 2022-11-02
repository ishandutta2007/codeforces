#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 2100005;
const int MOD = 1004535809;
const int G = 3;

int powermod(int x, int y, int m)
{
	int s = 1;
	while (y)
	{
		if (y & 1) s = (long long)s * x % m;
		x = (long long)x * x % m;
		y >>= 1;
	}
	return s;
}

int n;
int a[MAXN];
bool c[MAXN];
int ans[MAXN];
int ansn;

void init()
{
	int N;
	scanf("%d%d", &N, &n);
	++n;
	for (int i = 0; i < N; ++i)
	{
		int x;
		scanf("%d", &x);
		a[x] = 1;
		c[x] = true;
	}
}

void FFT(int *x, int m, int g)
{
	if (m == 1)
		return;

	static int tmp[MAXN];

	for (int i = 0; i < m / 2; ++i)
		tmp[i] = x[2 * i];
	for (int i = m / 2; i < m; ++i)
		tmp[i] = x[2 * i - m + 1];
	memcpy(x, tmp, m * sizeof(int));

	FFT(x, m / 2, (long long)g * g % MOD);
	FFT(x + m / 2, m / 2, (long long)g * g % MOD);

	for (int i = 0, ss = 1; i < m / 2; ++i, ss = (long long)ss * g % MOD)
	{
		int u = x[i];
		int v = (long long)x[i + m / 2] * ss % MOD;
		tmp[i] = (u + v) % MOD;
		tmp[i + m / 2] = (u - v + MOD) % MOD;
	}
	memcpy(x, tmp, m * sizeof(int));
}

void solve()
{
	int n2 = 1;
	while (n2 < n)
		n2 <<= 1;
	n2 <<= 1;

	int rt = powermod(G, (MOD - 1) / n2, MOD);
	FFT(a, n2, rt);
	for (int i = 0; i < n2; ++i)
		a[i] = (long long)a[i] * a[i] % MOD;
	rt = powermod(rt, MOD - 2, MOD);
	FFT(a, n2, rt);

	for (int i = 0; i < n; ++i)
		if (a[i] && !c[i])
		{
			printf("NO\n");
			return;
		}

	for (int i = 0; i < n; ++i)
		if (!a[i] && c[i])
			ans[ansn++] = i;

	printf("YES\n");
	printf("%d\n", ansn);
	for (int i = 0; i < ansn; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9220.in", "r", stdin);
	freopen("9220.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}