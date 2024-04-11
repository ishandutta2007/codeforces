#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 10010
using namespace std;
struct edge{
	int r,nxt,w;
}e[maxn<<1];
struct data{
	int u,v;
}d[maxn];
int f[maxn],tag[maxn],z,yu,n,m,head[maxn],esz,top,anses[maxn],ou,ji,vis[maxn],dep[maxn],fa[maxn][21];
void addedge(int u,int v,int w){
	e[++esz].r=v;e[esz].nxt=head[u];e[esz].w=w;head[u]=esz;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void dfs(int u,int f,int d){
//	printf("<%d>",u);
	dep[u]=d,fa[u][0]=f;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		dfs(e[t].r,u,d+1);
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;d>>i;i++)if((d>>i)&1)u=fa[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;--i)if(fa[u][i]!=fa[v][i])
		u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dfs2(int u,int f,int b){
	int as=tag[u];
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		as+=dfs2(e[t].r,u,e[t].w);
	if(as==ji&&b)anses[++top]=b;
//	printf("[%d,%d<%d>]\n",u,as,ji);
	return as;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&d[i].u,&d[i].v);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int u=d[i].u,v=d[i].v;
		if(find(u)!=find(v))
			addedge(u,v,i),addedge(v,u,i),f[f[u]]=f[v],vis[i]=-1;
	}
	for(int i=1;i<=n;++i)if(find(i)==i)dfs(i,0,1);
//	dfs(1,0,1);
	for(int i=1;i<=20;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=m;++i)if(vis[i]>=0){
		int u=d[i].u,v=d[i].v;
		int l=lca(u,v);
//		printf("<%d,%d,%d>",u,v,l);
		int dis=dep[u]+dep[v]-dep[l]*2+1;
		if(~dis&1)tag[u]-=n,tag[v]-=n,tag[l]+=2*n,ou++;
		else tag[u]++,tag[v]++,tag[l]-=2,yu=i,ji++;
	}
	if(ji==0){
		printf("%d\n",m);
		for(int i=1;i<=m;++i)printf("%d ",i);
		return 0;
	}
	for(int i=1;i<=n;++i)if(find(i)==i)dfs2(i,0,0);
//	dfs2(1,0,0);
	if(ji==1)anses[++top]=yu;
	printf("%d\n",top);
	sort(anses+1,anses+top+1);
	for(int i=1;i<=top;++i)printf("%d ",anses[i]);
}