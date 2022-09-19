# include <cstdio>
# include <set>
using namespace std;
const int MN = 151;
const int inf = 4e8 + 44;
int dp[MN][MN * (MN + 1) / 2]; //[k][sum] minimal sum of values of [k] soldiers on positions summing up to exactly [sum]
int main()
{
	int n, k, s;
	scanf("%d%d%d", &n, &k, &s);
	for (int i = 0; i < MN; ++i)
		for (int k = 0; k < MN * (MN + 1) / 2; ++k)
			dp[i][k] = inf;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		for (int sum = i * (i - 1) / 2; sum >= 0; --sum)
			for (int cou = min(i, k - 1); cou >= 0; --cou)
				dp[cou + 1][sum + i] = min(dp[cou][sum] + x, dp[cou + 1][sum + i]);
	}
	int res = inf;
	for (int i = 0; i - k * (k - 1) / 2 <= s && i <= n * (n - 1) / 2; ++i)
		res = min(res, dp[k][i]);
	printf("%d\n", res);
}