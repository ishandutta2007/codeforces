#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,i,j,u,v,s,pos[N],ans[N];
vector<int>e[N],ve[N],v2[N],v3[N];
void dfs(int u,int fa){
	for(int v:e[u])if(v!=fa)dfs(v,u);
	for(int v:ve[u])pos[v]=u;
}
unordered_set<int>ss[N];int me[N];
inline void ins(int x,int c){
	ss[x].insert(c);
	for(;ss[x].count(me[x]);++me[x]);
}
void dfs2(int u,int fa){
	for(int v:v2[u]){
		ans[v]=me[u];
		for(int x:v3[v])ins(x,ans[v]);
	}
	for(int v:e[u])if(v!=fa)dfs2(v,u);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(scanf("%d",&s),ve[i].resize(s),j=0;j<s;++j)
		scanf("%d",&ve[i][j]),v3[ve[i][j]].push_back(i),me[i]=1;
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	for(i=1;i<=m;++i)if(pos[i])v2[pos[i]].push_back(i);else ans[i]=1;
	dfs2(1,0);
	u=0;for(i=1;i<=m;++i)u=max(u,ans[i]);
	printf("%d\n",u);
	for(i=1;i<=m;++i)printf("%d ",ans[i]);puts("");
	return 0;
}