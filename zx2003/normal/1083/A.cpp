#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,w[N],u,v,c,i;
vector<pair<int,int>>e[N];
ll f[N],g[N],ans;
void dfs1(int u,int fa){
	int v,c;
	for(auto z:e[u]){
		tie(v,c)=z;if(v==fa)continue;
		dfs1(v,u);f[u]=max(f[u],f[v]-c);
	}
	f[u]+=w[u];
}
void dfs2(int u,int fa){
	int v,c;
	ans=max(ans,max(f[u],g[u]+w[u]));
	ll mx=0,mx2=0;
	for(auto z:e[u]){
		tie(v,c)=z;if(v==fa)continue;
		if(f[v]-c>=mx)mx2=mx,mx=f[v]-c;else mx2=max(mx2,f[v]-c);
	}
	for(auto z:e[u]){
		tie(v,c)=z;if(v==fa)continue;
		g[v]=max(g[v],max(g[u],f[v]-c==mx?mx2:mx)+w[u]-c);dfs2(v,u);
	}
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",w+i);
	for(i=1;i<n;++i)scanf("%d%d%d",&u,&v,&c),e[u].push_back({v,c}),e[v].push_back({u,c});
	dfs1(1,0);dfs2(1,0);printf("%lld\n",ans);
}