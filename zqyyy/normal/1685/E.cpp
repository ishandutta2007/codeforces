#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n, m, Q, a[N], s[N], pos[N];
ll s1, s2;
inline int dis(int x, int y) {return x<=y?y-x:m-x+y;}
struct Segment_Tree {
	int t[N<<2], tg[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {t[p]=min(t[ls], t[rs]);}
	inline void build(int p=1, int l=0, int r=m) {
		if (l==r) {t[p]=s[l]; return;} int mid=(l+r)>>1;
		build(ls, l, mid), build(rs, mid+1, r), upd(p);
	}
	inline void pt(int p, int v) {t[p]+=v, tg[p]+=v;}
	inline void spread(int p) {
		if (tg[p]) pt(ls, tg[p]), pt(rs, tg[p]), tg[p]=0;
	}
	void modify(int p, int l, int r, int x, int y, int v) {
		if (x<=l && r<=y) return pt(p, v); spread(p); int mid=(l+r)>>1;
		if (x<=mid) modify(ls, l, mid, x, y, v); if (y>mid) modify(rs, mid+1, r, x, y, v); upd(p);
	}
	int ask(int p, int l, int r, int x) {
		if (l==r) return t[p]; spread(p); int mid=(l+r)>>1;
		return x<=mid?ask(ls, l, mid, x):ask(rs, mid+1, r, x);
	}
	int query(int p=1, int l=0, int r=m) {
		if (l==r) return l; spread(p); int mid=(l+r)>>1;
		return t[ls]==t[p]?query(ls, l, mid):query(rs, mid+1, r);
	}
}T;
inline void upd(int v, int p) {
	if (v<=n) {
		int pre=v==1?n+1:v-1, nxt=v+1;
		s1-=dis(pos[pre], pos[v])+dis(pos[v], pos[nxt]), T.modify(1, 0, m, pos[v], m, 1), pos[v]=p;
		s1+=dis(pos[pre], p)+dis(p, pos[nxt]), T.modify(1, 0, m, p, m, -1);
	} else if (v>n+1) {
		int pre=v-1, nxt=v==m?n+1:v+1;
		s2-=dis(pos[pre], pos[v])+dis(pos[v], pos[nxt]), T.modify(1, 0, m, pos[v], m, -1), pos[v]=p;
		s2+=dis(pos[pre], p)+dis(p, pos[nxt]), T.modify(1, 0, m, p, m, 1);
	} else {
		s1-=dis(pos[v], pos[1])+dis(pos[n], pos[v]), s2-=dis(pos[v], pos[v+1])+dis(pos[m], pos[v]), pos[v]=p;
		s1+=dis(p, pos[1])+dis(pos[n], p), s2+=dis(p, pos[v+1])+dis(pos[m], p);
	}
}
inline int query() {
	if (T.ask(1, 0, m, pos[n+1])!=T.t[1]) return T.query();
	if (s1>m) return pos[n+1]%m;
	if (s2>m) return pos[n+1]-1;
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read(), m=2*n+1;
	for (int i=1; i<=m; i++) a[i]=read(), pos[a[i]]=i, s[i]=s[i-1]+(a[i]<n+1?-1:(a[i]>n+1?1:0));
	T.build(), s1=dis(pos[n+1], pos[1]), s2=dis(pos[m], pos[n+1]);
	for (int i=1; i<=n; i++) s1+=dis(pos[i], pos[i+1]);
	for (int i=n+1; i<m; i++) s2+=dis(pos[i], pos[i+1]);
	while (Q--) {
		int x=read(), y=read();
		upd(a[y], x), upd(a[x], y), swap(a[x], a[y]), printf("%d\n", query());
	}
	return 0;
}