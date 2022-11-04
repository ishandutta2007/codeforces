#include<cstring>
#include<iostream>
#include<algorithm>
#define nn 200010
#define ll long long
using namespace std;
inline int Read(){
	char c=getchar();int f=1,nm=0;
	while ('0'>c||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<=c&&c<='9') nm=nm*10+c-'0',c=getchar();
	return(f*nm);
}
struct Edge{int to,old;}e[nn*2];
int sz[nn],bl[nn],fa[nn],dep[nn],l[nn],tot,dfn[nn],tim;
inline void Dfs0(int x){
	sz[x]=1,dep[x]=dep[fa[x]]+1;
	for (int i=l[x];i;i=e[i].old) if(e[i].to!=fa[x])
	fa[e[i].to]=x,Dfs0(e[i].to),sz[x]+=sz[e[i].to];
}
inline void Dfs1(int x,int y){
	bl[x]=y,dfn[x]=++tim;int k=0;
	for (int i=l[x];i;i=e[i].old) if(e[i].to!=fa[x]&&sz[k]<sz[e[i].to]) k=e[i].to;
	if (k) Dfs1(k,y);
	for (int i=l[x];i;i=e[i].old) if(e[i].to!=fa[x]&&e[i].to!=k) Dfs1(e[i].to,e[i].to);
}
inline int Lca(int x,int y){
	if (dep[bl[x]]<dep[bl[y]]) swap(x,y);
	while (bl[x]!=bl[y]){
		x=fa[bl[x]];
		if (dep[bl[x]]<dep[bl[y]]) swap(x,y);
	}
	if (dep[x]<dep[y]) return(x);return(y);
}
int n,m,cnt,f[nn];
struct Node{ll s;int t,l,r;}t[nn*4];
inline Node Meg(Node l,Node r){
	Node x;
	x.s=l.s+r.s,x.t=l.t+r.t;
	x.l=l.l,x.r=r.r;
	if (l.t==l.l) x.l+=r.l;
	if (r.t==r.r) x.r+=l.r;
	x.s+=f[l.r+r.l]-f[l.r]-f[r.l];
	return(x);
}
inline Node Ask(int x,int l,int r,int a,int b){
	int md=(l+r)/2;
	if (l==a&&r==b) return(t[x]);
	if (b<=md) return(Ask(x*2,l,md,a,b));
	if (md<a) return(Ask(x*2+1,md+1,r,a,b));
	if (a<=md&&md<b){
		Node L=Ask(x*2,l,md,a,md);
		Node R=Ask(x*2+1,md+1,r,md+1,b);
		return(Meg(L,R));
	}
}
inline void Ins(int x,int l,int r,int a){
	int md=(l+r)/2;
	if (l==r){t[x].s=f[1],t[x].t=t[x].l=t[x].r=1;return;}
	if (a<=md) Ins(x*2,l,md,a);else Ins(x*2+1,md+1,r,a);
	t[x]=Meg(t[x*2],t[x*2+1]);
}
inline void Build(int x,int l,int r){
	t[x].t=(r-l+1);
	if (l==r) return;
	Build(x*2,l,(l+r)/2),Build(x*2+1,(l+r)/2+1,r);
}
inline Node Work(int x,int y){
	Node res=(Node){0,0,0},now=res;
	while (dep[bl[x]]>dep[y]){
		now=Ask(1,1,n,dfn[bl[x]],dfn[x]);
		res=Meg(now,res),x=fa[bl[x]];
	}
	if (x!=y){
		now=Ask(1,1,n,dfn[y]+1,dfn[x]);
		res=Meg(now,res);
	}
	return(res);
}
ll ans[nn];
struct Que{int op,u,v,w;}q[nn];
bool Cmpw(Que a,Que b) {return(a.w>b.w||a.w==b.w&&a.op<b.op);}
inline void Lnk(int x,int y) {e[++tot].to=y,e[tot].old=l[x],l[x]=tot;}
int main(){
	n=Read(),m=Read();
	for (int i=1;i<n;i++) f[i]=Read();
	for (int i=1;i<n;i++){
		cnt++,q[i].op=0,q[i].u=Read(),q[i].v=Read(),q[i].w=Read();
		Lnk(q[i].u,q[i].v),Lnk(q[i].v,q[i].u);
	}
	for (int i=1;i<=m;i++) q[++cnt].op=i,q[cnt].u=Read(),q[cnt].v=Read(),q[cnt].w=Read();
	sort(q+1,q+cnt+1,Cmpw);
	Dfs0(1),Dfs1(1,1);
	Build(1,1,n);
	for (int i=1;i<=cnt;i++){
		if (q[i].op==0){
			if (fa[q[i].v]==q[i].u) swap(q[i].u,q[i].v);
			Ins(1,1,n,dfn[q[i].u]);
		}else{
			int lca=Lca(q[i].u,q[i].v);
			Node L=Work(q[i].u,lca),R=Work(q[i].v,lca);
			swap(L.l,L.r);
			Node Ans=Meg(L,R);
			ans[q[i].op]=Ans.s;
		}
	}
	for (int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
}