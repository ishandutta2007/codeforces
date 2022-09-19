# include <cstdio>
# include <vector>
using namespace std;
const int MN = 314;
const int INF = 1e9+53;
vector <int> factor[MN];
int cost[MN];
int nin[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int x;
		scanf("%d", &x);
		for (int p=2; p*p<=x; ++p)
			if (x%p==0)
			{
				factor[i].push_back(p);
				while (x%p==0)
					x/=p;
			}
		if (x!=1)
			factor[i].push_back(x);
	}
	for (int i=0; i<n; ++i)
		scanf("%d", cost+i);
// 	for (int i=0; i<n; ++i)
// 	{
// 		printf("%d.", i);
// 		for (int x:factor[i])
// 			printf("%d ", x);
// 		printf("\n");
// 	}
	int res = INF;
// 	printf("st = %d\n", res);
	for (int tr = 0; tr<n; ++tr)
	{
		int dp[1<<9];
		int amo = factor[tr].size();
		for (int i=0; i<(1<<amo); ++i)
			dp[i]=INF;
// 		printf("amo = %d\n", amo);
		for (int i=0; i<n; ++i)
		{
			nin[i]=0;
			for (int k=0; k<amo; ++k)
			{
				bool found = false;
				for (int l:factor[i])
					if (l==factor[tr][k])
						found = true;
				if (! found)
					nin[i]|=(1<<k);
			}
// 			printf("nin[%d]=%d\n", i, nin[i]);
		}
		dp[0]=0;
		for (int i=0; i<n; ++i)
			for (int mask=0; mask<(1<<amo); ++mask)
			{
// 				printf("dp[%d] inc dp[%d]+%d (%d)\n", mask|nin[i], mask, cost[i], i);
				dp[mask|nin[i]]=min(dp[mask|nin[i]], dp[mask]+cost[i]);
			}
		res = min(res, dp[(1<<amo)-1]+cost[tr]);
	}
	if (res == INF)
		printf("-1\n");
	else
		printf("%d\n", res);
}