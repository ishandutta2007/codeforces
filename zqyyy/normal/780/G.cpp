#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=1e5+7, inf=2e9+7, mod=1e9+7;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
struct node {int u, l, r, s; } a[N]; 
int h, w, n;
struct Segment_Tree {
	int t[N<<2];
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q[N];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p) {t[p]=min(t[ls], t[rs]);}
	void build(int p, int l, int r) {
		if (l==r) {t[p]=h+1; q[l].push({h+1, 1}); return;}
		int mid=(l+r)>>1; build(ls, l, mid), build(rs, mid+1, r); upd(p);
	}
	void modify(int p, int l, int r, int x, int y, int v, int &c) {
		if (t[p]>v) return;
		if (l==r) {
			while (!q[l].empty() && q[l].top().fi<=v) inc(c, q[l].top().se), q[l].pop();
			t[p]=q[l].empty()?inf:q[l].top().fi; return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) modify(ls, l, mid, x, y, v, c);
		if (y>mid) modify(rs, mid+1, r, x, y, v, c);
		upd(p);
	}
	void change(int p, int l, int r, int x, int h, int v) {
		if (l==r) {q[l].push({h, v}), t[p]=q[l].top().fi; return;}
		int mid=(l+r)>>1; x<=mid?change(ls, l, mid, x, h, v):change(rs, mid+1, r, x, h, v); upd(p);
	}
	inline int query () {
		int ans=0;
		for (int i=1; i<=w; i++)
			while (!q[i].empty()) inc(ans, q[i].top().se), q[i].pop();
		return ans;
	}
	#undef ls
	#undef rs
}T;
int main() {
// #ifdef LOCAL
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
// #endif
	h=read(), w=read(), n=read();
	for (int i=1; i<=n; i++)
		a[i].u=read(), a[i].l=read(), a[i].r=read(), a[i].s=read();
	sort (a+1, a+n+1, [](auto x, auto y) {return x.u>y.u;});
	T.build(1, 1, w);
	for (int i=1; i<=n; i++) {
		int l=a[i].l, r=a[i].r, c=0, u=a[i].u;
		T.modify(1, 1, w, l, r, u+a[i].s, c);
		if (l>1 && r<w) T.change(1, 1, w, l-1, u, c), T.change(1, 1, w, r+1, u, c);
		else inc(c, c), T.change(1, 1, w, l>1?l-1:r+1, u, c);
	}
	printf("%d\n", T.query());
	return 0;
}