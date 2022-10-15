#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n,rt,sz[N],deg[N];
vector<int>G[N];
void dfs1(int x,int fa){
	sz[x]=1;
	for(int y:G[x])if(y^fa)dfs1(y,x),sz[x]+=sz[y];
}
int mn[N],cmx[N],mx[N],p[N],g[N];
void dfs2(int x,int fa){
	mn[x]=1e9;
	for(int y:G[x])if(y^fa)g[y]=sz[y];
	for(int y:G[x]){
		if(g[y]>mx[x])cmx[x]=mx[x],mx[x]=g[y],p[x]=y;
		else if(g[y]>cmx[x])cmx[x]=g[y];
		mn[x]=min(mn[x],g[y]);
	}
	for(int y:G[x])if(y^fa)g[x]=n-sz[y],dfs2(y,x);
}
set<int>s1[N];
int tot,ans[N],id[N];
inline void qry(int u){
	int x=(mx[u]-mn[u]+1)/2;
	auto it=s1[id[u]].lower_bound(x);
	if(it!=s1[id[u]].end())ans[u]=min(ans[u],max(mn[u]+*it,mx[u]-*it));
	if(it!=s1[id[u]].begin())it--,ans[u]=min(ans[u],max(mn[u]+*it,mx[u]-*it));
}
void dfs3(int x,int fa){
	int son=0;
	for(int y:G[x])
		if(y!=fa && sz[y]>sz[son])son=y;
	if(son)dfs3(son,x),id[x]=id[son];
	else id[x]=++tot;
	if(p[x]!=fa)qry(x);
	for(int y:G[x]){
		if(y==fa || y==son)continue;
		dfs3(y,x);
		auto it=s1[id[y]].begin();
		while(it!=s1[id[y]].end())
			s1[id[x]].insert(*it),it++;
	}
	s1[id[x]].insert(sz[x]);
}
multiset<int>s;
inline void query(int u,int y=0){
	int x=(mx[u]-mn[u]+1)/2;
	auto it=s.lower_bound(x-y);
	if(it!=s.end())ans[u]=min(ans[u],max(mn[u]+*it+y,mx[u]-*it-y));
	if(it!=s.begin())it--,ans[u]=min(ans[u],max(mn[u]+*it+y,mx[u]-*it-y));
}
void dfs4(int x,int fa){
	if(p[x]==fa)query(x);
	for(int y:G[x])if(y^fa)dfs4(y,x);
	s.insert(sz[x]);
}
void dfs5(int x,int fa){
	if(p[x]==fa)query(x);
	reverse(G[x].begin(),G[x].end());
	for(int y:G[x])if(y^fa)dfs5(y,x);
	s.insert(sz[x]);
}
void dfs6(int x,int fa){
	if(p[x]==fa)query(x,-sz[x]);
	s.insert(sz[x]);
	for(int y:G[x])if(y^fa)dfs6(y,x);
	s.erase(s.find(sz[x]));
}
int main(){
	n=read();
	for(int i=1,x,y;i<=n;i++){
		x=read(),y=read();
		if(!x || !y)rt=x|y;
		else deg[x]++,deg[y]++,G[x].push_back(y),G[y].push_back(x);
	}
	int max_deg=*max_element(deg+1,deg+n+1);
	if(max_deg<=2){
		for(int i=1;i<=n;i++)printf("%d\n",deg[i]==1?n-1:n/2);
		return 0;
	}
	if(max_deg==n-1){
		for(int i=1;i<=n;i++)printf("%d\n",n-deg[i]);
		return 0;
	}
	dfs1(rt,0),dfs2(rt,0),fill(ans+1,ans+n+1,n-1),dfs3(rt,0);
	dfs4(rt,0),s.clear(),dfs5(rt,0),s.clear(),dfs6(rt,0);
	for(int i=1;i<=n;i++)printf("%d\n",min(mx[i],max(ans[i],cmx[i])));
	return 0;
}