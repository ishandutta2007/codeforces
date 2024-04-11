#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=3e5+7;
mt19937_64 RAND(random_device{}());
ull val[N];
namespace seg {
	const int N=7e6+7;
	int tot, ls[N], rs[N];
	ull t[N];
	void modify(int &p, int q, int l, int r, int x) {
		p=++tot, t[p]=t[q]^val[x], ls[p]=ls[q], rs[p]=rs[q]; if (l==r) return;
		int mid=(l+r)>>1; x<=mid?modify(ls[p], ls[q], l, mid, x):modify(rs[p], rs[q], mid+1, r, x);
	}
	int query(int a, int b, int c, int d, int l, int r, int x, int y) {
		if (x<=l && r<=y) {
			if (!(t[a]^t[b]^t[c]^t[d])) return -1;
			if (l==r) return l; int mid=(l+r)>>1;
			if (t[ls[a]]^t[ls[b]]^t[ls[c]]^t[ls[d]])
				return query(ls[a], ls[b], ls[c], ls[d], l, mid, x, y);
			return query(rs[a], rs[b], rs[c], rs[d], mid+1, r, x, y);
		}
		int mid=(l+r)>>1;
		if (x<=mid) {
			int v=query(ls[a], ls[b], ls[c], ls[d], l, mid, x, y);
			if (~v) return v;
		}
		if (y>mid) {
			int v=query(rs[a], rs[b], rs[c], rs[d], mid+1, r, x, y);
			if (~v) return v;
		}
		return -1;
	}
}
int n, Q, s_dfn, dfn[N], anc[N][19], a[N], rt[N];
vector<int>G[N];
void dfs(int x, int fa) {
	seg::modify(rt[x], rt[fa], 1, n, a[x]), dfn[x]=++s_dfn, anc[x][0]=fa;
	for (int i=1; i<=18; i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for (int y:G[x]) if (y^fa) dfs(y, x);
}
inline int LCA(int x, int y) {
	if (x==y) return x; if (dfn[x]>dfn[y]) swap(x, y);
	for (int i=18; ~i; i--) if (dfn[anc[y][i]]>dfn[x]) y=anc[y][i];
	return anc[y][0];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read(), val[i]=RAND();
	for (int i=1; i<n; i++) {
		int x=read(), y=read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	while (Q--) {
		int x=read(), y=read(), l=read(), r=read(), lca=LCA(x, y);
		printf("%d\n", seg::query(rt[x], rt[y], rt[lca], rt[anc[lca][0]], 1, n, l, r));
	}
	return 0;
}