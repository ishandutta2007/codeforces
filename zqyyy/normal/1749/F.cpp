#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use in interactive problems!!!
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, m, dep[N], s_dfn, fa[N], dfn[N], top[N], sz[N], son[N];
vector<int>G[N];
void dfs1(int x) {
	dep[x]=dep[fa[x]]+1, sz[x]=1;
	for (int y:G[x]) {
		if (y==fa[x]) continue;
		fa[y]=x, dfs1(y), sz[x]+=sz[y];
		if (sz[son[x]]<sz[y]) son[x]=y;
	}
}
void dfs2(int x, int tf) {
	dfn[x]=++s_dfn, top[x]=tf;
	if (!son[x]) return; dfs2(son[x], tf);
	for (int y:G[x]) if (y!=fa[x] && y!=son[x]) dfs2(y, y);
}
struct b1t {
	int c[N];
	inline void add(int p, int x) {for (; p<=n; p+=p&-p) c[p]+=x;}
	inline void modify(int x, int v) {add(x, v), add(x+1, -v);}
	inline void modify(int l, int r, int v) {add(l, v), add(r+1, -v);}
	inline int ask(int p) {int res=0; for (; p; p&=p-1) res+=c[p]; return res;}
} T[21];
inline void work() {
	n=read();
	for (int i=1; i<n; i++) {
		int x=read(), y=read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs1(1), dfs2(1, 1), m=read();
	while (m--) {
		int opt=read();
		if (opt==1) {
			int x=read(), ans=0;
			for (int d=0; d<=20 && x; d++, x=fa[x])
				ans+=T[d].ask(dfn[x]);
			printf("%d\n", ans);
		} else {
			int x=read(), y=read(), v=read(), d=read();
			while (top[x]^top[y]) {
				if (dep[top[x]]>dep[top[y]]) swap(x, y);
				T[d].modify(dfn[top[y]], dfn[y], v), y=fa[top[y]];
			}
			if (dep[x]>dep[y]) swap(x, y);
			if (x^y) T[d].modify(dfn[x]+1, dfn[y], v);
			while (true) {
				if (x==1) {
					for (int i=0; i<=d; i++) T[i].modify(1, v);
					break;
				}
				T[d].modify(dfn[x], v); if (!d) break;
				T[--d].modify(dfn[x], v), x=fa[x];
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=1; //read();
	while (test--) work();
	return 0;
}