#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
const int P = 1e9 + 7; //
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
const int MAXN = 2e5 + 5;
ll ans = 0;
vector < int > e[MAXN];
int a[MAXN], n, m;
namespace BAS {
	int siz[MAXN], f[MAXN], dep[MAXN], id[MAXN], up[MAXN][5], ind, dfn[MAXN], top[MAXN];
    void dfs1(int u, int fa) {
		siz[u] = 1, dep[u] = dep[f[u] = fa] + 1;
		for(auto v : e[u]) if(v != f[u]) dfs1(v, u), siz[u] += siz[v];
	}
	#define upd(i) up[u][i] = up[f[up[u][i-1]]][i-1]
	void dfs2(int u, int fir) {
		int hson = 0; top[u] = up[u][0] = fir, id[dfn[u] = ++ind] = u;
		upd(1); upd(2); upd(3); upd(4);
		for(auto v : e[u]) if(v != f[u] && siz[v] > siz[hson]) hson = v;
		if(!hson) return; dfs2(hson, fir);
		for(auto v : e[u]) if(v != f[u] && v != hson) dfs2(v, v);
	}
	#define jump(i) if(up[u][i] && k > dep[u] - dep[up[u][i]]) k -= dep[u] - dep[up[u][i]] + 1, u = f[up[u][i]];
	inline int kth(int u, int k) {
		jump(4); jump(3); jump(2); jump(1); jump(0);
		return !u ? 0 : id[dfn[u] - k];
	}
	int lca(int u, int v) {
		while(top[u] != top[v])
			dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]];
		return dep[u] < dep[v] ? u : v;
	}
	inline int dist(int u, int v) {return dep[u] + dep[v] - 2 * dep[lca(u, v)];}
	
	inline int go(int u, int v, int k) {
		int l = lca(u, v);
		if(dep[u] - dep[l] < k) {
//			cerr << "?";
			return kth(v, dep[u] + dep[v] - 2 * dep[l] - k);
		} else return kth(u, k);
	}
	inline void init() {dfs1(1, 0); dfs2(1, 1);}
}
#define dist(i, j) BAS::dist(i, j)
#define lca(i, j) BAS::lca(i, j)
#define kth(u, k) BAS::kth(u, k)
#define go(u, v, k) BAS::go(u, v, k)
struct Cir {
	int v, r;
	Cir() {v = r = 0;} Cir(int u) : v(u), r(0) {}
	Cir(int V, int R) : v(V), r(R) {}
	void print() {cerr << v << ' ' << r << endl;}
};
pair < Cir, int > merge(const Cir &a, const Cir &b) {
	int d = dist(a.v, b.v);
//	cerr << a.v << ' ' << a.r << ' ' << b.v << ' ' << b.r << endl;
	if(d + b.r <= a.r) return mkp(a, 0);
	if(d + a.r <= b.r) return mkp(b, 2);
	return mkp(Cir(go(a.v, b.v, (d - a.r + b.r) / 2), (d + a.r + b.r) / 2), 1);
}
namespace DFS {
	int f[MAXN], siz[MAXN], rt, vrt, vis[MAXN], allrt;
//	vector < int > g[MAXN], h[MAXN];
	ll g[MAXN], h[MAXN], cg[MAXN], ch[MAXN];
	void getroot(int u, int fa, int allsiz) {
		siz[u] = 1; int mxval = 0;
		for(auto v : e[u]) {
			if(vis[v] || v == fa) continue;	
			getroot(v, u, allsiz); siz[u] += siz[v]; 
			ckmax(mxval, siz[v]);
		}
		ckmax(mxval, allsiz - siz[u]);
		if(vrt > mxval) rt = u, vrt = mxval;
	}
	void dfs(int u, int fa, int allsiz) {
		vis[u] = 1;
//		cerr << u << ' ' << allsiz << endl;
		for(auto v : e[u]) {
			if(vis[v] || v == fa) continue;
			int tsiz = (siz[v] < siz[u]) ? siz[v] : allsiz - siz[u]; vrt = INF, rt = 0;
			getroot(v, u, tsiz); f[rt] = u;
	//		cerr << u << ' ' << rt << endl; 
			dfs(rt, u, tsiz);
		}
	}
	void init() {
		vrt = INF; getroot(1, 0, n * 2 - 1); allrt = rt; dfs(rt, 0, n * 2 - 1);	
//		cerr << "allrt = " << allrt << endl;
	}
	
