#include<bits/stdc++.h>
#define ll long long
#define pb push_back
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
#define int long long
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
inline int read() {int x; FI(x); return x;}
const int MAXN = 3e5 + 5;
vector < int > e[MAXN]; int n, a[MAXN];
struct Line {
	int k, b; Line() {k = 0, b = -1e18;}
	Line(int K, int B) : k(K), b(B) {}
	void print() {fprintf(stderr, "k = %lld, b = %lld\n", k, b);}
};
inline int Y(Line v, int x) {
	return x * v.k + v.b;
}
struct LC_tree {
	static const int N = MAXN << 2;
	Line a[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void build(int k, int l, int r) {
		a[k].k = 0, a[k].b = -1e18;
		if(l == r) return; build(ls, l, mid), build(rs, mid+1, r);
	}
	void insert(int k, int l, int r, Line v) {
		int lv = Y(a[k], l), rv = Y(a[k], r), Lv = Y(v, l), Rv = Y(v, r);
		if(lv <= Lv && rv <= Rv) return a[k] = v, void();
		if(lv >= Lv && lv >= Rv) return;
		if(l == r) {if(Y(a[k], mid) < Y(v, mid)) swap(a[k], v); return;}
		if(Y(a[k], mid) < Y(v, mid)) swap(a[k], v);
		v.k < a[k].k ? insert(ls, l, mid, v) : insert(rs, mid+1, r, v);
	}
	int query(int k, int l, int r, int pos) {
//		cerr << pos << "??" << endl;
		if(l == r) return Y(a[k], pos);
		return max(Y(a[k], pos), pos <= mid ? query(ls, l, mid, pos) : query(rs, mid+1, r, pos));
	}
	void print(int k, int l, int r) {
		fprintf(stderr, "%lld %lld %lld\n", k, l, r); a[k].print();
		if(l != r) print(ls, l, mid), print(rs, mid+1, r);
	}
}tr;

int siz[MAXN], dep[MAXN], mxdep, vis[MAXN], ans, rt, vrt = INF;
void getroot(int u, int fa, int allsiz) {
	siz[u] = 1; int mx = -INF;
	for(auto v : e[u]) {
		if(v == fa || vis[v]) continue;
//		cerr << u << ' ' << v << endl;
		getroot(v, u, allsiz); siz[u] += siz[v];
		ckmax(mx, siz[v]);
	}
	ckmax(mx, allsiz - siz[u]);
	if(mx < vrt)
		rt = u, vrt = mx;
}
void getinfo(int u, int fa) {
	dep[u] = dep[fa] + 1, siz[u] = 1; ckmax(mxdep, dep[u]);
	for(auto v : e[u]) {
		if(v == fa || vis[v]) continue;
		getinfo(v, u); siz[u] += siz[v];
	}
}
vector < Line > q;
void solve(int u, int fa, int val, int sum, int tsum, int len, int antival, int st) {
	if(e[u].size() == 1) {
		ckmax(ans, tr.query(1, 1, mxdep, len) + val);
		ckmax(ans, val); ckmax(ans, antival + tsum);
		q.pb(Line(sum, antival));
	}
	for(auto v : e[u]) {
		if(v == fa || vis[v]) continue;
		solve(v, u, val + tsum + a[v], sum + a[v], tsum + a[v], len + 1, antival + a[v] * (dep[v] - 1), st);
	}
}
void dfs(int u, int allsiz, int dep) {
	vis[u] = 1; mxdep = 0; assert(dep <= 40);
	getinfo(u, 0); tr.build(1, 1, mxdep);
	for(auto v : e[u]) {
		if(vis[v]) continue;
		solve(v, 0, 2 * a[u] + a[v], a[v], a[u] + a[v], 2, a[v], u);
		for(auto it : q) tr.insert(1, 1, mxdep, it);
		q.clear();
	}
	reverse(e[u].begin(), e[u].end());
	tr.build(1, 1, mxdep);
	for(auto v : e[u]) {
		if(vis[v]) continue;
		solve(v, 0, 2 * a[u] + a[v], a[v], a[u] + a[v], 2, a[v], u);
		for(auto it : q) tr.insert(1, 1, mxdep, it);
		q.clear(); 
	}
	for(auto v : e[u]) {
		if(vis[v]) continue; vrt = INF;
		getroot(v, u, siz[v]); dfs(rt, siz[v], dep + 1);
	}
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
	For(i, 1, n) a[i] = read();   
	getroot(1, 0, n);
	dfs(rt, n, 0);
	cout << ans << endl;
    return FastIO::Fflush(), 0;
}
/*

*/