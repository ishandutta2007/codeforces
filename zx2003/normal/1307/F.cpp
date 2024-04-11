#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=2e5+5;
int n,k,r,x,y,i,j,anc[20][N],dep[N],g[N],a[N],bel[N],q;
bool bb[N];
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
vector<int>e[N];
void dfs(int x,int fa){anc[0][x]=fa;dep[x]=dep[fa]+1;for(int y:e[x])if(y!=fa)dfs(y,x);}
inline int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);int dt=dep[y]-dep[x],i;
	for(i=0;(1<<i)<=dt;++i)if(dt>>i&1)y=anc[i][y];if(x==y)return x;
	for(i=19;i>=0;--i)if(anc[i][x]!=anc[i][y])x=anc[i][x],y=anc[i][y];
	return anc[0][x];
}
inline int dis(int x,int y){return dep[x]+dep[y]-dep[lca(x,y)]*2;}
struct node{int ch[2],fa;P v,s;}t[N];
inline void upd(const int&x){t[x].s=min(min(t[t[x].ch[0]].s,t[t[x].ch[1]].s),t[x].v);}
inline int dir(const int&x,const int&y){return t[x].ch[1]==y;}
inline void setc(const int&x,const int&y,const int&o){t[x].ch[o]=y;t[y].fa=x;}
inline bool nrt(const int&x){return t[t[x].fa].ch[0]==x || t[t[x].fa].ch[1]==x;}
inline void rotate(int x){
	int y=t[x].fa,z=t[y].fa,o;
	if(nrt(y))setc(z,x,dir(z,y));t[x].fa=z;
	o=dir(y,x);setc(y,t[x].ch[!o],o);setc(x,y,!o);upd(y);
}
inline void splay(int x){
	for(;nrt(x);rotate(x)){
		int y=t[x].fa,z=t[y].fa;
		if(nrt(y))rotate(dir(z,y)==dir(y,x)?y:x);
	}
	upd(x);
}
inline void access(int x){int y=0,ox=x;for(;x;x=t[x].fa)splay(x),setc(x,y,1),upd(x),y=x;splay(ox);}
bool cov[N];
inline void mdy(int x){
	access(x);
	for(int y=x;y && !cov[y];y=anc[0][y])cov[y]=1,splay(y),t[y].v={dep[x]-dep[y]*2,x},upd(y);
}
inline int ask(int x){
	access(x);
	return t[x].s.first+dep[x]<=k?t[x].s.second:0;
}
int main(){
	for(i=0;i<N;++i)t[i].v=t[i].s={1<<25,0};
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>r;
	for(i=1;i<n;++i)cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);for(i=1;i<20;++i)for(j=1;j<=n;++j)anc[i][j]=anc[i-1][anc[i-1][j]];
	for(i=1;i<=n;++i)a[i]=i;sort(a+1,a+n+1,[&](int x,int y){return dep[x]<dep[y];});
	for(;r--;)cin>>x,bb[x]=1;
	for(i=1;i<=n;++i)t[i].fa=anc[0][i];
	for(i=1;i<=n;++i){
		x=a[i];
		y=ask(x);
		if(bb[x])g[x]=y?y:x,bel[x]=gfa(x),mdy(x);else bel[x]=y?gfa(y):0;
	}
	for(cin>>q;q--;){
		cin>>x>>y;
		int xx=bel[x],yy=bel[y];
		cout<<(dis(x,y)<=k || (xx && yy && xx==yy) || (xx && dis(xx,y)<=k) || (yy && dis(yy,x)<=k)?"YES":"NO")<<'\n';
	}
	return 0;
}