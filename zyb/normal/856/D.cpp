#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#define lowbit(o) o&(-o)
#define N 200005
using namespace std;
long long i,j,k,l,s,n,m,F[N],st[N],tot,fa[N],f[N][2],si[N],dis[N],T[N],G[N];
struct node {
	long long lca,x,y,v;
}a[N];
struct NODE {
	long long last[N],next[N],to[N];
	inline void add(long long x,long long y) {
		next[++tot]=last[x]; last[x]=tot; to[tot]=y;
	}
}A,B;
struct Node {
	long long t[N];
	inline void insert(long long x,long long y) {
		for (;x<=n;x+=lowbit(x)) t[x]+=y;
	}
	inline long long ask(long long x) {
		long long s=0;
		for (;x;x-=lowbit(x)) s+=t[x];
		return s;
	}
}C,D;
inline void dfs(long long o,long long p) {
	if (!p) p=o;
	F[o]=p;
	st[o]=++tot;
	long long gt=0,gtw=0;
	for (long long i=A.last[o];i;i=A.next[i]) if (si[A.to[i]]>gt) gt=si[A.to[i]],gtw=A.to[i];
	if (gtw) dfs(gtw,p);
	for (long long i=A.last[o];i;i=A.next[i]) if (A.to[i]!=gtw) dfs(A.to[i],0);
}
inline long long getlca(long long x,long long y) {
	while (F[x]!=F[y]) {
		if (dis[F[x]]>dis[F[y]]) x=fa[F[x]];
		else y=fa[F[y]];
	}
	if (dis[x]>dis[y]) return y;
	return x;
}
inline long long ask(long long o,long long x,long long y) {
	long long ans=C.ask(st[o])-C.ask(st[o]-1);
	while (F[x]!=F[o]) {
		ans+=C.ask(st[x])-C.ask(st[F[x]]-1);
		ans+=D.ask(st[x])-D.ask(st[F[x]]-1);
		x=fa[F[x]];
	}
	ans+=C.ask(st[x])-C.ask(st[o]);
	ans+=D.ask(st[x])-D.ask(st[o]);
	while (F[y]!=F[o]) {
		ans+=C.ask(st[y])-C.ask(st[F[y]]-1);
		ans+=D.ask(st[y])-D.ask(st[F[y]]-1);
		y=fa[F[y]];
	}
	ans+=C.ask(st[y])-C.ask(st[o]);
	ans+=D.ask(st[y])-D.ask(st[o]);
	return ans;
}
int main() {
	scanf("%I64d%I64d",&n,&m);
	for (i=2;i<=n;i++) scanf("%I64d",&fa[i]),A.add(fa[i],i);
	for (i=n;i;i--) si[i]++,si[fa[i]]+=si[i];
	for (i=1;i<=n;i++) dis[i]=dis[fa[i]]+1;
	tot=0;
	dfs(1,0);
	tot=0;
	for (i=1;i<=m;i++) {
		scanf("%I64d%I64d%I64d",&a[i].x,&a[i].y,&a[i].v);
		a[i].lca=getlca(a[i].x,a[i].y);
		B.add(a[i].lca,i);
	}
	for (i=n;i;i--) {
		C.insert(st[i],G[i]);
		for (j=A.last[i];j;j=A.next[j]) f[i][0]+=T[A.to[j]];
		for (j=B.last[i];j;j=B.next[j]) f[i][1]=max(f[i][1],ask(i,a[B.to[j]].x,a[B.to[j]].y)+a[B.to[j]].v);
		T[i]=max(f[i][0],f[i][1]);
		G[fa[i]]+=T[i];
		D.insert(st[i],/*f[i][0]*/-T[i]);
	}
	printf("%I64d\n",T[1]);
}