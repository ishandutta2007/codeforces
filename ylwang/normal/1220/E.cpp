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
#define int long long
const int P = 998244353; //
using namespace std;
template <typename T> inline void ckmax(T &a, T b) {(a < b) && (a = b);}
template <typename T> inline void ckmin(T &a, T b) {(a > b) && (a = b);}
inline int mul(int a, int b) {return 1ll * a * b % P;}
inline int add(int a, int b) {return a + b >= P ? a + b - P : a + b;}
inline int sub(int a, int b) {return a - b >= 0 ? a - b : a - b + P;}
inline void mulmod(int &a, int b) {a = mul(a, b);}
inline void addmod(int &a, int b) {((a += b) >= P) && (a -= P);}
inline void submod(int &a, int b) {((a -= b) < 0) && (a += P);}
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
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
inline int read() {int x; FI(x); return x;}
const int MAXN = 5e5 + 5;
int n, a[MAXN], m;
struct DSU {
	int f[MAXN];
	void init() {For(i, 0, MAXN-5) f[i] = i;}
	int find(int u) {
		while(u != f[u]) u = f[u] = f[f[u]];
		return f[u];
	}
	void merge(int u, int v) {
		u = find(u), v = find(v); if(u != v) f[u] = v;	
	}
}d;
struct NG {
	int siz[MAXN], f[MAXN], used[MAXN], Fa[MAXN], ans;
	vector < int > e[MAXN];
	void dfs1(int u, int fa) {
//		cerr << u << ' ' << fa << endl;
		Fa[u] = fa;
		if(siz[u] > 1) {
			int tu = u; while(!used[tu]) used[tu] = 1, ans += a[tu], tu = Fa[tu];
		}
		for(auto v : e[u]) {
			if(v == fa) continue; dfs1(v, u);
		}
	}
	void dfs2(int u, int fa) {
//		cerr << u << ' ' << fa << endl;
		f[u] = !used[u] ? a[u] : 0; int t =0;
		for(auto v : e[u]) {
			if(v == fa) continue;
//			cerr << "?" << ' ' << u << ' ' << v << endl;
			dfs2(v, u); ckmax(t, f[v]);
//			cerr << u << ' ' << t << ' ' << f[v] << endl; 
		}
		f[u] += t;
	}
	void solve() {
//		For(i, 1, n) if(siz[i]) cerr << a[i] << ' ' << siz[i] << endl;
		int s; dfs1(s = d.find(read()), 0); 
//		cerr << ans << endl;
		
		dfs2(s, 0); 
//		For(i, 1, n)  cerr << used[i] << ' ' << f[i] << endl;
		printf("%lld\n", ans + f[s]);
	}
}ng;
struct IG {
	vector < int > e[MAXN];	
	int vis[MAXN], f[MAXN], dep[MAXN];
	void dfs(int u, int fa) {
		vis[u] = 1, f[u] = fa, dep[u] = dep[fa] + 1;
		for(auto v : e[u]) {
			if(v == fa) continue;
//			cerr << u << ' ' << v << endl;
			if(!vis[v]) dfs(v, u);
			else {
//				cerr << "!" << ' ' << u << ' ' << v << endl;
				int tu = u, tv = v; if(dep[tu] < dep[tv]) continue;
				while(d.find(tu) != d.find(tv)) {
					int tmp = tu; tu = f[d.find(tu)];
					d.merge(tmp, tu); 
//					tu = f[d.find(tu)];
				}
				
			}
		}
	}
	map < pii, int > used;
	void solve() {
		For(i, 1, m) {
			int u = read(), v = read();
			e[u].pb(v), e[v].pb(u);	
		}
		dfs(1, 0);
//		For(i, 1, n) {
//			fprintf(stderr, "%d ", d.find(i));	
//		}
//		fprintf(stderr, "\n");
		For(u, 1, n) {
			ng.siz[d.find(u)]++; if(u != d.find(u)) a[d.find(u)] += a[u];
//			cerr << "?";
			for(auto v : e[u]) { int tu = d.find(u), tv = d.find(v);
				if(tu != tv && !used[mkp(min(tu, tv), max(tu, tv))]) ng.e[tu].pb(tv), ng.e[tv].pb(tu), used[mkp(min(tu, tv), max(tu, tv))] = 1;
			}
		}
	}
}ig;
signed main() 
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	n = read(), m = read(); For(i, 1, n) a[i] = read();
	d.init(), ig.solve(); ng.solve();
    return FastIO::Fflush(), 0;
}
/*

*/