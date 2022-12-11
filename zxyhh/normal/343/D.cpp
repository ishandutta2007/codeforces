/*
	Author: zxy_hhhh
	date: 2019/03/29
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd()
{
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 500005

int tag[maxn<<2];
void pushdown(int x) {
	if (tag[x]==-1) return ;
	tag[x<<1]=tag[x<<1|1]=tag[x];
	tag[x]=-1;
}
void update(int pos,int l,int r,int ql,int qr,int x) {
	if (r<ql||l>qr) return ;
	if (ql<=l&&r<=qr) {
		tag[pos]=x;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(pos);
	update(pos<<1,l,mid,ql,qr,x);
	update(pos<<1|1,mid+1,r,ql,qr,x);
}
int query(int pos,int l,int r,int x) {
	if (l==r) return tag[pos];
	int mid=(l+r)>>1;
	pushdown(pos);
	if (x<=mid) return query(pos<<1,l,mid,x);
	else return query(pos<<1|1,mid+1,r,x);
}
int nx[maxn<<1],to[maxn<<1],hd[maxn],cnt;
inline void add(int u,int v){nx[++cnt]=hd[u],to[cnt]=v,hd[u]=cnt;}
int dfn[maxn],top[maxn],fa[maxn],id,son[maxn],sz[maxn];
void dfs(int u,int F) {
	sz[u]=1;fa[u]=F;
	cross(i,u) if (to[i]!=F) {
		dfs(to[i],u);
		if (sz[to[i]]>sz[son[u]])
			son[u]=to[i];
		sz[u]+=sz[to[i]];
	}
}
void DFS(int u,int fa,int tp) {
	top[u]=tp,dfn[u]=++id;
	if (son[u]) DFS(son[u],u,tp);
	cross(i,u) if (to[i]!=fa&&to[i]!=son[u])  DFS(to[i],u,to[i]);
}
int n;
int Query(int x) {return query(1,1,n,dfn[x]);}
void Update1(int x) {
	while(x) {
		update(1,1,n,dfn[top[x]],dfn[x],0);
		x=fa[top[x]];
	}
}
void Update2(int x){
	update(1,1,n,dfn[x],dfn[x]+sz[x]-1,1);
}
int main()
{
	n=rd();
	rep(i,2,n) {
		int x=rd(),y=rd();
		add(x,y),add(y,x);
	}
	dfs(1,0);
	DFS(1,0,1);
	int m=rd();
	rep(i,1,m) {
		int op=rd(),x=rd();
		if (op==1) Update2(x);
		else if (op==2) Update1(x);
		else if (op==3) wrt(Query(x),'\n');
	}
}