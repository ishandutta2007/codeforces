#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
struct edge{int r,nxt;}e[maxn<<1];
struct data{int u,v,w;};
vector<data>v[maxn];
int n,m,head[maxn],esz,id[maxn],tim,rig[maxn];
int dep[maxn],tr[maxn],dp[maxn],fa[maxn][20];
void add(int x,int a){
	for(;x<=n;x+=x&-x)tr[x]+=a;
}
int query(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=tr[x];
	return ans;
}
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void dfs(int u,int _fa){
	id[u]=++tim,fa[u][0]=_fa,dep[u]=dep[_fa]+1;
	for(int i=1;fa[u][i-1];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=_fa)
		dfs(e[t].r,u);
	rig[u]=tim;
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;d>>i;i++)if(d>>i&1)u=fa[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;--i)if(fa[u][i]^fa[v][i])
		u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int near(int u,int v){
	if(dep[u]>=dep[v])return 0;
	int d=dep[v]-dep[u]-1;
	for(int i=0;d>>i;i++)if(d>>i&1)v=fa[v][i];
	return v;
}
void solve(int u){
	dp[u]=0;
	for(int t=head[u];t;t=e[t].nxt)if(fa[u][0]!=e[t].r)
		solve(e[t].r),dp[u]+=dp[e[t].r];
	int ls=2*query(id[u]),_dpu=dp[u];
	for(int i=0;i<v[u].size();++i){
		int psum=dp[u];
		int x=v[u][i].u,y=v[u][i].v,w=v[u][i].w;
		int z=query(id[x])+query(id[y])-ls;
//		printf("[%d]",z);
		_dpu=max(_dpu,psum+z+w);
	}
	add(id[u],dp[u]-_dpu);
	add(rig[u]+1,_dpu-dp[u]);
	dp[u]=_dpu;
//	printf("{%d,%d}",u,dp[u]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2,u;i<=n;++i)
		scanf("%d",&u),addedge(u,i);
	dfs(1,0);
	for(int i=1;i<=m;++i){
		data d;
		scanf("%d%d%d",&d.u,&d.v,&d.w);
		v[lca(d.u,d.v)].push_back(d);
//		printf("{%d}",lca(d.u,d.v));
	}
	solve(1);
	printf("%d",dp[1]);
}