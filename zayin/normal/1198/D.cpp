#include<bits/stdc++.h>
#define maxn 55
using namespace std;

int n;
char mp[maxn][maxn];

int sum[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int cnt(int x1,int y1,int x2,int y2)	{
	return sum[x2][y2]+sum[x1-1][y1-1]-sum[x2][y1-1]-sum[x1-1][y2];
}

int calc(int x1,int y1,int x2,int y2)	{
	if (~dp[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
	int &ans=dp[x1][y1][x2][y2];
	ans=min(cnt(x1,y1,x2,y2),max(x2-x1+1,y2-y1+1));
	for (int i=x1;i<x2;++i)
		ans=min(ans,calc(x1,y1,i,y2)+calc(i+1,y1,x2,y2));
	for (int j=y1;j<y2;++j)
		ans=min(ans,calc(x1,y1,x2,j)+calc(x1,j+1,x2,y2));
	return ans;
}

int main()	{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (int i=1;i<=n;++i)	{
		scanf("%s",mp[i]+1); 
		for (int j=1;j<=n;++j)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(mp[i][j]=='#');
	}
	printf("%d\n",calc(1,1,n,n));
	return 0;
}