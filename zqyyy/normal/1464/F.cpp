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
int n, Q, s_dfn, dfn[N], low[N], dep[N], id[N], anc[N][18];
vector<int> G[N];
void dfs(int x, int fa) {
	anc[x][0]=fa, dfn[x]=++s_dfn, dep[x]=dep[fa]+1, id[s_dfn]=x;
	for (int i=1; i<=17; i++) anc[x][i]=anc[anc[x][i-1]][i-1];
	for (int &y:G[x]) if (y^fa) dfs(y, x); low[x]=s_dfn;
}
inline int LCA(int x, int y) {
	if (x==y) return x; if (dfn[x]>dfn[y]) swap(x, y);
	for (int i=17; ~i; i--) if (dfn[anc[y][i]]>dfn[x]) y=anc[y][i];
	return anc[y][0];
}
inline int dist(int x, int y) {return dep[x]+dep[y]-(dep[LCA(x, y)]<<1);}
inline int gf(int x, int k) {
	if (dep[x]<=k) return 1;
	while (k) x=anc[x][__builtin_ctz(k)], k&=k-1;
	return x;
}
struct b1t {
	int c[N];
	inline void add(int p, int x) {for (; p<=n; p+=p&-p) c[p]+=x;}
	inline int ask(int p) {int res=0; for (; p; p&=p-1) res+=c[p]; return res;}
	inline int query(int l, int r) {return ask(r)-ask(l-1);}
}T;
namespace sgt {
	using node=array<int, 3>;
	node t[N<<2];
	node operator +(const node a, const node b) {
		if (!a[0]) return b; if (!b[0]) return a;
		node c=a[2]>b[2]?a:b;
		for (int x:{a[0], a[1]})
			for (int y:{b[0], b[1]}) {
				int d=dist(x, y);
				if (d>c[2]) c[2]=d, c[0]=x, c[1]=y;
			}
		return c;
	}
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p) {t[p]=t[ls]+t[rs];}
	void build(int p, int l, int r) {
		t[p]={0, 0, -1}; if (l==r) return;
		int mid=(l+r)>>1; build(ls, l, mid), build(rs, mid+1, r);
	}
	void modify(int p, int l, int r, int x, int v) {
		if (l==r) {if (v==1) t[p]={id[l], id[l], 0}; else t[p]={0, 0, -1}; return;}
		int mid=(l+r)>>1; x<=mid?modify(ls, l, mid, x, v):modify(rs, mid+1, r, x, v); upd(p);
	}
	node query(int p, int l, int r, int x, int y) {
		if (x<=l && r<=y) return t[p]; int mid=(l+r)>>1; if (y<=mid) return query(ls, l, mid, x, y);
		if (x>mid) return query(rs, mid+1, r, x ,y); return query(ls, l, mid, x, y)+query(rs, mid+1, r, x, y);
	}
#undef ls
#undef rs
}
struct cmp {
	bool operator ()(const int &x, const int &y) const {
		return dep[x]^dep[y]?dep[x]<dep[y]:x<y;
	}
};
int num, cnt[N];
set<int, cmp>s;
inline bool query(int d) {
	int x=*s.rbegin(), y=gf(x, d), z=gf(y, d);
	if (T.query(dfn[z], low[z])<num) return false;
	auto t=sgt::query(1, 1, n, dfn[z], low[z]);
	return dist(t[0], y)<=d && dist(t[1], y)<=d;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<n; i++) {
		int x=read(), y=read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	while (Q--) {
		int opt=read();
		if (opt==3) puts(query(read())?"Yes":"No");
		else {
			int x=read(), y=read(), lca=LCA(x, y);
			if (opt==1) {
				if (!cnt[lca]++) s.insert(lca), sgt::modify(1, 1, n, dfn[lca], 1);
				T.add(dfn[x], 1), T.add(dfn[y], 1), T.add(dfn[lca], -1), num++;
			} else {
				if (!--cnt[lca]) s.erase(lca), sgt::modify(1, 1, n, dfn[lca], -1);
				T.add(dfn[x], -1), T.add(dfn[y], -1), T.add(dfn[lca], 1), num--;
			}
		}
	}
	return 0;
}