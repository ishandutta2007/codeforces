# include <cstdio>
# include <set>
using namespace std;
const int MN = 511;
int dp[MN][MN];
int a[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		dp[i][i] = 0;
	for (int len = 1; len <= n; ++len)
	{
		for (int pos = 0; pos + len <= n; ++pos)
		{
			dp[pos][pos + len] = MN;
			if (a[pos] == a[pos + len - 1])
				dp[pos][pos + len] = min(max(1, dp[pos + 1][pos + len - 1]), dp[pos][pos + len]);
			for (int spl = pos + 1; spl < pos + len; ++spl)
				dp[pos][pos + len] = min(dp[pos][pos + len], dp[pos][spl] + dp[spl][pos + len]);
		}
	}
	printf("%d\n", dp[0][n]);
}