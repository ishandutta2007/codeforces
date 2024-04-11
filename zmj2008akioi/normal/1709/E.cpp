#include <cstdio>
#include <set>
const int N=4e5+10;
int n,ans,dnt,a[N],tag[N],head[N],to[N],next[N];
bool vis[N];std::set<int> set[N];
inline void swp(int &x,int &y){x^=y^=x^=y;}
inline void addedge(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void dfs(int u){
	bool ng=false;vis[u]=true,set[u].insert(0);
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;dfs(to[i]);
		if(set[u].size()<set[to[i]].size())set[u].swap(set[to[i]]),swp(tag[u],tag[to[i]]);
		for(int j:set[to[i]]){
			j^=tag[to[i]];
			if(set[u].find(j^a[u]^tag[u])!=set[u].end())ng=true;
		}
		for(int j:set[to[i]])set[u].insert(j^tag[to[i]]^tag[u]);
	}
	tag[u]^=a[u];
	if(ng)++ans,set[u].clear();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int u,v,i=1;i<n;++i)scanf("%d %d",&u,&v),addedge(u,v),addedge(v,u);
	dfs(1),printf("%d",ans);return 0;
}