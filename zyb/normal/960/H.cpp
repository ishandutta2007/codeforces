#include<bits/stdc++.h>
#define N 50005
#define M 15000005
#define pb push_back
#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)
using namespace std;
int i,j,m,n,p,k,q,C,deep[N],top[N],root[N],tot,fa[N],size[N],son[N],st[N],ed[N],col[N],cost[N];
long long typ[N],depth[N];
vector<int>v[N];
struct Node {
	int l,r;
	long long sum,add;
}tree[M];
inline void dfs(int x) {
	int i;
	for (i=0;i<(int)v[x].size();++i) {
		int p=v[x][i];
		deep[p]=deep[x]+1; fa[p]=x;
		dfs(p);
		size[x]+=size[p];
		if (size[p]>size[son[x]]) son[x]=p; 
	}
	size[x]++;
}
inline void Dfs(int x,int tp) {
	st[x]=++tot; 
	top[x]=tp;
	if (son[x]) Dfs(son[x],tp);
	for (int i=0;i<(int)v[x].size();++i) {
		int p=v[x][i];
		if (p==son[x]) continue;
		Dfs(p,p);
	}
	ed[x]=tot;
}
inline void down(int t,int len) {
	if (!tree[t].add) return;
	if (!ls) ls=++tot;
	if (!rs) rs=++tot;
	tree[ls].sum+=tree[t].add*(len-(len>>1));
	tree[rs].sum+=tree[t].add*(len>>1);
	tree[ls].add+=tree[t].add;
	tree[rs].add+=tree[t].add;
	tree[t].add=0;
}
inline long long query(int ll,int rr,int l,int r,int t) {
	if (ll<=l&&r<=rr) return tree[t].sum;
	else {
		long long S=0;
		down(t,r-l+1);
		if (ll<=mid) S+=query(ll,rr,l,mid,ls);
		if (rr>mid)  S+=query(ll,rr,mid+1,r,rs);
		return S;
	}
}
inline void modify(int ll,int rr,int c,int l,int r,int t) {
	if (ll<=l&&r<=rr) {
		tree[t].sum+=c*(r-l+1);
		tree[t].add+=c;
	}
	else {
		down(t,r-l+1);
		if (ll<=mid) {
			if (!ls) ls=++tot;
			modify(ll,rr,c,l,mid,ls);
		}
		if (rr>mid) {
			if 	(!rs) rs=++tot;
			modify(ll,rr,c,mid+1,r,rs);
		} 
		tree[t].sum=tree[ls].sum+tree[rs].sum;
	}
}
inline long long ask(int rt,int x) {
	long long S=0;
	while (x) {
		S+=query(st[top[x]],st[x],1,n,rt);
		x=fa[top[x]];
	}
	return S;
}

inline void add(int rt,int x,int y) {
	while (x) {
		modify(st[top[x]],st[x],y,1,n,rt);
		x=fa[top[x]];
	}
}

inline void ins(int x,int y) {
	depth[x]+=deep[y];
	typ[x]+=2*ask(root[x],y);typ[x]+=deep[y];
	add(root[x],y,1);
}

inline void del(int x,int y) {
	depth[x]-=deep[y];
	add(root[x],y,-1);
	typ[x]-=2*ask(root[x],y);typ[x]-=deep[y];
}

inline double work(int x) {
	return (1.*typ[x]*cost[x]*cost[x]-2.*depth[x]*cost[x]*C+1.*n*C*C)/n;
}

int main() {
	scanf("%d%d%d%d",&n,&m,&q,&C);
	for	(i=1;i<=n;++i) scanf("%d",&col[i]);
	for (i=2;i<=n;++i) scanf("%d",&fa[i]),v[fa[i]].pb(i);
	for (i=1;i<=m;++i) scanf("%d",&cost[i]);deep[1]=1;
	dfs(1);
	Dfs(1,1);
	tot=0;
	for (i=1;i<=m;++i) root[i]=++tot;
	for (i=1;i<=n;++i) ins(col[i],i);
	for (;q--;) {
		int ty,x;
		scanf("%d",&ty);
		if(ty==1) {
			int x,y;
			scanf("%d%d",&x,&y);
			del(col[x],x);
			col[x]=y;
			ins(col[x],x); 
		}
		else scanf("%d",&x),printf("%.10lf\n",work(x));
	}
}