#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans=0,n,m,dp[5005][5005];
char s[2][5005];
int main()
{
	scanf("%d%d%s%s",&n,&m,s[0]+1,s[1]+1);
	for(int i=n;i;i--)
	{
		for(int j=m;j;j--)
		{
			if(i<n)dp[i][j]=max(dp[i][j],dp[i+1][j]-1);
			if(j<m)dp[i][j]=max(dp[i][j],dp[i][j+1]-1);
			if(s[0][i]!=s[1][j])continue;
			dp[i][j]=max(dp[i][j],2+dp[i+1][j+1]);
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}