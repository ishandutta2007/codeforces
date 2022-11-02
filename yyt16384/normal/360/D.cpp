#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

int gcd(int x, int y)
{
	int z;
	while (y)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return x;
}

int powermod(int x, int y, int p)
{
	int s = 1;
	while (y)
	{
		if (y & 1)
			s = (long long)s * x % p;
		x = (long long)x * x % p;
		y >>= 1;
	}
	return s;
}

const int MAXN = 10005;
const int MAXM = 100005;
const int MAXD = 1505;

int n, m, p;
int a[MAXN];
int b[MAXM];
int bs;
int d[MAXD];
int dn;
int c[MAXN];
int phi[MAXD];

void init()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]);
}

void solve()
{
	bs = p - 1;
	for (int i = 0; i < m; ++i)
		bs = gcd(bs, b[i]);

	dn = 0;
	for (int i = 1; i * i <= p; ++i)
		if ((p - 1) % i == 0)
			d[dn++] = i;
	for (int i = dn - 1; i >= 0; --i)
		if (d[i] * d[i] < p - 1)
			d[dn++] = (p - 1) / d[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < dn; ++j)
			if (powermod(a[i], d[j], p) == 1)
			{
				c[i] = (p - 1) / d[j];
				break;
			}
		c[i] = gcd((long long)c[i] * bs % (p - 1), p - 1);
	}

	phi[0] = 1;
	for (int i = 1; i < dn; ++i)
	{
		for (int j = 1; j <= i; ++j)
			if (d[i] % d[j] == 0)
			{
				int rem = std::lower_bound(d, d + dn, d[i] / d[j]) - d;
				if (d[i] / d[j] % d[j] == 0)
					phi[i] = phi[rem] * d[j];
				else
					phi[i] = phi[rem] * (d[j] - 1);
				break;
			}
	}

	int ans = 0;
	for (int i = 0; i < dn; ++i)
	{
		bool flag = false;
		for (int j = 0; j < n; ++j)
			if ((p - 1) / d[i] % c[j] == 0)
			{
				flag = true;
				break;
			}
		if (flag)
			ans += phi[i];
	}

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("360D.in", "r", stdin);
	freopen("360D.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}