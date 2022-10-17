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
const int MAXN = 6e5 + 5;
mt19937 rnd(20181003);
ull random() {
	return (((1ull * rnd()) << 31ull) + rnd());	
}
vector < int > e[MAXN];
int n, a[MAXN], rt[MAXN], q; ull val[MAXN];
struct SMT {
	static const int N = MAXN * 20;
	int c[N][2], tot; ull t[N];
	#define ls c[p][0]
	#define rs c[p][1]
	#define mid ((l + r) >> 1)
	void build(int &p, int l, int r) {
		p = ++tot; if(l == r) return t[p] = 0, void();
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void insert(int &p, int q, int l, int r, int pos, ull val) {
		if(!p) p = ++tot; if(l == r) return t[p] = t[q] ^ val, void();
		if(pos <= mid) insert(ls, c[q][0], l, mid, pos, val), rs = c[q][1];
		else insert(rs, c[q][1], mid + 1, r, pos, val), ls = c[q][0];
		t[p] = t[ls] ^ t[rs];
	}
	int qry(int A, int B, int C, int D, int l, int r, int ql, int qr) {
//		cerr << A << ' ' << B << ' ' << C << ' ' << D << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		if(r < ql || qr < l) return -1;
		if(ql <= l && r <= qr) {
			if(l == r) return (t[A] ^ t[B] ^ t[C] ^ t[D]) ? l : -1;
			if(t[c[A][0]] ^ t[c[B][0]] ^ t[c[C][0]] ^ t[c[D][0]]) return qry(c[A][0], c[B][0], c[C][0], c[D][0], l, mid, ql, mid);
			return qry(c[A][1], c[B][1], c[C][1], c[D][1], mid + 1, r, mid + 1, qr);
		}
		int al = qry(c[A][0], c[B][0], c[C][0], c[D][0], l, mid, ql, qr); if(al != -1) return al;
		else return qry(c[A][1], c[B][1], c[C][1], c[D][1], mid + 1, r, ql, qr);
	}
}tr;
int top[MAXN], dep[MAXN], f[MAXN], siz[MAXN];
void dfs1(int u, int fa) {
//	cerr << u << endl;
	tr.insert(rt[u], rt[fa], 1, n, a[u], val[a[u]]);
	dep[u] = dep[fa] + 1, siz[u] = 1, f[u] = fa;
	for(auto v : e[u]) {
		if(v == fa) continue; dfs1(v, u); siz[u] += siz[v];
	}
}
void dfs2(int u, int fir) {
//	cerr << u << endl;
	top[u] = fir; int hson = 0;
	for(auto v : e[u])
		if(v != f[u] && siz[v] > siz[hson]) hson = v;
	if(!hson) return;
	dfs2(hson, fir);
	for(auto v : e[u]) {
		if(v != f[u] && v != hson) dfs2(v, v);
	}
}
inline int lca(int u, int v) {
	while(top[u] != top[v])
		dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]];
	return dep[u] < dep[v] ? u : v;
}

signed main()
{ 
	#ifndef ONLINE_JUDGE
        file("pro");
    #endif
	n = read(), q = read();
	For(i, 1, n) a[i] = read();
	For(i, 1, n) val[i] = random();
//    cerr << val[1] << endl; 
	For(i, 1, n - 1) {
		int u = read(), v = read();
		e[u].pb(v), e[v].pb(u);
	}
	tr.build(rt[0], 1, n); dfs1(1, 0); dfs2(1, 1);
//	cerr  << "?"; 
	while(q--) {
		int u = read(), v = read(), l = read(), r = read(), lc = lca(u, v), fa = f[lc];
		printf("%d\n", tr.qry(rt[u], rt[v], rt[lc], rt[fa], 1, n, l, r));
	}
    return FastIO::Fflush(), 0;
}
/*


*/