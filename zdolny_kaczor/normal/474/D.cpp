# include <cstdio>
const int MN = 1e5 + 44, MOD = 1e9 + 7;
long long dp[MN];
int main()
{
	int t, k;
	scanf("%d%d", &t, &k);
	for (int i = 0; i < k; ++i)
		dp[i] = 1;
	for (int i = k; i < MN; ++i)
		dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
	for (int i = 1; i < MN; ++i)
		dp[i] += dp[i - 1];
	while (t--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		long long res = dp[b] - dp[a - 1];
		res %= MOD;
		if (res < 0)
			res += MOD;
		printf("%d\n", (int) res);
	}
}