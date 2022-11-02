#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MOD = 1000000007;

int n1, n2;

void init()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		if (x == 1) ++n1;
		else ++n2;
	}
}

void solve()
{
	int x = 0, y = 1, z;
	for (int i = 1; i <= n1; ++i)
	{
		z = (y + (long long)x * (i - 1)) % MOD;
		x = y;
		y = z;
	}

	int ans = y;
	for (int i = n1 + 1; i <= n1 + n2; ++i)
		ans = (long long)ans * i % MOD;

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9231.in", "r", stdin);
	freopen("9231.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}