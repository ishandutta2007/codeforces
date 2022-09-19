# include <cstdio>
# include <set>
using namespace std;
const int MN = 22;
int cost[MN][MN];
char str[MN][MN];
int dp[1 << MN];
int rem[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", str[i]);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			scanf("%d", &cost[i][k]);
// 	printf("read.\n");
	for (int i = 1; i < (1 << n); ++i)
		dp[i] = 1 << 28;
// 	printf("dupae\n");
	for (int i = 0; i < m; ++i)
	{
		for (char a = 'a'; a <= 'z'; ++a)
		{
			int maxi = -(1 << 28), sum = 0;
			int mask = 0;
			for (int k = 0; k < n; ++k)
				if (str[k][i] == a)
				{
					maxi = max(maxi, cost[k][i]);
					sum += cost[k][i];
					mask |= 1 << k;
				}
			if (mask)
			{
				sum -= maxi;
// 				printf("mask = %d sum = %d\n", mask, sum);
				for (int medit = 0; medit < (1 << n); ++medit)
					dp[medit] = min(dp[medit], sum + dp[medit & ~mask]);
			}
		}
	}
// 	printf("dupax\n");
	for (int i = 0; i < n; ++i)
	{
		rem[i] = 1 << 28;
		for (int k = 0; k < m; ++k)
			rem [i] = min(rem[i], cost[i][k]);
// 		printf("rem = %d\n", rem[i]);
	}
	int res = 1 << 28;
// 	printf("dupaa\n");
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		int val = dp[mask];
// 		printf("val = %d\n", val);
		for (int i = 0; i < n; ++i)
			if ((mask & (1 << i)) == 0)
				val += rem[i];
		res = min(res, val);
	}
	printf("%d\n", res);
}