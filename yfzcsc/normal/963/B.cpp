#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
vector<int>G[maxn];
int n,dp[maxn],anses[maxn],tp;
void dfs(int u,int f){
	for(auto p:G[u])if(p!=f)dfs(p,u);
	if(G[u].size()==1)return (void)(dp[u]=0);
	int cnt=0;
	for(auto p:G[u])if(p!=f&&dp[p]==0)cnt++;
	dp[u]=cnt&1;
	if(dp[u])anses[++tp]=u;
	if(f==0&&dp[u]==1){printf("NO\n");exit(0);}
}
void dfs2(int u,int f){
	if(!dp[u])anses[++tp]=u;
	for(auto p:G[u])if(p!=f)dfs2(p,u);
}
int main(){
	scanf("%d",&n);
	if(n==1)return printf("YES\n1"),0;
	if(n==2)return printf("NO"),0;
	for(int i=1,u;i<=n;++i){
		scanf("%d",&u);
		if(u)G[u].push_back(i),G[i].push_back(u);
	}
	int rt=0;
	for(int i=1;i<=n;++i)if(G[i].size()>1)rt=i;
	dfs(rt,0),dfs2(rt,0);
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d\n",anses[i]);
}