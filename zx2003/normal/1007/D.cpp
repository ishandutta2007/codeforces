#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=1e5+5,V=4e6,E=2e7;
namespace tst{
struct edge{int to,next;}e[E];
int h[V],ecnt,dfn[V],low[V],xb,st[V],w,bel[V],scccnt,vcnt;bool b[V];
inline void addedge(int x,int y){e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;}
void dfs(int x){
	st[++w]=x;low[x]=dfn[x]=++xb;
	for(int i=h[x];i;i=e[i].next){
		if(!dfn[e[i].to])dfs(e[i].to);
		if(low[e[i].to]<low[x] && !bel[e[i].to])low[x]=low[e[i].to];
	}
	if(low[x]==dfn[x])for(++scccnt;bel[st[w]]=scccnt,b[st[w]^1]?0:b[st[w]]=1,st[w--]!=x;);
}
inline void ini(int n){vcnt=n;memset(h+1,0,n<<2);ecnt=0;}
inline void wk(int z){
	int i;
	scccnt=0;memset(dfn+1,0,vcnt<<2);memset(low+1,0,vcnt<<2);memset(bel+1,0,vcnt<<2);memset(b+1,0,vcnt);
	for(i=2;i<=vcnt;++i)if(!dfn[i])dfs(i);
	for(i=1;i<=z;++i)if(bel[i<<1]==bel[i<<1|1])break;if(i<=z){puts("NO");return;}
	puts("YES");
	for(i=1;i<=z;++i)printf("%d\n",b[i<<1]?1:2);
}
}
int n,x,y,m,i,j,a,b,c,d;
vector<int>e[N];
int anc[20][N],dep[N];
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int dt=dep[y]-dep[x],i;for(i=0;1<<i<=dt;++i)if(dt>>i&1)y=anc[i][y];if(x==y)return x;
	for(i=19;i>=0;--i)if(anc[i][x]!=anc[i][y])x=anc[i][x],y=anc[i][y];return anc[0][x];
}
int kthfa(int x,int k){for(int i=0;1<<i<=k;++i)if(k>>i&1)x=anc[i][x];return x;}
void dfs(int x,int fa){anc[0][x]=fa;dep[x]=dep[fa]+1;for(int y:e[x])if(y!=fa)dfs(y,x);}
vector<P>in[N],out[N];
struct node{int l,r,v;}t[V];int rt[N],tcnt;
void link1(int x,int y){tst::addedge(x*2+1,y*2+1),tst::addedge(y*2,x*2);}
void link2(int x,int y){tst::addedge(x*2,y*2+1),tst::addedge(y*2,x*2+1);}
int C;
void upd(int z){
	if(t[z].l)link1(z,t[z].l);if(t[z].r)link1(z,t[z].r);
	if(t[z].l && t[z].r)link2(t[z].l,t[z].r);
}
int merge(int x,int y){
	if(!x || !y)return x|y;
	int z=++tcnt;
	if(!t[x].l && !t[x].r)link1(z,x),link1(z,y),t[z].v=t[x].v|t[y].v;
		else t[z].l=merge(t[x].l,t[y].l),t[z].r=merge(t[x].r,t[y].r);
	upd(z);return z;
}
void mdy(int x,int&y,int l,int r,int k,int v,int tp){
	t[y=++tcnt]=t[x];
	if(l==r){
		if(tp==1)t[y].v|=1<<(v&1);else t[y].v^=1<<(v&1);
		v=v&~1;
		if(t[y].v&1)tst::addedge(v,y*2),tst::addedge(y*2+1,v^1);
		if(t[y].v&2)tst::addedge(v^1,y*2),tst::addedge(y*2+1,v);
		return;
	}
	int m=l+r>>1;if(k<=m)mdy(t[x].l,t[y].l,l,m,k,v,tp);else mdy(t[x].r,t[y].r,m+1,r,k,v,tp);
	upd(y);
}
void dfss(int x,int fa){
	for(P u:in[x])mdy(rt[x],rt[x],1,m,u.first,u.second,1);
	for(int y:e[x])if(y!=fa){
		dfss(y,x);
		rt[x]=merge(rt[x],rt[y]);
	}
	for(P u:out[x])mdy(rt[x],rt[x],1,m,u.first,u.second,-1);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);for(i=1;i<20;++i)for(j=1;j<=n;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	scanf("%d",&m);tst::vcnt=m*2+1;
	for(i=1;i<=m;++i){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		auto doo=[&](int a,int b,int o){
			int l=lca(a,b);
			if(l!=a)in[a].push_back({i,o}),out[kthfa(a,dep[a]-dep[l]-1)].push_back({i,o});
			if(l!=b)in[b].push_back({i,o}),out[kthfa(b,dep[b]-dep[l]-1)].push_back({i,o});
		};
		doo(a,b,i*2);doo(c,d,i*2+1);
	}
	tcnt=m;
	dfss(1,0);
	tst::wk(m);
	return 0;
}