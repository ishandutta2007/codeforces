#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
struct edge{int r,nxt,w;}e[maxn<<1];
typedef pair<int,int> par;
int n,m,d[maxn],sz[maxn],head[maxn],esz,tg[maxn],vis[maxn];
map<par,int> st;
int dfs(int u,int f){
	if(f!=-1)sz[u]=1;
	else sz[u]=0;
	vis[u]=1;
	for(int s,t=head[u];t;t=e[t].nxt)if(!vis[e[t].r])
		s=dfs(e[t].r,u),sz[u]+=s,(s?tg[e[t].w]=1:0);
	if(d[u]!=-1&&sz[u]%2!=d[u])return 0;
//	printf("<%d,%d>",u,sz[u]);
	return 1;
}
void addedge(int u,int v,int w){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=w;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&d[i]);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),st[par(u,v)]=i;
	for(auto s:st)addedge(s.first.first,s.first.second,s.second);
	int pos=1,ans=0;
	for(int i=1;i<=n;++i)if(d[i]==-1)pos=i;
	dfs(pos,-1);
	if(d[pos]!=-1&&sz[pos]%2!=d[pos])return puts("-1"),0;
	for(int i=1;i<=m;++i)ans+=tg[i];
	printf("%d\n",ans);
	for(int i=1;i<=m;++i)if(tg[i])printf("%d\n",i);
}