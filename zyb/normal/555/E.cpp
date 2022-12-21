#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 200005
int i,j,k,l,s,tot,n,m,x[N],y[N],low[N],dfn[N],st[N],v[N],q[N],last[N],to[2*N],next[2*N];
int fa[N],f[N],t[N*4],stack,dis[N],Si[N],p[N],si,be[N],Q;
struct node {
	int x,y;
}b[N];
using namespace std;
inline void add(int o,int p) {
	next[++tot]=last[o]; last[o]=tot; to[tot]=p;
}
inline void tarjan(int x,int y) {
	low[x]=dfn[x]=++tot;
	q[++stack]=x,v[x]=1;
	for (int i=last[x];i;i=next[i]) {
		if (i==(y^1)) continue;
		if (!dfn[to[i]]) tarjan(to[i],i),low[x]=min(low[x],low[to[i]]);
		else if (v[to[i]]) low[x]=min(low[x],dfn[to[i]]);
	}
	if (low[x]==dfn[x]) {
		++si;
		while (q[stack]!=x) p[q[stack]]=si,v[q[stack--]]=0;
		p[q[stack]]=si,v[q[stack--]]=0;
	}
}
inline void build(int o) {
	int l=0,r=1; dis[o]=1; q[1]=o;
	while (l<r) {
		int k=q[++l];
		be[k]=o;
		for (int i=last[k];i;i=next[i]) {
			if (to[i]==fa[k]||fa[to[i]]) continue;
			fa[q[++r]=to[i]]=k;
			dis[to[i]]=dis[k]+1;
		}
	}
	for (int i=r;i;i--) Si[q[i]]++,Si[fa[q[i]]]+=Si[q[i]];
}
inline void dfs(int o,int p) {
	if (!p) p=o;
	st[o]=++tot;
	f[o]=p;
	int gt=0,gtw=0;
	for (int i=last[o];i;i=next[i]) {
		if (to[i]==fa[o]) continue;
		if (Si[to[i]]>gt) gt=Si[to[i]],gtw=to[i];
	}
	if (gtw) dfs(gtw,p);
	for (int i=last[o];i;i=next[i]) {
		if (to[i]==fa[o]||to[i]==gtw) continue;
		dfs(to[i],0);
	}
}
inline int getlca(int x,int y) {
	while (f[x]!=f[y]) if (dis[f[x]]>dis[f[y]]) x=fa[f[x]];
	else y=fa[f[y]];
	if (dis[x]>dis[y]) return y;
	return x;
}
inline void change(int o,int l,int r,int ll,int rr,int p) {
	if (l==ll&&r==rr) {
		t[o]|=p; return ;
	}
	t[o*2]|=t[o]; t[o*2+1]|=t[o];
	int mid=(l+r)>>1;
	if (rr<=mid) change(o*2,l,mid,ll,rr,p);
	else if (ll>mid) change(o*2+1,mid+1,r,ll,rr,p);
	else change(o*2,l,mid,ll,mid,p),change(o*2+1,mid+1,r,mid+1,rr,p);
}
inline int get(int x,int y) {
	change(1,1,n,st[f[x]],st[x],y);
	return fa[f[x]];
}
inline void work(int x,int y,int z) {
	while (f[x]!=f[y]) if (dis[f[x]]>dis[f[y]]) x=get(x,z);
	else y=get(y,z);
	if (dis[x]>dis[y]) change(1,1,n,st[y]+1,st[x],z);
	else if (dis[x]<dis[y]) change(1,1,n,st[x]+1,st[y],z);
}
inline int ask(int o,int l,int r) {
	if (l==r) return t[o];
	t[o*2]|=t[o]; t[o*2+1]|=t[o];
	int mid=(l+r)>>1;
	return max(ask(o*2,l,mid),ask(o*2+1,mid+1,r));
}
int main() {
	scanf("%d%d%d",&n,&m,&Q);
	tot=1;
	for (i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]),add(x[i],y[i]),add(y[i],x[i]);
	for (i=1;i<=Q;i++) scanf("%d%d",&b[i].x,&b[i].y);
	tot=0;
	for (i=1;i<=n;i++) if (!dfn[i]) tarjan(i,0);
	tot=0;
	memset(last,0,sizeof(last));
	memset(fa,0,sizeof(fa));
	for (i=1;i<=m;i++) {
		if (p[x[i]]==p[y[i]]) continue;
		add(p[x[i]],p[y[i]]);
		add(p[y[i]],p[x[i]]);
	}
	n=si;
	for (i=1;i<=n;i++) if (!be[i]) build(i);
	tot=0;
	for (i=1;i<=n;i++) if (be[i]==i) dfs(i,0);
	for (i=1;i<=Q;i++) {
		if (be[p[b[i].x]]!=be[p[b[i].y]]) return puts("No\n"),0;
		int lca=getlca(p[b[i].x],p[b[i].y]);
		work(p[b[i].x],lca,1);
		work(p[b[i].y],lca,2);
	}
	int gt=ask(1,1,n);
	if (gt==3) printf("No\n");
	else printf("Yes\n");
}