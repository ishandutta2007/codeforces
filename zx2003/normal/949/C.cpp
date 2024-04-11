#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int low[N],dfn[N],st[N],w,xb,sz[N],sccno[N],cnt,ans,id;
int n,m,H,u[N],i,x,y,h[N];
struct edge{int to,next;}e[N<<1];
inline void addedge(int x,int y){
	e[++xb]=(edge){y,h[x]};h[x]=xb;
}
void dfs(int x){
	low[x]=dfn[st[++w]=x]=++xb;
	for(int i=h[x];i;i=e[i].next){
		int y=e[i].to;
		if(!dfn[y]){
			dfs(y);if(low[y]<low[x])low[x]=low[y];
		}else if(!sccno[y] && dfn[y]<low[x])low[x]=dfn[y];
	}
	if(low[x]==dfn[x]){
		for(sz[sccno[x]=++cnt]=1;st[w]!=x;--w)sccno[st[w]]=cnt,++sz[cnt];
		--w;
	}
}
bool can[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>H;
	for(i=1;i<=n;++i)cin>>u[i];
	for(i=1;i<=m;++i){
		cin>>x>>y;
		if((u[x]+1)%H==u[y])addedge(x,y);
		if((u[y]+1)%H==u[x])addedge(y,x);
	}
	for(i=1,xb=0;i<=n;++i)if(!dfn[i])dfs(i);ans=n+1;
	memset(can,1,sizeof can);
	for(i=1;i<=n;++i){
		for(x=h[i];x;x=e[x].next)if(sccno[i]!=sccno[e[x].to])break;
		if(x)can[sccno[i]]=0;
	}
	for(i=1;i<=cnt;++i)if(can[i] && sz[i]<ans)ans=sz[id=i];
	cout<<ans<<'\n';
	for(i=1;i<=n;++i)if(sccno[i]==id)cout<<i<<' ';
	return 0;
}