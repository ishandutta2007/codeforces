#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7;
const ll INF=1e18;
struct Node {
	ll a, w, v; int id;
	bool operator <(const Node &q) const {return v^q.v?v>q.v:w<q.w;}
} a[N];
int n, i, Q, pos[N];
ll c;
inline void calc() {
	while (i>1 && (1ll<<(i-2))>c) i--;
}
struct Segment_Tree {
	ll w[N<<2][22], v[N<<2][22], W[N<<2][22];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {
		for (int i=1; i<=20; i++) {
			w[p][i]=w[ls][i]+w[rs][i], v[p][i]=v[ls][i]+v[rs][i];
			W[p][i]=min(W[ls][i], w[ls][i]+W[rs][i]);
		}
	}
	inline void Get(int p, int x) {
		for (int i=1; i<=20; i++) {
			w[p][i]=v[p][i]=0, W[p][i]=INF;
			if (a[x].w<(1ll<<i-1)) w[p][i]=a[x].w*a[x].a, v[p][i]=a[x].v*a[x].a;
			else if (a[x].w<(1ll<<i) && a[x].a) W[p][i]=a[x].w; 
		}
	}
	void build(int p, int l, int r) {
		if (l==r) return Get(p, l); int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	void modify(int p, int l, int r, int x) {
		if (l==r) return Get(p, l); int mid=(l+r)>>1;
		x<=mid?modify(ls, l, mid, x):modify(rs, mid+1, r, x); upd(p);
	}
	ll query(int p, int l, int r) {
		if (l==r) {
			ll tmp=min(a[l].a, c/a[l].w);
			return c-=tmp*a[l].w, tmp*a[l].v;
		}
		calc();
		if (w[p][i]<=c) return c-=w[p][i], v[p][i];
		if (w[p][i-1]<=c && c<W[p][i-1]) return c-=w[p][i-1], v[p][i-1];
		int mid=(l+r)>>1; return query(ls, l, mid)+query(rs, mid+1, r);
	}
#undef ls
#undef rs
}T;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i].a=read(), a[i].w=read(), a[i].v=read(), a[i].id=i;
	sort (a+1, a+n+1);
	for (int i=1; i<=n; i++) pos[a[i].id]=i;
	T.build(1, 1, n);
	while (Q--) {
		int opt=read();
		if (opt<3) {
			int d=read(), k=pos[read()];
			opt==1?a[k].a+=d:a[k].a-=d, T.modify(1, 1, n, k);
		} else {
			c=read(), i=20;
			printf("%lld\n", T.query(1, 1, n));
		}
	}
	return 0;
}