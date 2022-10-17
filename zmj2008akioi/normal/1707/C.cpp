#include <cstdio>
#include <vector>
const int PW=20,N=1e5+10,M=2e5+10;
int n,m,cnt,dnt,f[N],d[N],sz[N],rev[N],dfn[N],dep[N],head[N],to[M],next[M],dbl[PW][N];
bool vis[N],ans[N];
struct edge{
	int u,v;
	edge(){};
	edge(int u,int v):u(u),v(v){};
};std::vector<edge> vec;
inline void swp(int &x,int &y){x^=y^=x^=y;}
inline int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void dfs(int u){
	sz[u]=1,vis[u]=true,dfn[u]=++cnt,rev[cnt]=u;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		dbl[0][to[i]]=u,dep[to[i]]=dep[u]+1,dfs(to[i]),sz[u]+=sz[to[i]];
	}
}
int access(int u,int v){
	for(int i=PW-1;~i;--i)if(dep[v]+(1<<i)<dep[u])u=dbl[i][u];
	return u;
}
int lca(int u,int v){
	if(dep[u]>dep[v])swp(u,v);
	for(int i=PW-1;~i;--i)if(dep[u]+(1<<i)<=dep[v])v=dbl[i][v];
	if(u==v)return u;
	for(int i=PW-1;~i;--i)if(dbl[i][u]!=dbl[i][v])u=dbl[i][u],v=dbl[i][v];
	return dbl[0][u];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int u,v,i=1;i<=m;++i){
		scanf("%d %d",&u,&v);
		if(find(u)!=find(v))f[find(u)]=find(v),addedge(u,v),addedge(v,u);
		else vec.push_back(edge(u,v));
	}
	dfs(1);
	for(int i=1;i<PW;++i)for(int j=1;j<=n;++j)dbl[i][j]=dbl[i-1][dbl[i-1][j]];
	for(edge i:vec){
		int u=i.u,v=i.v,c=lca(u,v);
		if(c==v)swp(u,v);
		if(c==u){
			int t=access(v,c);
			int l1=dfn[t],r1=dfn[t]+sz[t]-1;
			int l2=dfn[v],r2=dfn[v]+sz[v]-1;
			++d[l1],--d[l2],++d[r2+1],--d[r1+1];
		}
		else{
			if(dfn[u]>dfn[v])swp(u,v);
			int l1=dfn[u],r1=dfn[u]+sz[u]-1;
			int l2=dfn[v],r2=dfn[v]+sz[v]-1;
			++d[1],--d[l1],++d[r1+1],--d[l2],++d[r2+1],--d[n+1];
		}
	}
	for(int i=1;i<=n;++i)if(d[i]+=d[i-1])ans[rev[i]]=true;
	for(int i=1;i<=n;++i)putchar(ans[i]?'0':'1');
	return 0;
}