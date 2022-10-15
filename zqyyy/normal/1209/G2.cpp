#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7;
int n, Q, a[N];
set<int>s[N];
namespace sgt {
	const int N=8e5+7;
	int mn[N], lmx[N], rmx[N], mx[N], t[N], tg[N];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {
		mn[p]=min(mn[ls], mn[rs]), mx[p]=max(mx[ls], mx[rs]);
		if (mn[ls]<mn[rs])  lmx[p]=lmx[ls], rmx[p]=max(mx[rs], rmx[ls]), t[p]=t[ls];
		else if (mn[ls]>mn[rs]) rmx[p]=rmx[rs], lmx[p]=max(mx[ls], lmx[rs]), t[p]=t[rs];
		else t[p]=t[ls]+t[rs]+max(rmx[ls], lmx[rs]), lmx[p]=lmx[ls], rmx[p]=rmx[rs];
	}
	inline void pt(int p, int v) {tg[p]+=v, mn[p]+=v;}
	inline void pd(int p) {if (tg[p]) pt(ls, tg[p]), pt(rs, tg[p]), tg[p]=0;}
	void modify(int p, int l, int r, int x, int y, int v) {
		if (x<=l && r<=y) return pt(p, v); pd(p); int mid=(l+r)>>1;
		if (x<=mid) modify(ls, l, mid, x, y, v); if (y>mid) modify(rs, mid+1, r, x, y, v); upd(p);
	}
	void change(int p, int l, int r, int x, int v) {
		if (l==r) {t[p]=0, mx[p]=lmx[p]=v; return;} pd(p); int mid=(l+r)>>1;
		x<=mid?change(ls, l, mid, x, v):change(rs, mid+1, r, x, v); upd(p);
	}
#undef ls
#undef rs
}
inline void calc() {printf("%d\n", n-sgt::lmx[1]-sgt::rmx[1]-sgt::t[1]);}
inline void modify(int i, int op) {
	int sz=s[i].size(); if (!sz) return;
	int l=*s[i].begin(), r=*s[i].rbegin();
	sgt::change(1, 1, n, l, op>0?sz:0);
	if (l<r) sgt::modify(1, 1, n, l, r-1, op);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) s[a[i]=read()].insert(i);
	for (int i=1; i<=200000; i++) modify(i, 1);
	calc();
	while (Q--) {
		int p=read(), x=read(), c=a[p];
		modify(c, -1), s[c].erase(p), modify(c, 1), a[p]=x;
		modify(x, -1), s[x].insert(p), modify(x, 1), calc();
	}
	return 0;
}