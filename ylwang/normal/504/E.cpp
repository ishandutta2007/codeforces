#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
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
const int P1 = 469762049, P2 = 1000000007;
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int ksm(int a, int b, int P) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
 
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
struct Node {
    int x, y;
    Node operator + (const Node &b) {return (Node) {(x + b.x) % P1, (y + b.y) % P2};}
    Node operator + (const int &b) {return (Node) {(x + b) % P1, (y + b) % P2};}
    Node operator - (const Node &b) {return (Node) {(x - b.x + P1) % P1, (y - b.y + P2) % P2};}
    Node operator - (const int &b) {return (Node) {(x - b + P1) % P1, (y - b + P2) % P2};}
    Node operator * (const Node &b) {return (Node) {1ll * x * b.x % P1, 1ll * y * b.y % P2};}
    Node operator * (const int &b) {return (Node) {1ll * x * b % P1, 1ll * y * b % P2};}
    Node inv() {return (Node) {ksm(x, P1-2, P1), ksm(y, P2-2, P2)};}
    bool operator == (const Node &b) const {return x == b.x && y == b.y;}
    void print() {fprintf(stderr, "%d %d\n", x, y);}
};
const Node BASE = (Node) {131, 131};
const int MAXN = 6e5 + 5;
char s[MAXN];
vector < int > e[MAXN];
int n, siz[MAXN], f[MAXN], top[MAXN], dep[MAXN], Qnum, id[MAXN], up[MAXN][5], ind, dfn[MAXN]; 
Node ori[MAXN], rev[MAXN], pw[MAXN], ipw[MAXN];

