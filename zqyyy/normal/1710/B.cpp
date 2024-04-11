#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
const int N=2e5+7;
const ll INF=4e18;
struct node {
	int x, p, id;
	bool operator <(const node &q) const {
		return x<q.x;
	}
}a[N];
int n, m, ans[N], L[N], R[N], cl[N], cr[N];
ll h[N];
struct Segment_Tree {
	ll t[N<<2], tg[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p) {t[p]=max(t[ls], t[rs]);}
	void build(int p, int l, int r) {
		tg[p]=0; if (l==r) {t[p]=h[l]+a[l].x; return;} int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	inline void pt(int p, ll v) {t[p]+=v, tg[p]+=v;}
	inline void pd(int p) {if (tg[p]) pt(ls, tg[p]), pt(rs, tg[p]), tg[p]=0;}
	void modify(int p, int l, int r, int x, int y, ll v) {
		if (x<=l && r<=y) return pt(p, v); pd(p); int mid=(l+r)>>1;
		if (x<=mid) modify(ls, l, mid, x, y, v); if (y>mid) modify(rs, mid+1, r, x, y, v); upd(p);
	}
	ll query(int p, int l, int r, int x, int y) {
		if (x<=l && r<=y) return t[p]; pd(p); int mid=(l+r)>>1; ll res=-INF;
		if (x<=mid) ckmax(res, query(ls, l, mid, x, y)); if (y>mid) ckmax(res, query(rs, mid+1, r, x, y)); return res;	
	}
}T;
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=n; i++) {
		a[i].x=read(), a[i].p=read(), a[i].id=i;
		h[i]=0, cl[i]=cr[i]=0;
	}
	sort (a+1, a+n+1);
	for (int i=1; i<=n; i++) {
		int l=1, r=i;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (a[i].x-a[mid].x<=a[i].p) r=mid-1;
			else l=mid+1;
		}
		L[i]=l, l=i, r=n;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (a[mid].x-a[i].x<=a[i].p) l=mid+1;
			else r=mid-1;
		}
		R[i]=r;
		cl[L[i]]++, cl[i]--, cr[i]++, cr[R[i]+1]--;
		h[L[i]]+=-a[i].x+a[i].p, h[i]-=-a[i].x+a[i].p;
		h[i]+=a[i].p+a[i].x, h[R[i]+1]-=a[i].p+a[i].x;
	}
	for (int i=1; i<=n; i++) h[i]+=h[i-1], cl[i]+=cl[i-1], cr[i]+=cr[i-1];
	for (int i=1; i<=n; i++) h[i]+=(ll)cl[i]*a[i].x, h[i]-=(ll)cr[i]*a[i].x;
	int le=1; while (le<=n && h[le]<=m) le++;
	int ri=n; while (ri && h[ri]<=m) ri--;
	if (le>ri) {
		for (int i=1; i<=n; i++) putchar(49);
		putchar(10); return;	
	}
	T.build(1, 1, n);
	for (int i=1; i<=n; i++) {
		ans[a[i].id]=0;
		if (L[i]<=le && ri<=R[i]) {
			if (L[i]<i) T.modify(1, 1, n, L[i], i-1, -(a[i].p-a[i].x));
			T.modify(1, 1, n, i, R[i], -(a[i].p+a[i].x));
			ans[a[i].id]=T.query(1, 1, n, L[i], R[i])<=m;
			if (L[i]<i) T.modify(1, 1, n, L[i], i-1, a[i].p-a[i].x);
			T.modify(1, 1, n, i, R[i], a[i].p+a[i].x);
		}
		T.modify(1, 1, n, i, i, -2*a[i].x);
	}
	for (int i=1; i<=n; i++) printf("%d", ans[i]); putchar(10);
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}