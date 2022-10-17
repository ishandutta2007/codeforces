#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair 
#define si set < int >
#define vi vector < int > 
#define pii pair < int, int > 
#define mii map < int, int >
#define p_q priority_queue
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a, b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
//#define int long long
const int P = 998244353; //
using namespace std;
template <typename T> inline void ckmax(T &a, T b) {(a < b) && (a = b);}
template <typename T> inline void ckmin(T &a, T b) {(a > b) && (a = b);}
inline int mul(int &a, int &b) {return 1ll * a * b % P;}
inline int add(int &a, int &b) {return a + b >= P ? a + b - P : a + b;}
inline int sub(int &a, int &b) {return a - b >= 0 ? a - b : a - b + P;}
inline void mulmod(int &a, int &b) {a = mul(a, b);}
inline void addmod(int &a, int &b) {((a += b) >= P) && (a -= P);}
inline void submod(int &a, int &b) {((a -= b) < P) && (a += P);}
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read_str(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    template <typename T> bool read(T& x) {if(x)x=0;int bf=0,n=read_str(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    template <typename T> void write(T x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write_char(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 2e5 + 5;
int dis[MAXN], n, p[MAXN], flg[MAXN];
vector < int > e[MAXN]; int ans[MAXN];
namespace BAS {
	int dep[MAXN], f[MAXN], top[MAXN], siz[MAXN];
	void dfs1(int u, int fa) {
		siz[u] = 1, dep[u] = dep[fa] + 1, f[u] = fa;
		for(auto v : e[u]) {
			if(v == fa) continue;
			dfs1(v, u); siz[u] += siz[v];
		}
	}
	void dfs2(int u, int fir) {
		top[u] = fir; int hson = 0;
		for(auto v : e[u]) if(v != f[u] && siz[hson] < siz[v]) hson = v; 
		if(!hson) return; dfs2(hson, fir);
		for(auto v : e[u]) if(v != f[u] && v != hson) dfs2(v, v);
	}
	inline int lca(int u, int v) {
		while(top[u] != top[v]) 
			dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]];
		return dep[u] < dep[v] ? u : v;
	}
	inline int dist(int u, int v) {return dep[u] + dep[v] - 2 * dep[lca(u, v)];}    
	inline void init() {dfs1(1, 0); dfs2(1, 1);}
}
#define dist(u, v) BAS::dist(u, v)
void bfs() {
	queue < int > q; int k = read(); mst(dis, -1);
	For(i, 1, k) {
		int x = read(); q.push(x); dis[x] = 0;
//		cerr << "?";
	}
	while(q.size()) {
		int u = q.front(); q.pop();for(auto v : e[u]) {
//			cerr << '?' << ' ' << u << ' ' << v << endl;
			if(dis[v] == -1) dis[v] = dis[u] + 1, q.push(v);
		}
	}
//	cerr << dis[3] << endl;
}
int siz[MAXN], vis[MAXN], rt, vrt, f[MAXN];
void getroot(int u, int fa, int allsiz) {
	siz[u] = 1; int mx = 0;
	for(auto v : e[u]) {
		if(v == fa || vis[v]) continue;
		getroot(v, u, allsiz); siz[u] += siz[v]; ckmax(mx, siz[v]);
	}
	ckmax(mx, allsiz - siz[u]);
	if(mx < vrt)
		vrt = mx, rt = u;	
}
vector < int > t[MAXN]; vi sufmx[MAXN];
void dfs(int u, int allsiz) {
	vis[u] = 1, t[u].pb(u);
	for(auto v : e[u]) {
		if(vis[v]) continue;
		int tsiz = (siz[v] < siz[u]) ? siz[v] : (allsiz - siz[u]); vrt = rt = INF;
		getroot(v, u, tsiz); f[rt] = u; int tv = rt; dfs(tv, tsiz); 
//		cerr << u << ' ' << tv << endl;
		for(auto it : t[tv]) t[u].pb(it);
	}
	sufmx[u].resize(t[u].size());
}
 
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
	n = read();
	For(i, 1, n - 1) {
		int u = read(), v = read();
		e[u].pb(v), e[v].pb(u);	
	}
	bfs();
//	cerr << "?"; 
//	For(i, 1, n) cerr << dis[i] << endl;
	BAS::init();  vrt = rt = INF; getroot(1, 0, n); dfs(rt, n);
//	For(i, 1, n) {
//		cerr << i << ": ";
//		for(auto j : t[i]) {
//			cerr << j.second << ' ';
//		}
//		cerr << endl;
//	}
	For(i, 1, n) {
//		cerr << dis[i] << endl;
//		cerr << i << ":\n";
		for(int u = i; u; u = f[u]) {
			int d = dist(u, i); 
//			cerr << u << ' ' << dis[i] - d - 1 << endl;
//			cerr << i << ' ' << u << ' ' << d << endl;
			if(dis[i] > d) ckmax(sufmx[u][min((int)sufmx[u].size() - 1, dis[i] - d - 1)], dis[i]);
		}
//		cerr << endl;
	}
	
	For(i, 1, n) {
		assert(t[i].size() == sufmx[i].size());
		for(int j = (int)t[i].size() - 2; j >= 0; j--) {
			ckmax(sufmx[i][j], sufmx[i][j + 1]); 
//			cerr << i << ' ' << j << ' ' << sufmx[i][j] << endl;
		}
		for(auto it : t[i]) {
			int u = it, d = dist(u, i); 
//			cerr << u << ' ' << d << endl;
			ckmax(ans[u], sufmx[i][d]);
		}
	}
	For(i, 1, n) {
//		cerr << ans[i] << endl;
		printf("%d ", ans[i]);
	}
    return FastIO::Fflush(), 0;
}
/*
 
*/