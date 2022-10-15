#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
char s[100010];
int dp[100010][4];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		dp[1][1]=1,dp[1][0]=0,dp[1][2]=dp[1][3]=0x3f3f3f3f;
		for(int i=2;i<=n;++i)
		{
			if(s[i]==s[i-1]&&s[i]==s[i-2])
			{
				dp[i][0]=0x3f3f3f3f;
				dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
				dp[i][2]=dp[i-1][3];
				dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
			}
			else if(s[i]==s[i-1])
			{
				dp[i][0]=0x3f3f3f3f;
				dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
				dp[i][2]=min(dp[i-1][3],dp[i-1][1]);
				dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
			}
			else if(s[i]==s[i-2])
			{
				dp[i][0]=min(dp[i-1][2],dp[i-1][3]);
				dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
				dp[i][2]=dp[i-1][3];
				dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
			}
			else
			{
				dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),min(dp[i-1][2],dp[i-1][3]));
				dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
				dp[i][2]=min(dp[i-1][1],dp[i-1][3]);
				dp[i][3]=min(dp[i-1][1],dp[i-1][3])+1;
			}
		}
		printf("%d\n",min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3])));
	}
	return 0;
}