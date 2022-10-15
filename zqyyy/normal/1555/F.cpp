#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+7,M=5e5+7;
int pa[N];
int find(int x){return x^pa[x]?pa[x]=find(pa[x]):x;}
struct Edge{
	int to,nxt,w;	
}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]=(Edge){y,head[x],w},head[x]=s_e;
}
int n,Q,dis[N];
struct BIT{
	int c[N];
	#define lb(x) ((x)&-(x))
	inline void add(int p,int x){for(;p<=n;p+=lb(p))c[p]+=x;}
	inline int ask(int p){int res=0;for(;p;p-=lb(p))res+=c[p];return res;}	
}T;
int s_dfn,dfn[N],fa[N],sz[N];
int u[M],v[M],w[M],LCA[M];
bool flg[M];
vector<int>q[N];
inline void dfs(int x){
	dfn[x]=++s_dfn,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;if(dfn[y])continue;
		dis[y]=dis[x]^e[i].w,fa[y]=x;
		dfs(y),sz[x]+=sz[y],pa[y]=x;
	}
	for(auto i:q[x]){
		int y=u[i]^v[i]^x;
		if(dfn[y])LCA[i]=find(y);
	}
}
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=Q;i++){
		u[i]=read(),v[i]=read(),w[i]=read();
		int fu=find(u[i]),fv=find(v[i]);
		if(fu^fv){
			add_e(u[i],v[i],w[i]),add_e(v[i],u[i],w[i]);
			pa[fu]=fv,flg[i]=1;
		}else q[u[i]].push_back(i),q[v[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	for(int i=1;i<=Q;i++){
		if(flg[i]){puts("YES");continue;}
		int x=u[i],y=v[i],lca=LCA[i];
		if((dis[x]^dis[y]^w[i]) && T.ask(dfn[x])==T.ask(dfn[lca]) && T.ask(dfn[y])==T.ask(dfn[lca])){
			puts("YES");
			while(x^lca)T.add(dfn[x],1),T.add(dfn[x]+sz[x],-1),x=fa[x];
			while(y^lca)T.add(dfn[y],1),T.add(dfn[y]+sz[y],-1),y=fa[y];
		}else puts("NO");
	}
	return 0;	
}