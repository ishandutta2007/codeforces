#include<cstdio>
#include<algorithm>
using namespace std;
int ch[6200005][2],dp[6200005],tot=0,le;
int n,x,u;
void dfs(int p,int dep)
{
	if(dep==-1)return;
	if(ch[p][0])dfs(ch[p][0],dep-1);
	if(ch[p][1])dfs(ch[p][1],dep-1);
	dp[p]=max(dp[ch[p][0]],dp[ch[p][1]]);
	if(ch[p][0])dp[p]=max(dp[p],1+dp[ch[p][1]]);
	if(ch[p][1])dp[p]=max(dp[p],1+dp[ch[p][0]]);
}
int main()
{
	scanf("%d",&n);
	tot=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		u=1;
		for(int j=29;j>=0;j--)
		{
			le=((x&(1<<j))>0);
			if(!ch[u][le])ch[u][le]=++tot;
			u=ch[u][le];
		}
		dp[u]=1;
	}
	dfs(1,29);
	printf("%d\n",n-dp[1]);
	return 0;
}