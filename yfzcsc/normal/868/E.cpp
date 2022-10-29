#define _GLIBCXX_IOSTREAM
#include<bits/stdc++.h>
#define maxn 60
#define inf 1000000007
using namespace std;
struct edge{int r,nxt;}e[maxn<<1];
int dp[maxn][maxn][maxn][maxn],cnt[maxn],n,head[maxn],esz,dis[maxn][maxn];
bool vis[maxn][maxn][maxn][maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
int dfs(int u,int f,int in,int tot){
	if(!tot)return 0;
	if(vis[u][f][in][tot])
		return dp[u][f][in][tot];
	vis[u][f][in][tot]=1;
	int flag=0;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)flag=1;
	if(!flag)return dp[u][f][in][tot]=(tot==in?0:dfs(f,u,tot-in,tot-in)+dis[f][u]);
	int g[maxn]={inf};
	for(int i=1;i<=in;++i)g[i]=-inf;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		for(int i=in;i>=1;--i)
			for(int j=i;j>=1;--j)
				g[i]=max(g[i],min(g[i-j],dis[u][e[t].r]+dfs(e[t].r,u,j,tot)));
	return dp[u][f][in][tot]=g[in];
}
void dfs(int u,int f){
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		dfs(e[t].r,u),cnt[u]+=cnt[e[t].r];
}
int main(){
	scanf("%d",&n);
	for(int i=2,u,v,w;i<=n;++i)
		scanf("%d%d%d",&u,&v,&w),dis[u][v]=dis[v][u]=w,addedge(u,v);
	int s,m;
	scanf("%d%d",&s,&m);
	for(int i=1,c;i<=m;++i)
		scanf("%d",&c),cnt[c]++;
	dfs(s,0);
	int ans=inf;
	for(int t=head[s];t;t=e[t].nxt)
		ans=min(ans,dfs(e[t].r,s,cnt[e[t].r],m)+dis[s][e[t].r]);
	if(ans>=inf)printf("Terrorists win");
	else printf("%d",ans);
}