#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005
#define MOD 1000000007

using namespace std;

int dp[SIZE][SIZE];
int dp2[SIZE][SIZE];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	memset(dp,-1,sizeof(dp));
	for(int i=n-1;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			if(str[i]!=str[j]) dp[i][j]=0;
			else if(j==n-1) dp[i][j]=1;
			else dp[i][j]=dp[i+1][j+1]+1;
		}
	}
	memset(dp2,0,sizeof(dp2));
	dp2[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(dp2[i][j]==0) continue;
			if(j>0)
			{
				dp2[i+1][j+1]+=dp2[i][j];
				if(dp2[i+1][j+1]>=MOD) dp2[i+1][j+1]-=MOD;
			}
			if(str[i]!='0')
			{
				int st=j+1;
				if(j>0&&dp[i-j][i]<j)
				{
					int L=dp[i-j][i];
					int l=i-j+L,r=i+L;
					if(r<n&&str[l]<str[r]) st=j;
				}
				if(i+st<=n)
				{
					dp2[i+st][st]+=dp2[i][j];
					if(dp2[i+st][st]>=MOD) dp2[i+st][st]-=MOD;
				}
				//if(i+st==n) printf("%d %d : %d %d\n",i,j,dp2[i][j],st);
			}
		}
	}
	int ret=0;
	for(int i=0;i<=n;i++)
	{
		ret+=dp2[n][i];
		if(ret>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
	return 0;
}