#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
int n,u,v,i,sz[N],fa[N];
vector<int>e[N];
ll f[N][N];
struct state{int x,y,lx,ly;}q[N*N];int t,w;
void dfs(int x,int fa){
	sz[x]=1;::fa[x]=fa;
	for(int y:e[x])if(y!=fa)dfs(y,x),sz[x]+=sz[y];
}
int getsz(int x,int y){return fa[y]==x?sz[y]:n-sz[x];}
void relax(int x,int y,int lx,int ly,ll ff){
	if(x>y)swap(x,y),swap(lx,ly);
	if(!f[x][y])q[++w]=(state){x,y,lx,ly};
	f[x][y]=max(f[x][y],ff+getsz(lx,x)*getsz(ly,y));
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	for(i=2;i<=n;++i)relax(i,fa[i],fa[i],i,0);
	ll ans=0;
	for(;t<w;){
		++t;ans=max(ans,f[q[t].x][q[t].y]);
		for(int z:e[q[t].x])if(z!=q[t].lx)
			relax(z,q[t].y,q[t].x,q[t].ly,f[q[t].x][q[t].y]);
		for(int z:e[q[t].y])if(z!=q[t].ly)
			relax(q[t].x,z,q[t].lx,q[t].y,f[q[t].x][q[t].y]);
	}
	printf("%lld\n",ans);
	return 0;
}