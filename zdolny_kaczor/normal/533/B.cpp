# include <cstdio>
# include <vector>
template <typename T>
T abs(T x)
{
	if (x > 0)
		return x;
	else
		return -x;
}
using namespace std;
const int MN = 2e5 + 44;
vector <int> under[MN];
int val[MN];
long long dp[MN][2];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int up;
		scanf("%d%d", &up, val + i);
		under[up].push_back(i);
	}
	for (int i = n; i > 0; --i)
	{
		long long evensum = 0;
		long long positivedsum = 0;
		long long minabs = 1e7 + 44;
		bool positiveeven = true;
		for (auto x : under[i])
		{
			evensum += dp[x][0];
			if (dp[x][1] > dp[x][0])
			{
				positivedsum += dp[x][1] - dp[x][0];
				positiveeven = !positiveeven;
			}
			minabs = min(minabs, abs(dp[x][1] - dp[x][0]));
		}
		if (positiveeven)
		{
			dp[i][0] = evensum + positivedsum;
			dp[i][1] = evensum + positivedsum - minabs;
		}
		else
		{
			dp[i][0] = evensum + positivedsum - minabs;
			dp[i][1] = evensum + positivedsum;
		}
		dp[i][1] = max(dp[i][1], dp[i][0] + val[i]);
	}
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int k = 0; k < 2; ++k)
			ans = max(ans, dp[i][k]);
	printf("%I64d\n", ans);
}