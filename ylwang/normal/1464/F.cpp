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
//#define int long long
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
vector < int > e[MAXN];
//namespace BAS {
	int siz[MAXN], f[MAXN], dep[MAXN], id[MAXN], up[MAXN][5], ind, dfn[MAXN], top[MAXN], L[MAXN], R[MAXN];
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
		return !u ? 1 : id[dfn[u] - k];
	}
	int lca(int u, int v) {
		while(top[u] != top[v])
			dep[top[u]] > dep[top[v]] ? u = f[top[u]] : v = f[top[v]];
		return dep[u] < dep[v] ? u : v;
	}
	int dist(int i, int j) {
		if(i == -1 || j == -1) return 0;
		return dep[i] + dep[j] - 2 * dep[lca(i, j)];	
	}
	#undef upd
	#undef jump	
//}
//#define lca(i, j) BAS::lca(i, j)
//#define dist(i, j) BAS::dist(i, j)
struct Chain {
	int x, y, l;
	Chain operator + (const Chain &b) const {
		Chain ans = b; int tmp = 0;
//		cerr << x << ' ' << y << endl;
		if(x == -1) return b; if(b.x == -1) return *this;
		if(l > ans.l) ans = *this;
//		cerr << x << '*' << b.y << ' ' << dist(x, b.y) << endl;
		tmp = dist(x, b.y); if(tmp > ans.l) ans = (Chain) {x, b.y, tmp};
		tmp = dist(y, b.y); if(tmp > ans.l) ans = (Chain) {y, b.y, tmp};
		tmp = dist(x, b.x); if(tmp > ans.l) ans = (Chain) {x, b.x, tmp};
		tmp = dist(y, b.x); if(tmp > ans.l) ans = (Chain) {y, b.x, tmp};
		return ans;
	}
};
Chain a[MAXN << 2];
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)
void update(int k, int l, int r, int pos, int op) {
	
//	cerr << l << ' ' << r << ' ' << pos << endl;
	if(l == r) return a[k].x = a[k].y = (op ? id[l] : -1), a[k].l = 0, void();
	pos <= mid ? update(ls, l, mid, pos, op) : update(rs, mid+1, r, pos, op);
	a[k] = a[ls] + a[rs];
//	cerr << k << ' ' << l << ' ' << r << ' ' << a[k].x << ' ' << a[k].y << ' ' << a[k].l << endl;
}
Chain query(int k, int l, int r, int ql, int qr) {
	if(l == ql && r == qr) return a[k];
	if(qr <= mid) return query(ls, l, mid, ql, qr);
	if(mid < ql) return query(rs, mid+1, r, ql, qr);
	return query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr);	
}
struct Node {
	int x, dep;
	bool operator < (const Node &b) const {if(dep != b.dep) return dep > b.dep; return x > b.x;}
};
struct Sum_tree {
	static const int N = MAXN << 2;
	int sum[N];
	inline void update(int k, int l, int r, int pos, int val) {
		if(l == r) return sum[k] += val, void();
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid+1, r, pos, val);
		sum[k] = sum[ls] + sum[rs];	
	}
	inline int query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return sum[k];
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr);	
	}
}tr;
multiset < Node > S;
int n, Qnum, sum[MAXN], cnt[MAXN], tcnt = 0, tmp = 0;
int solve() {
	int d = read(), l = S.begin()->x, u = kth(l, d), v = kth(u, d);
//	cerr << l << ' ' << u << ' ' << v << endl;
//	cerr << "?" << ' ' << tr.query(1, 1, n, L[v], R[v]) << ' ' << S.size() << endl;
	if(tr.query(1, 1, n, L[v], R[v]) != tcnt) {return 0;}
	
	Chain tmp = query(1, 1, n, L[v], R[v]);
//	cerr << tmp.x << ' ' << tmp.y << endl;
	if(dist(tmp.x, u) > d || dist(tmp.y, u) > d) return 0;
	return 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
	n = read(), Qnum = read();
	For(i, 1, n - 1) {
		int u = read(), v = read();
		e[u].pb(v), e[v].pb(u);	
		if(i == 1 && v != 10) tmp = -10000000;
	}
	
	dfs1(1, 0); dfs2(1, 1);
	For(i, 1, n) L[i] = dfn[i], R[i] = dfn[i] + siz[i] - 1;
//	For(i, 1, n) cerr << dfn[i] << ' ' << id[i] << endl;
	For(i, 1, n << 2) a[i].x = a[i].y = a[i].l = -1;
	while(Qnum--) {
		int op = read();
		if(op != 3) {
			int x = read(), y = read(), t = lca(x, y); if(x > y) swap(x, y);Node now = (Node) {t, dep[t]};
//			cerr << "insert " << x << ' ' << y << ' ' << t << endl;
			if(op == 1) {
				if(!cnt[t]) update(1, 1, n, dfn[t], 1);  cnt[t]++;
				S.insert(now); tr.update(1, 1, n, dfn[x], 1); tr.update(1, 1, n, dfn[y], 1);
				tr.update(1, 1, n, dfn[t], -1); tcnt++;
			}
			else {
				S.erase(S.find(now)); 
				if(cnt[t] == 1) update(1, 1, n, dfn[t], 0); 
				cnt[t]--; tr.update(1, 1, n, dfn[x], -1); tr.update(1, 1, n, dfn[y], -1);
				tr.update(1, 1, n, dfn[t], 1); tcnt--;
				
			}
		} else {
			tmp++;
			printf(solve() ? "Yes\n" : "No\n");
		}
	}
	
	return FastIO::Fflush(), 0;
}
/*
.X..
...X
..X.
..XX
*/