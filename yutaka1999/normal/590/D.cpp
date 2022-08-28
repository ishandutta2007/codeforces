#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 155
#define MX 11330

using namespace std;

int dp[2][SIZE][MX];
int dp2[2][SIZE][MX];
int A[SIZE];

int main()
{
	int n,k,s;
	scanf("%d %d %d",&n,&k,&s);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int pos=0;
	memset(dp,-1,sizeof(dp));
	dp[pos][0][0]=0;
	for(int i=k-1;i>=0;i--)
	{
		int a=A[i];
		pos^=1;
		memset(dp[pos],-1,sizeof(dp[pos]));
		for(int j=0;j<k-i;j++)
		{
			for(int p=0;p<=min(s,MX-1);p++)
			{
				if(dp[pos^1][j][p]==-1) continue;
				//
				if(dp[pos][j][p]==-1) dp[pos][j][p]=dp[pos^1][j][p]+a;
				else dp[pos][j][p]=min(dp[pos][j][p],dp[pos^1][j][p]+a);
				//
				if(dp[pos][j+1][p+(k-i-j-1)]==-1) dp[pos][j+1][p+(k-i-j-1)]=dp[pos^1][j][p];
				else dp[pos][j+1][p+(k-i-j-1)]=min(dp[pos][j+1][p+(k-i-j-1)],dp[pos^1][j][p]);
			}
		}
	}
	for(int i=k;i<n;i++)
	{
		int a=A[i];
		pos^=1;
		memset(dp[pos],-1,sizeof(dp[pos]));
		for(int j=0;j<=k;j++)
		{
			for(int p=0;p<=min(s,MX-1);p++)
			{
				if(dp[pos^1][j][p]==-1) continue;
				//
				if(dp[pos][j][p]==-1) dp[pos][j][p]=dp[pos^1][j][p];
				else dp[pos][j][p]=min(dp[pos][j][p],dp[pos^1][j][p]);
				//
				if(j>0)
				{
					if(dp[pos][j-1][p+(i+j-k)]==-1) dp[pos][j-1][p+(i+j-k)]=dp[pos^1][j][p]+a;
					else dp[pos][j-1][p+(i+j-k)]=min(dp[pos][j-1][p+(i+j-k)],dp[pos^1][j][p]+a);
				}
			}
		}
	}
	int ret=0;
	for(int i=0;i<k;i++) ret+=A[i];
	for(int p=0;p<=min(s,MX-1);p++)
	{
		if(dp[pos][0][p]==-1) continue;
		ret=min(ret,dp[pos][0][p]);
	}
	printf("%d\n",ret);
	return 0;
}