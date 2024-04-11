#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=100005,INF=1e9;
pii _0=mp(0,-INF);
pii Merge(pii a,pii b){
	return mp(a.fi+b.fi,max(a.se+b.fi,b.se));
}
namespace Seg{
	const int S=N*4;
	int len[S],cov[S];
	pii val[S];
	void build(int rt,int L,int R){
		len[rt]=R-L+1,cov[rt]=0;
		val[rt]=mp(-len[rt],-1);
		if (L==R)
			return;
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	void pushdown(int rt){
		if (cov[rt]){
			int ls=rt<<1,rs=ls|1;
			cov[ls]=cov[rs]=1;
			val[ls]=mp(-len[ls],-1),val[rs]=mp(-len[rs],-1);
			cov[rt]=0;
		}
	}
	void change(int rt,int L,int R,int x,int v){
		if (L==R){
			val[rt].fi+=v,val[rt].se+=v;
			return;
		}
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		if (x<=mid)
			change(ls,L,mid,x,v);
		else
			change(rs,mid+1,R,x,v);
		val[rt]=Merge(val[ls],val[rs]);
	}
	void cover(int rt,int L,int R,int xL,int xR){
		if (R<xL||L>xR)
			return;
		if (xL<=L&&R<=xR){
			val[rt]=mp(-len[rt],-1),cov[rt]=1;
			return;
		}
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		cover(ls,L,mid,xL,xR);
		cover(rs,mid+1,R,xL,xR);
		val[rt]=Merge(val[ls],val[rs]);
	}
	pii query(int rt,int L,int R,int xL,int xR){
		if (R<xL||L>xR)
			return _0;
		if (xL<=L&&R<=xR)
			return val[rt];
		pushdown(rt);
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		return Merge(query(ls,L,mid,xL,xR),query(rs,mid+1,R,xL,xR));
	}
}
int n,q;
vi e[N];
int fa[N],dep[N],sz[N],son[N],top[N],I[N],O[N],aI[N];
void dfs(int x,int d){
	sz[x]=1,dep[x]=d,son[x]=0;
	for (auto y : e[x]){
		dfs(y,d+1);
		sz[x]+=sz[y];
		if (!son[x]||sz[y]>sz[son[x]])
			son[x]=y;
	}
}
void gettop(int x,int tp){
	static int Time=0;
	I[x]=++Time,aI[Time]=x;
	top[x]=tp;
	if (son[x])
		gettop(son[x],tp);
	for (auto y : e[x])
		if (y!=son[x])
			gettop(y,y);
	O[x]=Time;
}
pii query(int x){
	pii res=_0;
	while (x){
		int fx=top[x];
		res=Merge(Seg::query(1,1,n,I[fx],I[x]),res);
		x=fa[fx];
	}
	return res;
}
int main(){
	n=read(),q=read();
	For(i,2,n)
		e[fa[i]=read()].pb(i);
	dfs(1,0);
	gettop(1,1);
	Seg::build(1,1,n);
	while (q--){
		int type=read(),x=read();
		if (type==1)
			Seg::change(1,1,n,I[x],1);
		else if (type==2){
			Seg::cover(1,1,n,I[x],O[x]);
			pii res=query(x);
			if (res.se>=0)
				Seg::change(1,1,n,I[x],-res.se-1);
		}
		else if (type==3){
			pii res=query(x);
			puts(res.se>=0?"black":"white");
		}
	}
	return 0;
}