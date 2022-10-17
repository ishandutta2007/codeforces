#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
const int MAXN = 5e5 + 5;
int n, m, ans[MAXN], cnt = 0, ik[MAXN];
struct Edge {
	int u, v, w, id;
	bool operator < (const Edge b) const {return w < b.w;}
}g[MAXN];
struct Vedge {
	int v, w, id;
};
vector < Vedge > e[MAXN];
struct DSU {
	int f[MAXN];
	DSU() {For(i, 0, MAXN-5) f[i] = i;}
	inline int find(int x) {
		while(x != f[x]) x = f[x] = f[f[x]];
		return x;
	}
	inline int merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if(fx == fy) return 0; f[fx] = fy; return 1;
	}
}dsu1, dsu2;
int f[MAXN][19], mx[MAXN][19], dep[MAXN], id[MAXN];
void dfs1(int u, int fa, int fr1, int fr2) {
	dep[u] = dep[fa] + 1, f[u][0] = fa, mx[u][0] = fr1, id[u] = fr2;
	For(i, 1, 18) f[u][i] = f[f[u][i-1]][i-1], mx[u][i] = max(mx[f[u][i-1]][i-1], mx[u][i-1]);
	for(auto t : e[u])
		if(t.v != fa) dfs1(t.v, u, t.w, t.id);
}
Pair lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v); int res = 0 ;
	foR(i, 18, 0) if(dep[f[u][i]] >= dep[v]) ckmax(res, mx[u][i]), u = f[u][i];
	if(u == v) return mkp(u, res);
	foR(i, 18, 0) if(f[u][i] != f[v][i]) {
		ckmax(res, mx[u][i]); ckmax(res, mx[v][i]);
		u = f[u][i], v = f[v][i];
	}
	ckmax(res, mx[u][0]), ckmax(res, mx[v][0]);
	return mkp(f[u][0], res);
}
void merge(int u, int l, int x) {
	int t;
	while(dep[t = dsu2.find(u)] > dep[l]) {
//		cerr << u << ' ' << t << endl;
		ans[id[t]] = x; dsu2.merge(t, dsu2.find(f[t][0])); u = f[t][0];
	}
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n), FI(m);
    For(i, 1, m)
    	FI(g[i].u), FI(g[i].v), FI(g[i].w), g[i].id = i;
	sort(g + 1, g + 1 + m);
	For(i, 1, m) {
		if(dsu1.merge(g[i].u, g[i].v)) {
//			cerr << g[i].u << ' ' << g[i].v << ' ' << i << endl;
			e[g[i].u].pb((Vedge) {g[i].v, g[i].w, g[i].id});
			e[g[i].v].pb((Vedge) {g[i].u, g[i].w, g[i].id});
			ik[i] = 1;
		}
	}
	dfs1(1, 0, 0, 0);
//	cerr << "?";
	For(i, 1, m) {
		if(!ik[i]) {
			int u = g[i].u, v = g[i].v; Pair l = lca(u, v);
//			cerr << u << ' ' << v << ' ' << l.first << endl;
			
			ans[g[i].id] = l.second; merge(u, l.first, g[i].w), merge(v, l.first, g[i].w);
		}
	}
	
	For(i, 1, m)
		printf("%d ", ans[i] - 1);
	
//	For(i, 1, m)
//		if(!ik[i]) h[++cnt] = i;
	
    return FastIO::Fflush(), 0;
}
/*
Think twice!
 
*/