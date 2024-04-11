#include<bits/stdc++.h>
#define N 400005
#define M 20000005
#define aa 4000005
#define pb push_back
using namespace std;
int i,j,k,l,s,n,m,tot,q[aa],F[N],G[aa],Next[N],to[N],last[N],x,y;
int fa[N],si[aa],dis[N],vis[aa],dfn[aa],low[aa],S,T[N],st[N],r,tt,C[aa];
int d[N];
struct Node {
	int x[N],y[N],a[N],b[N];
}A;
int ans[N];
vector<int>g[aa];
inline void add(int x,int y) {
	Next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
struct node {
	int tot,last[M],next[M],to[M];
	inline void add(int x,int y) {
		next[++tot]=last[x]; last[x]=tot; to[tot]=y;
	}
}B;
inline void build(int x) {
	int l=0,r=1; q[1]=x;
	dis[x]=1;
	while (l<r) {
		int k=q[++l];
		for (int i=last[k];i;i=Next[i]) {
			if (fa[k]==to[i]) continue;
			fa[q[++r]=to[i]]=k;
			dis[to[i]]=dis[k]+1;
		}
	}
	for (int i=n;i;i--) si[q[i]]++,si[fa[q[i]]]+=si[q[i]];
}
inline void dfs(int x,int y) {
	if (!y) y=x;
	F[x]=y;
	st[x]=++tot;
	int gt=0,gtw=0;
	for (int i=last[x];i;i=Next[i]) {
		if (to[i]==fa[x]) continue;
		if (si[to[i]]>gt) gt=si[gtw=to[i]];
	}
	if (gtw) dfs(gtw,y);
	for (int i=last[x];i;i=Next[i]) {
		if (to[i]==fa[x]||to[i]==gtw) continue;
		dfs(to[i],0);
	}
}
inline void ask(int o,int l,int r,int ll,int rr,int p) {
	
	if (l==ll&&r==rr) {
		B.add(p,T[o]);
		return ;
	}
	B.add(p,d[o]);
	int mid=(l+r)>>1;
	if (rr<=mid) ask(o*2,l,mid,ll,rr,p);
	else if (ll>mid) ask(o*2+1,mid+1,r,ll,rr,p);
	else ask(o*2,l,mid,ll,mid,p),ask(o*2+1,mid+1,r,mid+1,rr,p);
}
inline void change(int o,int l,int r,int ll,int rr,int p) {
	if (l==ll&&r==rr) {
		B.add(++tot,T[o]);
		T[o]=tot;
		if (o/2) B.add(T[o/2],T[o]);
		B.add(T[o],p);
		B.add(d[o],p);
		if (l!=r) {
			B.add(T[o],T[o*2]);
			B.add(T[o],T[o*2+1]);
		}
		return ;
	}
	int mid=(l+r)>>1;
	if (rr<=mid) change(o*2,l,mid,ll,rr,p);
	else if (ll>mid) change(o*2+1,mid+1,r,ll,rr,p);
	else change(o*2,l,mid,ll,mid,p),change(o*2+1,mid+1,r,mid+1,rr,p);
}
inline void ask(int x,int a,int b,int t) {
	while (F[a]!=F[b]) {
		if (dis[F[a]]>dis[F[b]]) {
			ask(1,1,n,st[F[a]],st[a],x+(t-1)*m);
			a=fa[F[a]];
		}
		else {
			ask(1,1,n,st[F[b]],st[b],x+(t-1)*m);
			b=fa[F[b]];
		}
	}
	if (dis[a]>dis[b]) ask(1,1,n,st[b]+1,st[a],x+(t-1)*m);
	else if (dis[b]>dis[a]) ask(1,1,n,st[a]+1,st[b],x+(t-1)*m);
}
inline void work(int x,int a,int b,int t) {
	while (F[a]!=F[b]) {
		if (dis[F[a]]>dis[F[b]]) {
			change(1,1,n,st[F[a]],st[a],x+(t-1)*m);
			a=fa[F[a]];
		}
		else {
			change(1,1,n,st[F[b]],st[b],x+(t-1)*m);
			b=fa[F[b]];
		}
	}
	if (dis[a]>dis[b]) change(1,1,n,st[b]+1,st[a],x+(t-1)*m);
	else if (dis[b]>dis[a]) change(1,1,n,st[a]+1,st[b],x+(t-1)*m);
}
inline void build(int o,int l,int r) {
	T[o]=++tot;
	d[o]=++tot;
	if (l==r) return ;
	
	int mid=(l+r)>>1;
	build(o*2,l,mid),build(o*2+1,mid+1,r);
	B.add(T[o],T[o*2]);
	B.add(T[o],T[o*2+1]);
}
inline void tarjan(int x) {
	dfn[x]=low[x]=++tt;
	q[++r]=x;
	vis[x]=1;
	for (int i=B.last[x];i;i=B.next[i]) {
		if (!dfn[B.to[i]]) tarjan(B.to[i]),low[x]=min(low[x],low[B.to[i]]);
		else if (vis[B.to[i]]) low[x]=min(low[x],low[B.to[i]]);
	}
	if (low[x]==dfn[x]) {
		++S;
		while (q[r]!=x) {
			vis[q[r]]=0;
			G[q[r]]=S;
			r--;
		}
		vis[x]=0;
		G[x]=S;
		r--;
	}
}
int main() {
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	build(1);
	tot=0;
	dfs(1,0);
	r=0;
	scanf("%d",&m);
	tot=2*m;
	build(1,1,n);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&A.x[i],&A.y[i]);
		scanf("%d%d",&A.a[i],&A.b[i]);
		ask(i,A.x[i],A.y[i],1);
		ask(i,A.a[i],A.b[i],2);
		work(i,A.x[i],A.y[i],2);
		work(i,A.a[i],A.b[i],1);
	}
	//for (i=1;i<=tot;i++) if (!dfn[i]) tarjan(i);
	build(1,1,n);
	for (i=m;i;i--) {
		ask(i,A.x[i],A.y[i],1);
		ask(i,A.a[i],A.b[i],2);
		work(i,A.x[i],A.y[i],2);
		work(i,A.a[i],A.b[i],1);
	}
	if (tot>=aa) return puts("a"),0;
	for (i=1;i<=tot;i++) if (!dfn[i]) tarjan(i);
	for (i=1;i<=m;i++) if (G[i]==G[i+m]) return puts("NO"),0;
	puts("YES");
	for (i=1;i<=tot;i++) g[G[i]].pb(i);
	for (i=1;i<=S;i++) si[i]=0;
	for (i=1;i<=tot;i++) {
		for (j=B.last[i];j;j=B.next[j]) {
			if (G[i]!=G[B.to[j]]) si[G[B.to[j]]]++;
		}
	}
	r=0;
	for (i=1;i<=S;i++) {
		if (!si[i]) q[++r]=i;
	}
	l=0;
	while (l<r) {
		int k=q[++l];
		C[k]=l;
		for (int j=0;j<g[k].size();j++)
		for (int o=B.last[g[k][j]];o;o=B.next[o]) {
			if (G[B.to[o]]==k) continue;
			si[G[B.to[o]]]--;
			if (!si[G[B.to[o]]]) q[++r]=G[B.to[o]];
		}
	}
	for (i=1;i<=m;i++) {
		if (C[G[i]]<C[G[i+m]]) puts("2");
		else puts("1");
	}
}