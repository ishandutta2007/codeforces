#include<stdio.h>
#include<algorithm>
#define N 1005
#define inf 1000000000
#include<vector>
#define pb push_back
using namespace std;
int i,j,k,l,s,n,m,last[N],q[N],dis[N],e[N],x,y,tot,v[N],bb;
int g[N],Ans,ans[N];
vector<int>G[N];
inline void dfs(int o,int w,int p) {
	v[o]=p;
	g[o]=w;
	for (int i=0;i<G[o].size();i++) {
		if (v[G[o][i]]) if (v[G[o][i]]!=(p^1)) bb=1;
		if (!v[G[o][i]]) dfs(G[o][i],w,p^1);
	}
}
inline void spfa(int o) {
	int l=0,r=1; q[1]=o;
	for (int i=1;i<=n;i++) dis[i]=-1;
	dis[o]=0;
	while (l<r) {
		int k=q[++l];
		for (int i=0;i<G[k].size();i++) if (dis[G[k][i]]==-1) dis[G[k][i]]=dis[k]+1,q[++r]=G[k][i];
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	for (i=1;i<=n;i++) if (!v[i]) dfs(i,i,2);
	if (bb) return puts("-1"),0;
	for (i=1;i<=n;i++) {
		spfa(i);
		for (j=1;j<=n;j++) ans[g[i]]=max(ans[g[i]],dis[j]);
	}
	for (i=1;i<=n;i++) Ans+=ans[i];
	printf("%d\n",Ans);
}