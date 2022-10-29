#include<bits/stdc++.h>
#define maxn 401000
using namespace std;
typedef long long ll;
struct edge{
	int r,nxt;
}e[maxn<<1];
int n,head[maxn],esz;
ll sum,sz[maxn][2],dp[maxn][2],dep[maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void dfs(int u,int f,int d){
	dep[u]=d;
	dp[u][d&1]=d,sz[u][d&1]=1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		dfs(e[t].r,u,d+1);
	ll _f[4]={0},g[4]={0};
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				_f[i^j]+=dp[u][i]*sz[e[t].r][j]+sz[u][i]*dp[e[t].r][j],g[i^j]+=sz[u][i]*sz[e[t].r][j];
		dp[u][0]+=dp[e[t].r][0];
		dp[u][1]+=dp[e[t].r][1];
		sz[u][0]+=sz[e[t].r][0];
		sz[u][1]+=sz[e[t].r][1];
	}
//	printf("[%lld,%lld]",_f[0],_f[1]);
	sum+=_f[0]-g[0]*d*2;
	sum+=_f[1]-g[1]*d*2+g[1];
}
int main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	dfs(1,0,0);
	printf("%lld",sum/2);
}