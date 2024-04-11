#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
char s[3005],t[3005];
int n,m,dp[3005][3005],ans=0;
const int mod=998244353;
int M(int x){return x>=mod?x-mod:x;}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	for(int i=0;i<=n+1;i++)dp[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(s[i]==t[j+i-1]||j+i-1>m)
			{
				dp[i][j]=M(dp[i][j]+dp[i-1][j]);
			}
			if(s[i]==t[j]||j>m)
			{
				//printf("%d %d\n",i,j);
				dp[i][j]=M(dp[i][j]+dp[i-1][j+1]);
			}
			//printf("#%d %d %d\n",i,j,dp[i][j]);
		}
	}
	for(int i=m;i<=n;i++)ans=M(ans+dp[i][1]);
	printf("%d\n",ans);
	return 0;
}