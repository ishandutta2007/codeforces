#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1000005;
const int MOD = 1000000007;

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

int n, m, k;
bool nosol;
int minx, maxx, s2;
int ans;
int pw2[MAXN];

void init()
{
	scanf("%d%d%d", &n, &m, &k);
	++k;
	minx = n;
	maxx = 0;
	ans = 1;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		if (y - x != 1 && y - x != k)
		{
			nosol = true;
			return;
		}
		else if (y - x == k)
		{
			if (x > maxx)
				maxx = x;
			if (x < minx)
				minx = x;
			++s2;
		}
	}
	if (minx + k <= maxx)
		nosol = true;
}

void solve()
{
	if (nosol)
	{
		printf("0\n");
		return;
	}

	if (k == 0 || k >= n - 1)
	{
		printf("1\n");
		return;
	}

	n -= k;

	pw2[0] = 1;
	for (int i = 1; i <= n; ++i)
		pw2[i] = (long long)pw2[i - 1] * 2 % MOD;

	if (minx > maxx)
		ans = 1;
	else
		ans = 0;

	for (int i = 0; i < n; ++i)
	{
		int left = i;
		int right = i + k;
		if (s2 && left > minx)
			break;
		if (s2 && right <= maxx)
			continue;
		if (right > n)
			right = n;
		int cnt = right - left - s2;
		if (s2 && left == minx)
			++cnt;
		ans = (ans + pw2[cnt - 1]) % MOD;
	}

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9214.in", "r", stdin);
	freopen("9214.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}