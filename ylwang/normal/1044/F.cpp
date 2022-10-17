#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
//#define int long long
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}

inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 2e5 + 5;
int n, m, Q, f[MAXN], siz[MAXN], dep[MAXN], top[MAXN], dfn[MAXN], up[MAXN][5], id[MAXN], ind = 0;
vector < int > e[MAXN];

void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1, f[u] = fa, siz[u] = 1;
	for(auto v : e[u]) {
		if(v == fa) continue;
		dfs1(v, u), siz[u] += siz[v];
	}
}
void dfs2(int u, int fir) {
	top[u] = fir, id[dfn[u] = ++ind] = u; up[u][0] = fir; int hson = 0;
	up[u][1] = up[f[up[u][0]]][0], up[u][2] = up[f[up[u][1]]][1], up[u][3] = up[f[up[u][2]]][2], up[u][4] = up[f[up[u][3]]][3];
	for(auto v : e[u]) {
		if(v != f[u] && (!hson || siz[v] > siz[hson])) hson = v;
	}
	if(!hson) return;
	dfs2(hson, fir);
	for(auto v : e[u]) {
		if(v != hson && v != f[u]) dfs2(v, v);
	}
}
inline int kth(int u, int k) {
	if(up[u][4] && k > dep[u] - dep[up[u][4]]) k -= dep[u] - dep[up[u][4]] + 1, u = f[up[u][4]];
	if(up[u][3] && k > dep[u] - dep[up[u][3]]) k -= dep[u] - dep[up[u][3]] + 1, u = f[up[u][3]];
	if(up[u][2] && k > dep[u] - dep[up[u][2]]) k -= dep[u] - dep[up[u][2]] + 1, u = f[up[u][2]];
	if(up[u][1] && k > dep[u] - dep[up[u][1]]) k -= dep[u] - dep[up[u][1]] + 1, u = f[up[u][1]];
	if(up[u][0] && k > dep[u] - dep[up[u][0]]) k -= dep[u] - dep[up[u][0]] + 1, u = f[up[u][0]];
	assert(u); return id[dfn[u] - k];
}
struct Segment_tree {
	static const int N = MAXN << 2;
	int mn[N], cnt[N], tag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	inline void pushr(int k, int v) {tag[k] += v, mn[k] += v;}
	inline void pushdown(int k) {
		if(tag[k]) {
			pushr(ls, tag[k]), pushr(rs, tag[k]);
			tag[k] = 0;
		}
	}
	inline void pushup(int k) {
		mn[k] = min(mn[ls], mn[rs]), cnt[k] = cnt[ls] * (mn[ls] <= mn[rs]) + cnt[rs] * (mn[rs] <= mn[ls]);
	}
	void build(int k, int l, int r) {
		mn[k] = tag[k] = 0, cnt[k] = r - l + 1;
		if(l == r) return;
		build(ls, l, mid), build(rs, mid+1, r);
	}
	void update(int k, int l, int r, int ql, int qr, int val) {
		if(l == ql && r == qr) return pushr(k, val);
		pushdown(k);
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);
		pushup(k);
	}
}tr;
inline int lca(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = f[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	return x;
}
map < Pair, int > o;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n), FI(Q);
    For(i, 1, n - 1) {
    	int u, v; FI(u), FI(v);
    	e[u].pb(v), e[v].pb(u);
	}
	dfs1(1, 0), dfs2(1, 1); tr.build(1, 1, n);
	while(Q--) {
		int u, v; FI(u), FI(v); if(dfn[u] > dfn[v]) swap(u, v); int t = o[mkp(u, v)] ? -1 : 1, x = lca(u, v);
		if(x == u) {
			int z = kth(v, dep[v] - dep[x] - 1);
//			cerr << x << ' ' << v << ' ' << z << endl;
			tr.update(1, 1, n, dfn[z], dfn[z] + siz[z] - 1, t);
			tr.update(1, 1, n, dfn[v], dfn[v] + siz[v] - 1, -t);
		}
		else {
			tr.pushr(1, t);
			tr.update(1, 1, n, dfn[u], dfn[u] + siz[u] - 1, -t);
			tr.update(1, 1, n, dfn[v], dfn[v] + siz[v] - 1, -t);
		}
//		assert(u < v);
		o[mkp(u, v)] ^= 1; printf("%d\n", tr.mn[1] != 0 ? 0 : tr.cnt[1]);
	}
    return FastIO::Fflush(), 0;
}
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?

*/