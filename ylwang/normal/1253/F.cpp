#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 62) - 1)
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
const int MAXN = 1e5 + 5;
const int MAXM = 3e5 + 5;
int n, m, k, q, key[MAXN], ik[MAXN];
struct Edge1 {
	int u, v, w;
	bool operator < (const Edge1 &b) const {return w < b.w;}
}g[MAXM];
struct Edge2 {
	int v, w, nxt;	
}e[MAXM << 1];
int lst[MAXN], tot;
void addedge(int u, int v, int w) {
	e[++tot] = (Edge2) {v, w, lst[u]};
	lst[u] = tot;
}
int dis[MAXN], used[MAXN], fr[MAXN];
struct Node {
	int x, y;
	bool operator < (const Node &b) const {return y > b.y;}
};
priority_queue < Node > Q;
inline void Dij() {
	For(i, 0, n) dis[i] = INF, used[i] = 0;
	For(i, 1, k) dis[key[i]] = 0, fr[key[i]] = key[i], Q.push((Node) {i, 0});
	while(Q.size()) {
		int u = Q.top().x, f = fr[u]; Q.pop(); if(used[u]) continue; used[u] = 1;
		Foe(i, u) {
			if(dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w, fr[v] = f;
				Q.push((Node) {v, dis[v]});	
			}
		}
	}
}
struct DSU {
	int f[MAXN];
	DSU() {For(i, 0, MAXN-2) f[i] = i;}
	int find(int u) {
		while(u != f[u]) u = f[u] = f[f[u]];
		return u;
	}
	int merge(int u, int v) {
		u = find(u), v = find(v);
		if(u == v) return 0;
		return f[v] = u, 1;
	}
}dsu;
struct Tree {
	Edge2 e[MAXM << 1];
	int lst[MAXN], tot;
	void addedge(int u, int v, int w) {
		e[++tot] = (Edge2) {v, w, lst[u]};
		lst[u] = tot;
	}
	int f[MAXN][20], mx[MAXN][20], dep[MAXN];
	void dfs1(int u, int fa, int fr)  {
//		cerr << u << ' ' << fa << endl;
		f[u][0] = fa, mx[u][0] = fr, dep[u] = dep[fa] + 1;
		For(i, 1, 19) f[u][i] = f[f[u][i-1]][i-1], mx[u][i] = max(mx[f[u][i-1]][i-1], mx[u][i-1]);
		Foe(i, u) {
			if(v == fa) continue;
			dfs1(v, u, e[i].w);
		}
	}
	int query(int u, int v) {
		if(dep[u] < dep[v]) swap(u, v); int res = 0;
		foR(i, 19, 0) if(dep[f[u][i]] >= dep[v]) ckmax(res, mx[u][i]), u = f[u][i];
		if(u == v) return res;
		foR(i, 19, 0) if(f[u][i] != f[v][i]) {
			ckmax(res, max(mx[u][i], mx[v][i]));
			u = f[u][i], v = f[v][i];
		}
		ckmax(res, max(mx[u][0], mx[v][0]));
		return res;
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    scanf("%lld %lld %lld %lld", &n, &m, &k, &q);
	For(i, 1, m) {
		scanf("%lld %lld %lld", &g[i].u, &g[i].v, &g[i].w);
		addedge(g[i].u, g[i].v, g[i].w); addedge(g[i].v, g[i].u, g[i].w); 
	}
	For(i, 1, k) key[i] = i, ik[i] = 1;
	Dij();
//	For(i, 1, n) cerr << dis[i] << ' ' << fr[i] << endl;
	For(i, 1, m) {
		g[i].w += dis[g[i].u] + dis[g[i].v];
		g[i].u = fr[g[i].u], g[i].v = fr[g[i].v];
	}
	
	sort(g + 1, g + 1 + m);
	For(i, 1, m) {
		if(dsu.merge(g[i].u, g[i].v))
			tr.addedge(g[i].u, g[i].v, g[i].w), tr.addedge(g[i].v, g[i].u, g[i].w);
	}
	
	tr.dfs1(1, 0, 0);
//	cerr << "?";
	For(tq, 1, q) {
		int x, y; scanf("%lld %lld", &x, &y);
		printf("%lld\n", tr.query(x, y));
	}
    return FastIO::Fflush(), 0;
}
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?

*/