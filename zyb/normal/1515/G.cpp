#include<bits/stdc++.h>
using namespace std;
#define N 400005
long long tot,last[N],to[N],Next[N],val[N],vis[N],dis[N],a[N];
long long r,t,fa[N],n,m,low[N],dfn[N],A[N],b[N],q[N];
inline void add(long long x,long long y,long long z) {
	Next[++tot]=last[x]; last[x]=tot; to[tot]=y; val[tot]=z;
}
inline long long gcd(long long x,long long y) {
	if (!y) return x;
	if (x%y==0) return y;
	return gcd(y,x%y);
}
inline void dfs(int x) {
	vis[x]=1;
	q[++r]=x;
	dfn[x]=low[x]=++tot;
	for (long long i=last[x];i;i=Next[i]) {
		if (!dfn[to[i]]) {
			dis[to[i]]=dis[x]+val[i];
			dfs(int(to[i]));
			low[x]=min(low[x],low[to[i]]);
		}
		
		else if (vis[to[i]]) {
			long long len=dis[x]-dis[to[i]]+val[i];
			if (dis[to[i]]>dis[x]) len=abs(dis[to[i]]-dis[x]-val[i]);
			if (!a[to[i]]) a[to[i]]=len;
			else a[to[i]]=gcd(a[to[i]],len);
			low[x]=min(low[x],low[to[i]]);
		}
	}
	if (low[x]==dfn[x]) {
		++t;
		A[t]=0;
		while (1) {
			vis[q[r]]=0;
			if (a[q[r]]) {
				if (!A[t]) A[t]=a[q[r]];
				else A[t]=gcd(A[t],a[q[r]]);
			}
			b[q[r]]=t;
			if (q[r]==x) {
				r--;
				break;
			}
			r--;
		}
	}
}

int main() {
	scanf("%lld%lld",&n,&m);
	for (long long i=1;i<=m;i++) {
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
	}
	for (long long i=1;i<=n;i++) a[i]=0;
	tot=0;
	for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i);
	for (long long i=1;i<=n;i++) a[i]=A[b[i]];
	long long q;
	scanf("%lld",&q);
	for (long long i=1;i<=q;i++) {
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		a[x]=A[b[x]];
		if (!y) puts("YES");
		else if (!a[x]) puts("NO");
		else {
			if (y % gcd(a[x],z)) puts("NO");
			else puts("YES");
		}
	}
}