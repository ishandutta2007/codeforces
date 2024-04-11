# include <cstdio>
# define sp dp
# include <set>
using namespace std;
const int MN=31, MR=51;
const int INF=1<<20;
int dp[MN][MN][MR];
int main()
{
	for (int i=0; i<MN; ++i)
		for (int k=0; k<MN; ++k)
			for (int l=0; l<MR; ++l)
				if (i*k==l || l==0)
					dp[i][k][l]=0;
				else if (l>i*k)
					dp[i][k][l]=INF;
				else
				{
					dp[i][k][l]=INF;
					for (int spl=0; spl<i; spl++)
						for (int val=0; val<l; ++val)
							dp[i][k][l]=min(dp[i][k][l], dp[spl][k][val]+dp[i-spl][k][l-val]+k*k);
					for (int spl=0; spl<k; spl++)
						for (int val=0; val<l; ++val)
							dp[i][k][l]=min(dp[i][k][l], dp[i][spl][val]+sp[i][k-spl][l-val]+i*i);
				}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", dp[a][b][c]);
	}
}