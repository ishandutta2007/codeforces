#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
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
    void write(ll x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
#define upd(i) up[u][i] = up[f[up[u][i-1]]][i-1]
#define jump(i) if(up[u][i] && k > dep[u] - dep[up[u][i]]) k -= dep[u] - dep[up[u][i]] + 1, u = f[up[u][i]];
const int MAXN = 4e5 + 5;
vector < int > e[MAXN]; int tot = 0;
inline void addedge(int u, int v) {
	tot++; e[u].pb(tot); e[tot].pb(u);
	e[tot].pb(v); e[v].pb(tot);
}
int siz[MAXN], f[MAXN], dep[MAXN], id[MAXN], up[MAXN][5], ind, dfn[MAXN], top[MAXN];
void dfs1(int u, int fa) {
	siz[u] = 1, dep[u] = dep[f[u] = fa] + 1;
	for(auto v : e[u]) if(v != f[u]) dfs1(v, u), siz[u] += siz[v];
}
void dfs2(int u, int fir) {
	int hson = 0; top[u] = up[u][0] = fir, id[dfn[u] = ++ind] = u;
	upd(1); upd(2); upd(3); upd(4);
	for(auto v : e[u]) if(v != f[u] && siz[v] > siz[hson]) hson = v;
	if(!hson) return; dfs2(hson, fir);
	for(auto v : e[u]) if(v != f[u] && v != hson) dfs2(v, v);
}
inline int kth(int u, int k) {
	jump(4); jump(3); jump(2); jump(1); jump(0);
	return !u ? 0 : id[dfn[u] - k];
}
int lca(int u, int v) {
	while(top[u] != top[v]) dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]];
	return dep[u] < dep[v] ? u : v;
}
int dist(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
#undef upd
#undef jump
int n, k, m, key[MAXN], ik[MAXN];
struct DSU {
	int f[MAXN];
	DSU() {For(i, 1, MAXN - 5) f[i] = i;}
	inline int find(int x) {
		while(x != f[x]) x = f[x] = f[f[x]];
		return x;
	}
	inline int merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return 0; f[y] = x; return 1;
	}
}d;
queue < Pair > q; int used[MAXN];
void bfs() {
	For(i, 1, m) q.push(mkp(key[i], 0));
	while(q.size()) {
		int u = q.front().first, s = q.front().second; q.pop();
		if(s == k) continue;
		for(auto v : e[u]) {
			d.merge(u, v);
			if(!used[v]) used[v] = 1, q.push(mkp(v, s + 1));
		} 
	}
}
bool query(int u, int v) {
	int l = lca(u, v);
	if(dep[u] + dep[v] - 2 * dep[l] <= 2 * k) return 1;
	u = dep[u] - dep[l] < k ? kth(v, dep[v] - (k - dep[u] + 2 * dep[l])) : kth(u, k);
	v = dep[v] - dep[l] < k ? kth(u, dep[u] - (k - dep[v] + 2 * dep[l])) : kth(v, k);
//	cerr << u << ' ' << v << endl;
	return d.find(u) == d.find(v);
	
}
signed main()
{
	#ifndef ONLINE_JUDGE 
    	file("pro");
    #endif
    n = read(), k = read(), m = read(); tot = n;
    For(i, 1, n - 1) {
    	int u = read(), v = read();
    	addedge(u, v);
	}
//	cerr << tot << endl;
	For(i, 1, m) ik[key[i] = read()] = 1;
	dfs1(1, 0), dfs2(1, 1);
	bfs();
//	For(i, 1, tot) cerr << d.find(i) << endl;
	int Qnum = read();
	while(Qnum--) {
		int u = read(), v = read();
		printf(query(u, v) ? "YES\n" : "NO\n");
	}
    return FastIO::Fflush(), 0;
}
/*

*/