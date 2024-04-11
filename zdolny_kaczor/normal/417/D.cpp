# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e2 + 1;
const int MM = 20;
const long long llinf = 1ll << 62;
long long dp[2][1 << MM];
pair <int, pair <int, int> > Friend[MN];
# define monitor first
# define cost second.first
# define solvable_bitmask second.second
int main()
{
	int n, m, b;
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 0; i < n; ++i)
	{
		int problems_cou;
		scanf("%d%d%d", &Friend[i].cost, &Friend[i].monitor, &problems_cou);
		for (int k = 0; k < problems_cou; ++k)
		{
			int x;
			scanf("%d", &x);
			x--;
			Friend[i].solvable_bitmask |= (1 << x);
		}
	}
	sort(Friend, Friend + n);
	reverse(Friend, Friend + n);
	for (int i = 0; i <= n; ++i)
		for (int mask = 0; mask < (1 << m); ++mask)
			dp[i % 2][mask] = llinf;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
// 		printf("include cost = %d mon = %d mask = %d\n", Friend[i].cost, Friend[i].monitor, Friend[i].solvable_bitmask);
		for (int mask = 0; mask < (1 << m); ++mask)
			dp[(i + 1)%2][mask] = dp[i % 2][mask];
		for (int mask = 0; mask < (1 << m); ++mask)
			dp[(i + 1) % 2][mask | Friend[i].solvable_bitmask] = min(dp[(i + 1) % 2][mask | Friend[i].solvable_bitmask], dp[i % 2][mask] + Friend[i].cost + (mask == 0 ? Friend[i].monitor * (long long) b : 0));
// 		for (int mask = 0; mask < (1 << m); ++mask)
// 			printf("%d costs %I64d\n", mask, dp[i + 1][mask]);
	}
	if (dp[n % 2][(1 << m) - 1] == llinf)
		printf("-1\n");
	else
		printf("%I64d\n", dp[n % 2][(1 << m) - 1]);
}