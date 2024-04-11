# include <cstdio>
const int MN = 24;
const int MOD = 1e9 + 7;
long long sum[1 << MN];
bool bad[1 << MN];
int arr[MN];
int dp[1 << MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	for (int i = 1; i < (1 << n); ++i)
	{
		int rem;
		for (rem = 0; ((1 << rem) & i) == 0; ++rem)
			;
		sum[i] = sum[i &~ (1 << rem)] + arr[rem];
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		int x;
		scanf("%d", &x);
		for (int j = 0; j < (1 << n); ++j)
			if (sum[j] == x)
			{
				bad[j] = true;
			}
	}
	dp[0] = 1;
	for (int i = 1; i < (1 << n); ++i)
		if (!bad[i] )
			for (int k = 0; k < n; ++k)
				if (i & (1 << k))
					dp[i] = (dp[i] + dp[i & ~(1 << k)]) % MOD;
	printf("%d\n", dp[(1 << n) - 1]);
}