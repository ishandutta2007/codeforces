#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define SQ 320
#define MOD 1000000007

using namespace std;
typedef long long int ll;

vector <ll> dp[SIZE];
ll DP[SQ][SQ];

int main()
{
	int n,m,x;
	scanf("%d %d %d",&n,&m,&x);
	ll ret=0;
	if(m<=SQ)
	{
		for(int i=0;i<=n;i++) dp[i].resize(m+1);
		dp[0][0]=1;
		for(int i=1;i<=m;i++)
		{
			for(int j=n;j>=0;j--)
			{
				ll sum=0;
				for(int k=0;k<=m;k++)
				{
					if(i==x) dp[j][k]=0;
					if(k>=i)
					{
						dp[j][k]+=sum;
						dp[j][k]%=MOD;
					}
					if(j!=0)
					{
						sum+=dp[j-1][k];
						sum%=MOD;
					}
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			ret+=dp[n][i];
			ret%=MOD;
		}
	}
	else//n<SQ
	{
		x--;
		memset(DP,0,sizeof(DP));
		DP[0][0]=1;
		for(int i=0;i<m;i++)
		{
			for(int j=n;j>=0;j--)
			{
				for(int k=0;k<=n;k++)
				{
					if(i==x) DP[j][k]=0;
					if(j>0)
					{
						DP[j][k]+=DP[j-1][k];
						DP[j][k]%=MOD;
					}
				}
			}
			for(int j=n;j>0;j--)
			{
				for(int k=j;k>0;k--)
				{
					DP[j][k]+=DP[j][k-1];
					DP[j][k]%=MOD;
				}
			}
		}
		ret=DP[n][n];
	}
	for(int i=1;i<=n;i++)
	{
		ret*=(ll) i;
		ret%=MOD;
	}
	printf("%I64d\n",ret);
	return 0;
}