	void update(int u, int op) {
//		fprintf(stderr, "Update %d %d\n", u, op);
		int s = u, fr = -1;
		while(u) {
			int d = dist(s, u); g[u] += op * d, cg[u] += op;
			if(fr != -1) h[fr] += op * d, ch[fr] += op;
			fr = u, u = f[u];
		}
	}
	ll query(int u) {
		int s = u, fr = -1;
		ll ans = 0;
		while(u) {
			int d = dist(s, u); ans += (g[u] - h[fr]) + 1ll * (cg[u] - cg[fr]) * d;
			fr = u, u = f[u];
		}
//		assert(ans % 2 == 0);
		return ans;
	}
}
Cir val[MAXN]; int suf[MAXN]; int L, R;
void cdq(int l, int r) {
//	fprintf(stderr, "cdq : %d %d\n", l, r); 
	if(l == r) return void(); ll sum = 0;
	int mid = (l + r) >> 1; L = mid + 1, R = mid;
	val[mid + 1] = Cir(mid + 1); For(i, mid + 2, r) val[i] = merge(val[i - 1], Cir(i)).first;
	suf[r + 1] = 0; foR(i, r, mid - 1) suf[i] = suf[i + 1] + val[i].r;
	val[mid] = Cir(mid); foR(i, mid, l) {
		if(i != mid) val[i] = merge(val[i + 1], Cir(i)).first;
		int tL = mid + 1, tR = r, pos1 = mid, pos2 = r + 1;
		while(tL <= tR) {
			int tMid = (tL + tR) >> 1;
			if(merge(val[i], val[tMid]).second) tR = tMid - 1;
			else pos1 = tMid, tL = tMid + 1;
		}
		tL = mid + 1, tR = r;
		while(tL <= tR) {
			int tMid = (tL + tR) >> 1;
			if(merge(val[i], val[tMid]).second != 2) tL = tMid + 1;
			else pos2 = tMid, tR = tMid - 1;
		}
		while(L <= pos1) sum -= val[L].r, DFS::update(val[L++].v, -1);
		while(R < pos2 - 1) DFS::update(val[++R].v, 1), sum += val[R].r;
//		cerr << i << ' ' << pos1 << ' ' << pos2 << endl;
		ans += 2ll * (pos1 - mid) * merge(val[i], val[pos1]).first.r 
			+ 2ll * suf[pos2]
			+ DFS::query(val[i].v) + 1ll * (pos2 - pos1 - 1) * val[i].r + sum;
//		fprintf(stderr, "add %lld %lld %lld\n", 2ll * (pos1 - mid) * merge(val[i], val[pos1]).first.r , DFS::query(val[i].v) + 1ll * (pos2 - pos1 - 1) * val[i].r + sum, 2ll * suf[pos2]);
//		cerr << "Query " << i << ' ' << DFS::query(i) << endl;
	}
//	For(i, l, r) val[i].print();
	For(i, L, R) DFS::update(val[i].v, -1);
	cdq(l, mid), cdq(mid+1, r);
}
signed main()
{
    #ifndef ONLINE_JUDGE
		file("pro");
    #endif
	n = m = read();
	For(i, 1, n - 1) {
		int u = read(), v = read();
		e[u].pb(++m), e[v].pb(m); e[m].pb(u), e[m].pb(v);
    }
   
    BAS::init(); DFS::init(); 
//	cerr << lca(4, 1) << ' ' << go(4, 1, 1) << endl;
    cdq(1, n);
//    cerr << ans << endl;
	assert(ans % 2 == 0);
	cout << ans / 2 << endl;
	return FastIO::Fflush(), 0;
}
/*

*/