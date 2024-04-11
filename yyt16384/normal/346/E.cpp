#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

int ia, in, ip, ih;

void init()
{
	scanf("%d%d%d%d", &ia, &in, &ip, &ih);
}

int f(int a, int n, int p)
{
	if ((long long)a * (n - 1) < p)
		return std::max(a, p - a * (n - 1));
	int k = (long long)a * n % p;
	int num = (long long)a * n / p + (k >= p / a * a);
	return f((a - p % a) % a, num, a);
}

void solve()
{
	++in;
	ia %= ip;
	int u;
	if ((long long)ia * (in - 1) < ip) u = ia;
	else u = f(ia, in, ip);
	if (u <= ih) printf("YES\n");
	else printf("NO\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9222.in", "r", stdin);
	freopen("9222.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		solve();
	}

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}