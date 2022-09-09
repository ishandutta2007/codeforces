#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const int N=1e5+5;
int n,q,x,y,u,v,w,i,j,g[N],sz[N],ans,a[N];
vector<pii>e[N];
ll md,dep[N],dis[N],L;int dad[N];
void dfs(int x,int fa,ll d){
	if(d>=md)md=d,u=x;dad[x]=fa;dep[x]=d;
	for(pii E:e[x])if(E.first!=fa)dfs(E.first,x,d+E.second);
}
void dfs2(int x,int fa,ll d){
	dis[x]=max(dis[x],d);
	for(pii E:e[x])if(E.first!=fa)dfs2(E.first,x,d+E.second);
}
void dfs3(int x,int fa){dad[x]=fa;for(pii E:e[x])if(E.first!=fa)dfs3(E.first,x);}
bool cmp(int x,int y){return dis[x]<dis[y];}
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<n;++i)cin>>x>>y>>v,
		e[x].push_back(pii(y,v)),e[y].push_back(pii(x,v));
	dfs(1,0,0);md=0;dfs(v=u,0,0);
	ll mn,z;
	for(i=u;i!=v;i=dad[i])if(z=max(dep[i],md-dep[i]),!w || z<mn)mn=z,w=i;
	dfs2(u,0,0);dfs2(v,0,0);dfs3(w,0);
	for(i=1;i<=n;++i)a[i]=i;sort(a+1,a+n+1,cmp);
	for(cin>>q;q--;){
		cin>>L;
		ans=0;for(i=1;i<=n;++i)sz[i]=1,g[i]=i;
		for(i=1;i<=n;++i)ans+=dis[i]-dis[w]<=L;
		for(i=j=n;i>1;--i){
			for(;dis[a[j]]>dis[a[i]]+L;--sz[gfa(a[j--])]);
			for(pii E:e[a[i]])if(E.first!=dad[a[i]])sz[a[i]]+=sz[E.first],g[E.first]=a[i];
			ans=max(ans,sz[a[i]]);
		}
		cout<<ans<<'\n';
	}		
	return 0;
}