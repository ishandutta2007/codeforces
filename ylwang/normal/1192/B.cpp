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
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(ll &a, ll b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
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
const int MAXN = 2e5 + 5;
int n, q, W; 
struct BIT {
	int c[MAXN];
	inline void upd(int x, int v) {for(; x <= n; x += x&(-x)) c[x] += v;}
	void update(int l, int r, int v) {
		upd(l, v); upd(r+1, -v);
	}
	int query(int x) {
		int ans = 0; for(; x; x -= x&(-x)) ans += c[x];
		return ans;
	}
}bit;
struct Edge {
	int u, v, w, nxt;
}e[MAXN<<1];

int lst[MAXN], tot = 0, dep[MAXN], dis[MAXN], in[MAXN], out[MAXN], ind = 0, f[MAXN][20], id[MAXN];
void addedge(int u, int v, int w) {
	e[++tot] = (Edge) {u, v, w, lst[u]};
	lst[u] = tot;
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	foR(i, 19, 0) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	foR(i, 19, 0) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
void dfs1(int u, int fa) {
	dep[u] = dep[fa] + 1, f[u][0] = fa, in[u] = ++ind, id[ind] = u;
	For(i, 1, 19) f[u][i] = f[f[u][i-1]][i-1];
	Foe(i, u) {
		if(v == fa) continue;
		dis[v] = dis[u] + e[i].w; dfs1(v, u); 
	}
	out[u] = ind;
}
int dist(int u, int v) {return bit.query(u) + bit.query(v) - 2 * bit.query(in[lca(id[u], id[v])]);}
int odist(int u, int v) {
	return bit.query(in[u]) + bit.query(in[v]) - 2 * bit.query(in[lca(u, v)]);
}
struct Chain {
	int x, y, l;
//	Chain() {x = y = l = 0;}
	Chain operator + (const Chain &b) const {
		Chain ans = b; int tmp = 0;
		if((this -> l) > ans.l) ans = *this;
//		cerr << x << '*' << b.y << ' ' << dist(x, b.y) << endl;
		tmp = dist(x, b.y); if(tmp > ans.l) ans = (Chain) {x, b.y, tmp};
		tmp = dist(y, b.y); if(tmp > ans.l) ans = (Chain) {y, b.y, tmp};
		tmp = dist(x, b.x); if(tmp > ans.l) ans = (Chain) {x, b.x, tmp};
//		cerr << b.x << '*' << y << ' ' << dist(b.x, y) << endl;
		tmp = dist(y, b.x); if(tmp > ans.l) ans = (Chain) {y, b.x, tmp};
//		cerr << x << ' ' << y << ' ' << b.x << ' ' << b.y << ' ' << ans.x << ' ' << ans.y << ' ' << ans.l << ' ' << lca(id[ans.x], id[ans.y]) << endl;
		return ans;
	}
};
struct Segment_tree {
	Chain a[MAXN<<2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void build(int k, int l, int r) {
		if(l == r) return a[k].x = a[k].y = l, a[k].l = 0, void();
		build(ls, l, mid); build(rs, mid+1, r);
		a[k] = a[ls] + a[rs];
	}
	void print(int k, int l, int r) {
		cerr << k << ' ' << a[k].x << ' ' << a[k].y<< ' ' << a[k].l << endl;
		if(l == r) return;
		print(ls, l, mid); print(rs, mid+1, r);
	}
	void Debug() {
		print(1, 1, n);
		fprintf(stderr, "\n");
	}
	void update(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return;
		if(qr <= mid) update(ls, l, mid, ql, qr);
		else if(mid < ql) update(rs, mid+1, r, ql, qr);
		else update(ls, l, mid, ql, mid), update(rs, mid+1, r, mid+1, qr);
		a[k] = a[ls] + a[rs];
	}
}tr;
signed main()
{
	cin >> n >> q >> W;
	For(i, 1, n - 1) {
		int u, v, w; FI(u); FI(v); FI(w);
		addedge(u, v, w); addedge(v, u, w);
	}
	dfs1(1, 0);
//	For(i, 1, n) {
//		cerr << dis[i] << endl;
//	}
	For(i, 1, n)
		bit.update(in[i], in[i], dis[i]);
//	For(i, 1, n) {
//		cerr << in[i] << endl;
//	}
	tr.build(1, 1, n);
//	tr.print(1, 1, n);
//	For(i, 1, n) {
//		For(j, 1, n) {
//			cerr << i << ' ' << j << ' ' << lca(i, j) << ' ' << odist(i, j) << endl;
//		}
//		cerr << endl;
//	}
	int lstans = 0;
	while(q--) {
		int i, w; FI(i); FI(w);
		i = (i + lstans) % (n - 1) + 1, w = (w + lstans) % W;
//		cerr << id << ' ' << w << endl;
		i = (i << 1); int u = e[i].u, v = e[i].v, ow = e[i].w;
		if(f[v][0] == u) swap(u, v);
		bit.update(in[u], out[u], w - ow);
//		For(i, 1, n) {
//			cerr << bit.query(id[i]) << ' ';
//		}
//		cerr << endl;
		e[i].w = e[i-1].w = w;
		tr.update(1, 1, n, in[u], out[u]);
//		tr.Debug();
		printf("%lld\n", lstans = tr.a[1].l);
	}
    return FastIO::Fflush(), 0;
}
/*

*/