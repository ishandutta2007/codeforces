#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
struct Edge{int to,nxt;}e[N];
int s_e,head[N];
inline void add_e(int x,int y){
	e[++s_e]={y,head[x]},head[x]=s_e;	
}
int n,Q,a[N],b[N];
int s_dfn,id[N],dep[N],st[N<<1][19];
inline int ckmin(int x,int y){return dep[x]<dep[y]?x:y;}
inline void init_st(int n){
	for(int j=1;j<=__lg(n);j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=ckmin(st[i][j-1],st[i+(1<<j-1)][j-1]);
}
inline int LCA(int x,int y){
	x=id[x],y=id[y];if(x>y)swap(x,y);int k=__lg(y-x+1);
	return ckmin(st[x][k],st[y-(1<<k)+1][k]);
}
void dfs(int x){
	id[x]=++s_dfn,st[s_dfn][0]=x;
	for(int i=head[x],y;i;i=e[i].nxt)
		dep[y=e[i].to]=dep[x]+1,dfs(y),st[++s_dfn][0]=x;	
}
struct A{int x,y;};
inline bool on(int x,int u,int v){
	int y=LCA(u,v);
	return (LCA(u,x)==x || LCA(v,x)==x) && LCA(x,y)==y;
}
inline bool chk(int x,int y,int u,int v){
	return on(x,u,v) && on(y,u,v);	
}
A operator +(const A &p,const A &q){
	if(!q.x)return p;
	if(!~p.x || !~q.x)return {-1,-1};
	if(chk(q.x,q.y,p.x,p.y))return p;
	if(chk(p.x,p.y,q.x,q.y))return q;
	if(chk(p.x,q.y,p.y,q.x))return {p.y,q.x};
	if(chk(p.x,q.x,p.y,q.y))return {p.y,q.y};
	if(chk(p.y,q.x,p.x,q.y))return {p.x,q.y};
	if(chk(p.y,q.y,p.x,q.x))return {p.x,q.x};
	return {-1,-1};
}
struct Segment_Tree{
	A t[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p){t[p]=t[ls]+t[rs];}
	void build(int p,int l,int r){
		if(l==r){t[p]={b[l],b[l]};return;}
		int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),upd(p);	
	}
	void modify(int p,int l,int r,int x){
		if(l==r){t[p]={b[l],b[l]};return;}
		int mid=(l+r)>>1;x<=mid?modify(ls,l,mid,x):modify(rs,mid+1,r,x);upd(p);
	}
	int query(int p,int l,int r,A res){
		if(l==r)return l;
		int mid=(l+r)>>1;A tmp=t[ls]+res;
		if(~tmp.x)return query(rs,mid+1,r,tmp);
		return query(ls,l,mid,res);
	}
}T;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[a[i]]=i;
	for(int i=2;i<=n;i++)add_e(read(),i);
	dfs(1),init_st(s_dfn),T.build(1,0,n-1),Q=read();
	while(Q--){
		int opt=read();
		if(opt==2){
			if(~T.t[1].x)printf("%d\n",n);
			else printf("%d\n",T.query(1,0,n-1,{0,0}));
		}else{
			int x=read(),y=read();
			swap(a[x],a[y]),b[a[x]]=x,b[a[y]]=y;
			T.modify(1,0,n-1,a[x]),T.modify(1,0,n-1,a[y]);	
		}
	}
	return 0;
}