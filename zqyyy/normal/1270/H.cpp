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
const int N=5e5+7, M=1e6+7, inf=0x3f3f3f3f;
struct A {
	int v, c;
	A(int _v=0, int _c=0) :v(_v), c(_c) {}
	A operator +(const A &q) const {
		A r;
		if (v<=q.v) {
			r=*this;
			if (v==q.v) r.c+=q.c;
		} else r=q;
		return r;
	}
};
bool vis[M];
namespace seg {
	const int N=4e6+7;
	A t[N]; int tg[N];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {t[p]=t[ls]+t[rs];}
	inline void pt(int p, int v) {t[p].v+=v, tg[p]+=v;}
	inline void pd(int p) {if (tg[p]) pt(ls, tg[p]), pt(rs, tg[p]), tg[p]=0;}
	void build(int p, int l, int r) {
		if (l==r) {t[p]=vis[l]?A(tg[p], 1):A(inf, 0); return;}
		pd(p); int mid=(l+r)>>1; build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	void modify(int p, int l, int r, int x, int y, int v) {
		if (x<=l && r<=y) return pt(p, v); pd(p); int mid=(l+r)>>1;
		if (x<=mid) modify(ls, l, mid, x, y, v); if (y>mid) modify(rs, mid+1, r, x, y, v); upd(p);
	}
	void update(int p, int l, int r, int x) {
		if (l==r) {t[p]=vis[x]?A(tg[p], 1):A(inf, 0); return;} pd(p); int mid=(l+r)>>1;
		x<=mid?update(ls, l, mid, x):update(rs, mid+1, r, x); upd(p);
	}
#undef ls
#undef rs
}
int n, m, Q, a[N];
inline void ins(int x, int v) {
	if (a[x]>a[x+1]) seg::modify(1, 0, m, a[x+1], a[x]-1, v);
}
inline void calc() {
	if (seg::t[1].v==1) printf("%d\n", seg::t[1].c);
	else puts("1");
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read(), a[0]=m=1e6+1;
	for (int i=1; i<=n; i++) a[i]=read(), vis[a[i]]=true;
	for (int i=0; i<=n; i++) ins(i, 1);
	seg::build(1, 0, m);
	while (Q--) {
		int x=read(), v=read();
		ins(x-1, -1), ins(x, -1), vis[a[x]]=false, seg::update(1, 0, m, a[x]), a[x]=v;
		ins(x-1, 1), ins(x, 1), vis[a[x]]=true, seg::update(1, 0, m, a[x]), calc();
	}
	return 0;
}