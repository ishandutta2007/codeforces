#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int n,a[105];
int res1,res2;
int ans=0;
int dp[105][105][105][2];
int last,pos;
int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	res2=n/2,res1=n-res2;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][res1][res2][0]=dp[0][res1][res2][1]=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]!=0)
		{
			for(int j=0; j<=res1; ++j)
			{
				for(int k=0; k<=res2; ++k)
				{
					for(int t=0; t<=1; ++t)
					{
						dp[i][j][k][a[i]%2]=min(dp[i][j][k][a[i]%2],dp[i-1][j+a[i]%2][k+(a[i]+1)%2][t]+(a[i]%2==t?0:1));
					}
				}
			}
		}
		else
		{
			for(a[i]=0; a[i]<=1; ++a[i])
			{
				for(int j=0; j<=res1; ++j)
				{
					for(int k=0; k<=res2; ++k)
					{
						for(int t=0; t<=1; ++t)
						{
							dp[i][j][k][a[i]%2]=min(dp[i][j][k][a[i]%2],dp[i-1][j+a[i]%2][k+(a[i]+1)%2][t]+(a[i]%2==t?0:1));
						}
					}
				}
			}
		}
	}
	printf("%d\n",min(dp[n][0][0][0],dp[n][0][0][1]));
	return 0;
}