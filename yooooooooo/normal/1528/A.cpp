#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,ans=0,l[200005][2],dp[200005][2];
vector<int>s[200005];
void dfs(int p,int f)
{
	//printf("#%d\n",p);
	dp[p][0]=dp[p][1]=0;
	for(int i=0;i<s[p].size();i++)
	{
		int v=s[p][i];
		if(v==f)continue;
		dfs(v,p);
		dp[p][0]=dp[p][0]+max(dp[v][0]+abs(l[p][0]-l[v][0]),dp[v][1]+abs(l[p][0]-l[v][1]));
		dp[p][1]=dp[p][1]+max(dp[v][0]+abs(l[p][1]-l[v][0]),dp[v][1]+abs(l[p][1]-l[v][1]));
		
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)s[i].clear();
		for(int i=1;i<=n;i++)scanf("%lld%lld",&l[i][0],&l[i][1]);
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			s[x].push_back(y);
			s[y].push_back(x);
		}
		//ans=0;
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}