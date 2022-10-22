// LUOGU_RID: 90884445
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<23]; // '\n' for function isspace in function readstr
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?'\n':*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc(); (*s++)='\0';
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
const int N=1e5+7, mod=1e9+7;
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
int n, Q, ed[N], sz[N];
ll ans[N];
char str[N];
vector<tuple<int, int, int> >vec[N];
namespace AC {
	int tot, s_dfn, dfn[N], low[N], fail[N], fa[N], tr[N][26];
	vector<int>G[N];
	inline void insert(int id, char *s) {
		int u=0;
		for (int i=1; s[i]; i++) {
			int c=s[i]-'a';
			if (!tr[u][c]) tr[u][c]=++tot, fa[tot]=u;
			u=tr[u][c];
		}
		ed[id]=u;
	}
	void dfs(int x) {
		dfn[x]=++s_dfn;
		for (int y:G[x]) dfs(y);
		low[x]=s_dfn;
	}
	inline void build() {
		queue<int>q; for (int i=0; i<26; i++) if (tr[0][i]) q.push(tr[0][i]);
		while (!q.empty()) {
			int u=q.front(); q.pop();
			for (int i=0; i<26; i++)
				if (tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i], q.push(tr[u][i]);
				else tr[u][i]=tr[fail[u]][i];
		}
		for (int i=1; i<=tot; i++) G[fail[i]].push_back(i);
		dfs(0);
	}
} using namespace AC;
struct b1t {
	int c[N];
	inline void clear() {fill(c+1, c+s_dfn+1, 0);}
	inline void add(int p, int x) {for (; p<=s_dfn; p+=p&-p) c[p]+=x;}
	inline void modify(int l, int r, int x) {add(l, 1), add(r+1, -1);}
	inline int ask(int p) {int res=0; for (; p; p&=p-1) res+=c[p]; return res;}
	inline int query(int l, int r) {return ask(r)-ask(l-1);}
}T;
vector<tuple<int, int, int> > qry[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read(); int m=0;
	for (int i=1; i<=n; i++) read(str+1), insert(i, str), m+=sz[i]=strlen(str+1);
	int B=sqrt(m);
	for (int i=1; i<=Q; i++) {
		int l=read(), r=read(), k=read();
		if (sz[k]<=B) vec[r].push_back({k, i, 1}), vec[l-1].push_back({k, i, -1});
		else qry[k].push_back({l, r, i});
	}
	build();
	for (int i=1; i<=n; i++) {
		if (qry[i].empty()) continue;
		for (int x=ed[i]; x; x=fa[x]) T.add(dfn[x], 1);
		static ll sum[N];
		for (int j=1; j<=n; j++) sum[j]=sum[j-1]+T.query(dfn[ed[j]], low[ed[j]]);
		for (auto &[l, r, id]:qry[i]) ans[id]=sum[r]-sum[l-1];
		T.clear();
	}
	for (int i=1; i<=n; i++) {
		T.modify(dfn[ed[i]], low[ed[i]], 1);
		for (auto &[k, id, op]:vec[i])
			for (int x=ed[k]; x; x=fa[x]) ans[id]+=op*T.ask(dfn[x]);
	}
	for (int i=1; i<=Q; i++) printf("%lld\n", ans[i]);
	return 0;
}