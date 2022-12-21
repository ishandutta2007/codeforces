#include<stdio.h>
#define N 1000005
#define M 2000005
#include<algorithm>
using namespace std;
int i,j,k,l,s,n,m,f[N],st[N],dis[N],q[N],size[N],ans[N],Ans,fa[N],da[N],x[M],y[M];
int tot,last[N],next[M],to[M],si,v[N],a[N];
inline void add(int o,int p) {
	next[++tot]=last[o]; last[o]=tot; to[tot]=p;
}
struct node {
	int F[N];
	inline int get(int x) {
		F[st[f[x]]]++,F[st[x]+1]--;
		return fa[f[x]];
	}
	inline void change(int x,int y) {
		while (f[x]!=f[y]) {
			if (dis[f[x]]>dis[f[y]]) x=get(x);
			else y=get(y);
		}
		if (dis[x]>dis[y]) F[st[y]+1]++,F[st[x]+1]--;
		if (dis[x]<dis[y]) F[st[x]+1]++,F[st[y]+1]--;
	}
	inline void work() {
		for (int i=1;i<=n;i++) F[i]+=F[i-1];
	}
	inline int ask(int o) {
		return F[st[o]];
	}
}A,B;
inline void build(int o) {
	int l=0,r=1; q[1]=o; dis[o]=1; a[o]=1;
	while (l<r) {
		int k=q[++l];
		for (int i=last[k];i;i=next[i]) {
			if (fa[k]==to[i]) continue;
			dis[to[i]]=dis[fa[q[++r]=to[i]]=k]+1;
			a[to[i]]=a[k]^1;
		}
	}
	for (int i=r;i;i--) size[q[i]]++,size[fa[q[i]]]+=size[q[i]];
}
inline void dfs(int o,int p) {
	st[o]=++tot;
	if (!p) p=o;
	f[o]=p;
	int gt=0,gtw=0;
	for (int i=last[o];i;i=next[i]) {
		if (to[i]==fa[o]) continue;
		if (size[to[i]]>gt) gt=size[to[i]],gtw=to[i];
	}
	if (gtw) dfs(gtw,p);
	for (int i=last[o];i;i=next[i]) {
		if (to[i]==fa[o]||to[i]==gtw) continue;
		dfs(to[i],0);
	}
}
inline int getf(int o) {
	if (fa[o]==o) return o;
	return fa[o]=getf(fa[o]);
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++) {
		scanf("%d%d",&x[i],&y[i]);
		if (getf(x[i])==getf(y[i])) v[i]=1;
		else fa[getf(x[i])]=getf(y[i]),add(x[i],y[i]),add(y[i],x[i]);
	}
	for (i=1;i<=n;i++) fa[i]=0; tot=0;
	for (int ii=1;ii<=n;ii++) {
		if (!st[ii]) {
			build(ii);
			dfs(ii,0);
		}
	}
		for (i=1;i<=m;i++) {
			if (!v[i]) continue;
			if (a[x[i]]==a[y[i]]) A.change(x[i],y[i]),si++;
			else B.change(x[i],y[i]);
		}
		if (si<=1) {
			for (i=1;i<=m;i++) {
				if (!v[i]) continue;
				if (a[x[i]]==a[y[i]]) ans[i]=1,Ans++;
				else if (!si) ans[i]=1,Ans++;
			}
		}
		A.work(); B.work();
		for (i=1;i<=m;i++) {
			if (v[i]) continue;
			int gt;
			if (fa[x[i]]==y[i]) gt=x[i];
			else gt=y[i];
			int gtw=A.ask(gt),yy=B.ask(gt);
			if (gtw&&yy) ans[i]=0;
			else if (!si) ans[i]=1,Ans++;
			else if (si==gtw) ans[i]=1,Ans++;
			else ans[i]=0;
		}
	printf("%d\n",Ans);
	for (i=1;i<=m;i++) if (ans[i]) printf("%d ",i);
}