void dfs1(int u, int fa) {
	siz[u] = 1, f[u] = fa, dep[u] = dep[fa] + 1;
	ori[u] = ori[fa] * BASE + (s[u] - 'a'), rev[u] = rev[fa] + pw[dep[u] - 1] * (s[u] - 'a');
	for(auto v : e[u]) {
		if(v == fa) continue;
		dfs1(v, u); siz[u] += siz[v];
	}
}
void dfs2(int u, int fir) {
//	cerr << u << ' ' << fir << endl;
	int hson = -1; up[u][0] = top[u] = fir, id[++ind] = u, dfn[u] = ind;
	up[u][1] = up[f[up[u][0]]][0], up[u][2] = up[f[up[u][1]]][1], up[u][3] = up[f[up[u][2]]][2], up[u][4] = up[f[up[u][3]]][3];
	for(auto v : e[u]) {
		if(v == f[u]) continue;
		if(hson == -1 || siz[v] > siz[hson]) hson = v;
	}
	if(hson == -1) return;
	dfs2(hson, fir);
	for(auto v : e[u]) {
		if(v == f[u] || v == hson) continue;
		dfs2(v, v);
	}
}
inline int lca(int u, int v) {
//	cerr << u << ' ' << v << endl;
	while(top[u] != top[v])
		dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]];
	return dep[u] < dep[v] ? u : v;
}
int bfk(int u, int k) {
	while(k--) u = f[u];
	return u;
}
inline int kth(int u, int k) {
	
	if(k < 0) return -1;
//	int tk = bfk(u, k);
	if(up[u][4] && k > dep[u] - dep[up[u][4]]) k -= dep[u] - dep[up[u][4]] + 1, u = f[up[u][4]];
	if(up[u][3] && k > dep[u] - dep[up[u][3]]) k -= dep[u] - dep[up[u][3]] + 1, u = f[up[u][3]];
	if(up[u][2] && k > dep[u] - dep[up[u][2]]) k -= dep[u] - dep[up[u][2]] + 1, u = f[up[u][2]];
	if(up[u][1] && k > dep[u] - dep[up[u][1]]) k -= dep[u] - dep[up[u][1]] + 1, u = f[up[u][1]];
	if(up[u][0] && k > dep[u] - dep[up[u][0]]) k -= dep[u] - dep[up[u][0]] + 1, u = f[up[u][0]];
//	while(up[u] && k >= dep[u] - dep[up[u]] + 1) k -= dep[u] - dep[up[u]] + 1, u = f[up[u]];
//	while(u && k >= dep[u] - dep[top[u]] + 1) k -= dep[u] - dep[top[u]] + 1, u = f[top[u]];
//	assert( !u ? 0 : id[dfn[u] - k] == tk);
	return !u ? 0 : id[dfn[u] - k];
}
inline Node geto(int l, int x) {
	if(l == -1) return (Node) {0, 0};
	return ori[x] - ori[f[l]] * pw[dep[x] - dep[f[l]]];
}
inline Node getr(int l, int x) {
	if(l == -1) return (Node) {0, 0};
//	cerr << l << ' ' << x << ' ' << dep[f[l]] << endl; 
//	rev[f[l]].print(), rev[x].print(); ipw[dep[f[l]]].print(); pw[dep[f[l]]].print();
//	ipw[dep[f[l]]].print(); (rev[x] - rev[f[l]]).print();
	return (rev[x] - rev[f[l]]) * ipw[dep[f[l]]];
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(s + 1);
    pw[0] = (Node) {1, 1}; ipw[0] = (Node) {1, 1}; For(i, 1, n) pw[i] = pw[i-1] * BASE, ipw[i] = pw[i].inv();
    For(i, 1, n - 1) {
    	int u, v; FI(u), FI(v);
    	e[u].pb(v), e[v].pb(u);
	}
	dfs1(1, 0); dfs2(1, 1);
//	For(i, 1, n) assert(top[i] == i);
//	For(i, 1, n) up[i] = top[f[top[f[top[f[top[i]]]]]]];
	
	FI(Qnum);
//	cerr << "?";
//	For(i, 1, n) For(j, 1, 5) {
//		cerr << i << ' ' << j << ' ' << kth(i, j) << endl;
//	}
	For(Q, 1, Qnum) {
//		fprintf(stderr, "Query %d : \n", Q);
		int x, y, l, r; FI(x), FI(y), FI(l), FI(r);
		int l1 = lca(x, y), l2 = lca(l, r);
//		int l1 = 1, l2 = 1;
		int d1, d2, t1 = dep[x] - dep[l1], t2 = dep[l] - dep[l2];

		if(t1 > t2) swap(x, l), swap(y, r), swap(l1, l2), swap(t1, t2);
		int L = 1, R = min(d1 = dep[x] + dep[y] - 2 * dep[l1] + 1, d2 = dep[l] + dep[r] - 2 * dep[l2] + 1), res = 0;
//		cerr << x << ' ' << y << ' ' << l1 << ' ' << l << ' ' << r << ' ' << l2 << ' ' << t1 << ' ' << t2 << endl;
//		cerr << t1 << ' ' << t2 << endl;
		while(L <= R) {
			int mid = (L + R) >> 1;
//			cerr << L << ' ' << R << ' ' << mid << endl;
			if(mid > t2 + 1) {
				
				if(getr(kth(x, t1 - 1), x) * pw[mid - t1] + geto(l1, kth(y, d1 - mid)) == getr(kth(l, t2 - 1), l) * pw[mid - t2] + geto(l2, kth(r, d2 - mid))) L = mid + 1, res = mid;
				else R = mid - 1;
			} else if(t1 + 1 < mid && mid <= t2 + 1) {
//				cerr << mid << endl;
				if(getr(kth(x, t1 - 1), x) * pw[mid - t1] + geto(l1, kth(y, d1 - mid)) == getr(kth(l, mid - 1), l)) L = mid + 1, res = mid;
				else R = mid - 1;
			} else {
//				cerr << "?";
//				geto(kth(x, mid - 1), x).print(), geto(kth(l, mid - 1), l).print();
				if(getr(kth(x, mid - 1), x) == getr(kth(l, mid - 1), l)) L = mid + 1, res = mid;
				else R = mid - 1;
			}
		}
//		cerr << endl;
		FO(res); FO('\n');
	}
    return FastIO::Fflush(), 0;
}
/*
4
ngww
1 2
2 3
3 4
1
3 4 4 3
*/