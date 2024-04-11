#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3e5+7;
int pa[N<<1];
int find(int x){return x^pa[x]?pa[x]=find(pa[x]):x;}
struct Edge{int to,nxt;}e[N<<1];
int s_e,head[N<<1];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e;
}
struct edge{int x,y,w;}ed[N];
int n,Q,tot,w[N<<1];
int s_dfn,dfn[N<<1],dep[N<<1],st[N<<1][20];
void dfs(int x,int fa){
	st[s_dfn][0]=fa,dfn[x]=++s_dfn,dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=e[i].nxt)dfs(e[i].to,x);
}
inline int ckmin(int x,int y){return dep[x]<dep[y]?x:y;}
inline void init_st(int n){
	for(int j=1;j<=__lg(n);j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=ckmin(st[i][j-1],st[i+(1<<j-1)][j-1]);
}
inline int LCA(int x,int y){
	if(x==y)return x;if(dfn[x]>dfn[y])swap(x,y);
	int k=__lg(dfn[y]-dfn[x]);return ckmin(st[dfn[x]][k],st[dfn[y]-(1<<k)][k]);
}
struct Segment_Tree{
	int t[N<<2],s[N<<2],tg[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int *t,int p){
		if(!~t[rs])t[p]=t[ls];
		else if(!~t[ls])t[p]=t[rs];
		else t[p]=LCA(t[ls],t[rs]);
	}
	void build(int p,int l,int r){
		t[p]=-1;if(l==r){s[p]=l;return;}
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r),upd(s,p);
	}
	inline void pt(int p,int v){t[p]=(tg[p]=v)?s[p]:-1;}
	inline void spread(int p){
		if(~tg[p])pt(ls,tg[p]),pt(rs,tg[p]),tg[p]=-1;
	}
	void modify(int p,int l,int r,int x,int y,int v){
		if(x<=l && r<=y)return pt(p,v);
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,v);
		if(y>mid)modify(rs,mid+1,r,x,y,v);
		upd(t,p);
	}
}T;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=tot=read(),Q=read();
	for(int i=1;i<n;i++)ed[i].x=read(),ed[i].y=read(),ed[i].w=read();
	sort(ed+1,ed+n,[](auto x,auto y){return x.w<y.w;});
	for(int i=1;i<=n;i++)pa[i]=i,w[i]=-1;
	for(int i=1;i<n;i++){
		int x=find(ed[i].x),y=find(ed[i].y);
		w[++tot]=ed[i].w,pa[x]=pa[y]=pa[tot]=tot,add_e(tot,x),add_e(tot,y);
	}
	dfs(tot,0),init_st((n-1)<<1),T.build(1,1,n);
	while(Q--){
		int opt=read();
		if(opt<3){
			int l=read(),r=read();
			T.modify(1,1,n,l,r,opt&1);
		}else{
			int x=read(),y=T.t[1],mx=-1;
			if(~y)mx=max({w[y],w[LCA(x,y)]});
			printf("%d\n",mx);
		}
	}
	return 0;
}