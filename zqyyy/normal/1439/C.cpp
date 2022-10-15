#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7;
int n, Q, a[N];
namespace seg {
	const int M=N<<2;
	int mn[M], tg[M]; ll t[M];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {mn[p]=min(mn[ls], mn[rs]), t[p]=t[ls]+t[rs];}
	void build(int p, int l, int r) {
		if (l==r) {t[p]=mn[p]=a[l]; return;} int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	inline void pt(int p, int v, int len) {t[p]=(ll)v*len, mn[p]=tg[p]=v;}
	inline void pd(int p, int len) {if (tg[p]) pt(ls, tg[p], (len+1)/2), pt(rs, tg[p], len/2), tg[p]=0;}
	inline void modify(int p, int l, int r, int x, int v) {
		if (mn[p]>=v) return;
		if (l==r) return pt(p, v, 1);
		pd(p, r-l+1); int mid=(l+r)>>1;
		if (x<=mid) modify(ls, l, mid, x, v);
		else if (mn[ls]>=v) modify(rs, mid+1, r, x, v);
		else modify(ls, l, mid, x, v), r<=x?pt(rs, v, r-mid):modify(rs, mid+1, r, x, v);
		upd(p);
	}
	void query(int p, int l, int r, int x, int &v, int &ans) {
		if (x<=l && t[p]<=v) {ans+=r-l+1, v-=t[p]; return;}
		if (mn[p]>v) return;
		pd(p, r-l+1); int mid=(l+r)>>1;
		if (x<=mid) query(ls, l, mid, x, v, ans);
		query(rs, mid+1, r, x, v, ans);
	}
#undef ls
#undef rs
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) a[i]=read();
	seg::build(1, 1, n);
	while (Q--) {
		int opt=read(), x=read(), y=read();
		if (opt==1) seg::modify(1, 1, n, x, y);
		else {
			int ans=0; seg::query(1, 1, n, x, y, ans);
			printf("%d\n", ans);
		}
	}
	return 0;
}