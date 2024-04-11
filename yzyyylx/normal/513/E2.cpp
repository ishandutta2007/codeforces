#include<iostream>
#include<cstdio>
#include<cstring>
#define N 30010
#define M 210
using namespace std;

int n,m,dp[N][M][4],num[N];
//0 :gu
//1 :gu->feng
//2 :feng
//3 :feng->gu
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	memset(dp,-0x3f,sizeof(dp));
	for(j=0;j<=n;j++) for(i=0;i<4;i++) dp[j][0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			int tmp=1+(j!=1&&j!=m);
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-1][3])-tmp*num[i];
			dp[i][j][1]=max(dp[i-1][j][1],dp[i][j][0]);
			dp[i][j][2]=max(dp[i-1][j][2],dp[i-1][j-1][1])+tmp*num[i];
			dp[i][j][3]=max(dp[i-1][j][3],dp[i][j][2]);
			if(tmp==2)
			{
				dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][1]);
				dp[i][j][3]=max(dp[i][j][3],dp[i-1][j-1][3]);
			}
		}
	}
	cout<<max(dp[n][m][1],dp[n][m][3]);
}