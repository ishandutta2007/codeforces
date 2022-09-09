#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
struct graph{
struct edge{int to,next;}e[N<<1];
int n,h[N],ecnt;
graph():ecnt(1){}
inline void addedge(int x,int y){
	e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;
	e[++ecnt]=(edge){x,h[y]};h[y]=ecnt;
}
};
int lo[N*2],R;
struct forest:graph{
int f[20][N*2],eu[N*2],xb,id[N],en[N];
void dfs(int x,int fa){
	eu[id[x]=++xb]=x;f[0][xb]=xb;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs(e[i].to,x),f[0][++xb]=id[x],eu[xb]=x;en[x]=xb;
}
inline void ini(int n){
	int i,j;
	this->n=n;
	for(i=1;i<=n;++i)if(!id[i])dfs(i,0);
	for(i=1;i<20;++i)for(j=1;j+(1<<i)-1<=xb;++j)f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
}
inline int lca(int x,int y){
	x=id[x];y=id[y];if(x>y)swap(x,y);
	int l=lo[y-x+1];return eu[min(f[l][x],f[l][y-(1<<l)+1])];
}
}T;
struct Tarjan:graph{
int dfn[N],low[N],xb,bel[N],bel1[N],bel2[N],bcnt,te[N];
void dfs(int x,int fe){
	static int st[N],w;
	dfn[x]=low[x]=++xb;st[++w]=x;
	for(int i=h[x];i;i=e[i].next)if(i!=fe){
		if(!dfn[e[i].to])bel2[e[i].to]=bel2[x],dfs(e[i].to,i^1);
		low[x]=min(low[x],low[e[i].to]);
	}
	if(dfn[x]==low[x])for(te[++bcnt]=fe,bel1[bcnt]=bel2[x];bel[st[w]]=bcnt,st[w--]!=x;);
}
};
struct E_DCC_D:Tarjan{
void ini(int n,int m){
	int i,x,y;
	this->n=n;
	for(i=1;i<=m;++i)cin>>x>>y,addedge(x,y);
	for(i=1;i<=n;++i)if(!dfn[i])bel2[i]=i,dfs(i,0);
	for(i=1;i<=bcnt;++i)if(te[i])T.addedge(bel[e[te[i]].to],i);
	T.ini(bcnt);
}
}G;
inline void rotate(int&x){x=(x+R)%G.n;!x?x=G.n:0;}
inline bool cmp(const int&a,const int&b){return T.id[a]<T.id[b];}
struct solver:Tarjan{
int a[N*3],xxb;
inline void build_VT(){
	static int st[N];int w=0,i,oxxb=xxb;
	sort(a+1,a+xxb+1,cmp);xxb=unique(a+1,a+xxb+1)-a-1;
	for(i=1;i<oxxb;++i)if(G.bel1[a[i]]==G.bel1[a[i+1]])a[++xxb]=T.lca(a[i],a[i+1]);
	sort(a+1,a+xxb+1,cmp);xxb=unique(a+1,a+xxb+1)-a-1;
	st[1]=0;
	for(i=1;i<=xxb;++i){
		if(w && G.bel1[st[w]]!=G.bel1[a[i]]){for(int j=1;j<w;++j)addedge(st[j],st[j+1]);w=0;st[1]=0;}
		for(;w && T.en[st[w]]<T.id[a[i]];--w)if(w>1)addedge(st[w-1],st[w]);
		st[++w]=a[i];st[w+1]=0;
	}
	for(i=1;i<w;++i)addedge(st[i],st[i+1]);
}
int e1[N],e2[N],v0[N];
inline bool solve(){
	int p,q,i;
	cin>>p>>q;
	for(i=1;i<=p;++i)cin>>v0[i],rotate(v0[i]),a[++xxb]=v0[i]=G.bel[v0[i]];
	for(i=1;i<=q;++i)cin>>e1[i]>>e2[i],rotate(e1[i]),rotate(e2[i]),a[++xxb]=e1[i]=G.bel[e1[i]],a[++xxb]=e2[i]=G.bel[e2[i]];
	build_VT();
	for(i=1;i<=q;++i)addedge(e1[i],e2[i]);
	for(i=1;i<=xxb;++i)if(!dfn[a[i]])dfs(a[i],0);
	bool ans=1;
	for(i=2;i<=p;++i)ans=ans && bel[v0[i]]==bel[v0[1]];
	for(i=1;i<=xxb;++i)h[a[i]]=dfn[a[i]]=low[a[i]]=0;
	bcnt=xb=xxb=0;ecnt=1;
	return ans;
}
}S;
int main(){
	int n,m,q,i;
	for(i=2;i<N*2;++i)lo[i]=lo[i>>1]+1;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>q;G.ini(n,m);
	for(i=1;i<=q;++i)cout<<(S.solve()?R=(R+i)%n,"YES":"NO")<<'\n';
	return 0;
}