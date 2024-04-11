// LUOGU_RID: 90881167
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
const int N=2e5+7, M=5e5+7, mod=1e9+7;
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
int n, Q, ans[M], ed[N];
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
	inline void add(int p, int x) {for (; p<=s_dfn; p+=p&-p) c[p]+=x;}
	inline int ask(int p) {int res=0; for (; p; p&=p-1) res+=c[p]; return res;}
	inline int query(int l, int r) {return ask(r)-ask(l-1);}
}T;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), Q=read();
	for (int i=1; i<=n; i++) read(str+1), insert(i, str);
	for (int i=1; i<=Q; i++) {
		int l=read(), r=read(), k=read();
		vec[r].push_back({k, i, 1}), vec[l-1].push_back({k, i, -1});
	}
	build();
	for (int i=1; i<=n; i++) {
		for (int x=ed[i]; x; x=fa[x]) T.add(dfn[x], 1);
		for (auto &[k, id, op]:vec[i]) ans[id]+=op*T.query(dfn[ed[k]], low[ed[k]]);
	}
	for (int i=1; i<=Q; i++) printf("%d\n", ans[i]);
	return 0;
}