#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8769.in", "r", stdin);
	freopen("8769.out", "w", stdout);
#endif

	int n, m;
	long long ans = 0;
	scanf("%d%d", &n, &m);
	++n;

	for (int i = m + 1; i * 2 <= n; ++i)
		for (int j = m + 1, cc = (2 * i - j) * (n - i); j < n - m; ++j, cc -= n - i)
		{
			int t = (cc - 1) / (i + j);
			if (t <= m) break;
			if (t >= n - m) t = n - m - 1;
			ans += t - m;
			if (i * 2 < n) ans += t - m;
		}

	ans *= 3;
	printf("%"LLFORMAT"d\n", ans);

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}