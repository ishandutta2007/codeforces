# include <cstdio>
# include <set>
using namespace std;
const int MN = 42;
long long dp[MN][3][3];
long long val[3][3];
int main()
{
	for (int i=0; i<3; ++i)
		for (int k=0; k<3; ++k)
			scanf("%I64d", &val[i][k]);
	int n;
	scanf("%d", &n);
	for (int l=1; l<=n; ++l)
	{
		for (int i=0; i<3; ++i)
			for (int k=0; k<3; ++k)
			{
				if (i==k)
					continue;
				int oth = 0^1^2^i^k;
				dp[l][i][k]=min(dp[l-1][i][oth]+val[i][k]+dp[l-1][oth][k],
												dp[l-1][i][k]+val[i][oth]+dp[l-1][k][i]+val[oth][k]+dp[l-1][i][k]);
			}
	}
	printf("%I64d\n", dp[n][0][2]);
}