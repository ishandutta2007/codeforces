#include<bits/stdc++.h>
using namespace std;
#define N 500005
int dis[N],vis[N],last[N],tot,to[2*N],val[2*N],Next[2*N],n,m;
struct ed {
	int x,y,v;
}b[N];
inline void add(int x,int y,int z) {
	Next[++tot]=last[x];
	last[x]=tot; to[tot]=y;
	val[tot]=z;
}
inline void dfs(int x) {
	if (!vis[x]) vis[x]=1;
	for (int i=last[x];i;i=Next[i]) {
		if (!vis[to[i]]) {
			vis[to[i]]=1;
			dis[to[i]]=dis[x]+1;
			dfs(to[i]);
		}
	}
}
struct tree {
	int tot,st[N],q[N],fa[N],dis[N],en[N];
	int f[N*4][2],A[N],a[N],d[N*4];
	inline void build(int x) {
		int l=0,r=1; q[1]=x;
		while (l<r) {
			int k=q[++l];
			for (int i=last[k];i;i=Next[i]) {
				if (fa[k]==to[i]) continue;
				fa[q[++r]=to[i]]=k;
				dis[to[i]]=dis[k]+1;
				a[to[i]]=a[k]^val[i];
			}
		}
	}
	inline void dfs(int x) {
		st[x]=++tot;
		A[tot]=x;
		for (int i=last[x];i;i=Next[i]) {
			if (fa[x]==to[i]) continue;
			dfs(to[i]);
		}
		en[x]=tot;
	}
	inline void up(int o) {
		for (int i=0;i<=1;i++)
			f[o][i]=max(f[o*2][i],f[o*2+1][i]);
	}
	inline void build(int o,int l,int r) {
		if (l==r) {
			f[o][0]=f[o][1]=-1;
			f[o][a[A[l]]]=dis[A[l]];
			return ;
		}
		int mid=(l+r)>>1;
		build(o*2,l,mid);
		build(o*2+1,mid+1,r);
		up(o);
	}
	inline void down(int x) {
		d[x*2]^=1;
		d[x*2+1]^=1;
		swap(f[x*2][0],f[x*2][1]);
		swap(f[x*2+1][0],f[x*2+1][1]);
		d[x]=0;
	}
	inline void change(int o,int l,int r,int ll,int rr) {
		if (l==ll&&r==rr) {
			swap(f[o][0],f[o][1]);
			d[o]^=1;
			return ;
		}
		if (d[o]) down(o);
		int mid=(l+r)>>1;
		if (rr<=mid) change(o*2,l,mid,ll,rr);
		else if (ll>mid) change(o*2+1,mid+1,r,ll,rr);
		else change(o*2,l,mid,ll,mid),change(o*2+1,mid+1,r,mid+1,rr);
		up(o);
	}
	inline void change(int x,int y) {
		if (st[x]>st[y]) swap(x,y);
		change(1,1,n,st[y],en[y]);
	}
}A,B;
int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].v);
		add(b[i].x,b[i].y,b[i].v);
		add(b[i].y,b[i].x,b[i].v);
	}
	dfs(1);
	int X=0,Y=0;
	for (int i=1;i<=n;i++) if (dis[i]>=dis[X]) X=i;
	for (int i=1;i<=n;i++) dis[i]=vis[i]=0;
	dfs(X);
	for (int i=1;i<=n;i++) if (dis[i]>=dis[Y]) Y=i;
	A.build(X);
	B.build(Y);
	A.dfs(X);
	B.dfs(Y);
	A.build(1,1,n);
	B.build(1,1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) {
		int x;
		scanf("%d",&x);
		A.change(b[x].x,b[x].y);
		B.change(b[x].x,b[x].y);
		printf("%d\n",max(A.f[1][0],B.f[1][0]));
	}
}