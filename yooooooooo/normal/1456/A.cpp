#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ans,T,n,p,k,dp[100005],x,y;
char s[100005];
const int inf=2e9+7;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",s+1);
		for(int i=n;i>=p;i--)
		{
			dp[i]=(s[i]=='0');
			if(i+k<=n)dp[i]+=dp[i+k];
		}
		scanf("%d%d",&x,&y);
		ans=inf;
		for(int i=p;i<=n;i++)ans=min(ans,x*dp[i]+y*(i-p));
		printf("%d\n",ans);
	}
	return 0;
}