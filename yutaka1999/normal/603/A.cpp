#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;

int dp[2][3][2];
char str[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	int pos=0;
	memset(dp[pos],0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<2;k++)
			{
				int c=str[i]-'0';
				if(j==1) c=1-c;
				dp[pos][j][k]=max(dp[pos][j][k],dp[pos^1][j][k]);
				if(k==c) dp[pos][j][1-k]=max(dp[pos][j][1-k],dp[pos^1][j][k]+1);
				if(j<2)
				{
					dp[pos][j+1][k]=max(dp[pos][j+1][k],dp[pos^1][j][k]);
					if(k==c) dp[pos][j+1][1-k]=max(dp[pos][j+1][1-k],dp[pos^1][j][k]+1);
				}
			}
		}
	}
	int mx=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<2;k++)
		{
			mx=max(mx,dp[pos][i][k]);
		}
	}
	printf("%d\n",mx);
	return 0;
}