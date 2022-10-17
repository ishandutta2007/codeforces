#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define ull unsigned ll
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); --i)
#define For(i, k, j) for(rint i = (k); i <= (j); ++i)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};

const int MAXN = 1e5 + 5;
int n, m;
Pair q[MAXN];
vector < int > e[MAXN];
int siz[MAXN], fa[MAXN], dep[MAXN], fir[MAXN], Num = 0;
void dfs1(int u, int Fa) {
	fa[u] = Fa, siz[u] = 1;
	for(auto v : e[u]) {
		if(v != Fa) {
			dep[v] = dep[u] + 1;
			dfs1(v, u);
			siz[u] += siz[v];
		}
	}
}
void dfs2(int u, int Fir) {
	fir[u] = Fir;
	int maxi = -1, maxv = 0;
	for(auto v : e[u])
		if(v != fa[u] && maxv < siz[v]) maxi = v, maxv = siz[v];
	if(maxi == -1) return;
	dfs2(maxi, Fir);
	for(auto v : e[u])
		if(v != fa[u] && v != maxi) dfs2(v, v);
}
inline int lca(int x, int y) {
	while(fir[x] != fir[y]) {
		if(dep[fir[x]] < dep[fir[y]]) swap(x, y);
		x = fa[fir[x]];	
	}
	if(dep[x] > dep[y]) swap(x, y);
	return x;
}
inline int getdist(int x, int y) {
//	cerr << x << ' ' << y << ' ' << lca(x, y) << endl;
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int st[MAXN], cnt = 0, dis[MAXN];
queue < int > Q;
inline void bfs() {
	For(i, 1, n) dis[i] = INF;
	For(i, 1, cnt) Q.push(st[i]), dis[st[i]] = 0;
	while(Q.size()) {
		int u = Q.front(); Q.pop();
		for(auto v : e[u])
			if(dis[v] == INF) dis[v] = dis[u] + 1, Q.push(v);
	}
	
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	cin >> n >> m;
	For(i, 1, n-1) {
		int u, v; FI(u); FI(v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs1(1, 1);
	dfs2(1, -1);
	For(i, 1, m) {
		FI(q[i].first); FI(q[i].second);
	}
	For(i, 1, n) dis[i] = INF;
	int Bsiz =  sqrt(2 * m / log2(m)) ;
	q[0].first = 1, q[0].second = 1;
	for(int l = 0, r; l <= m; l = r + 1) {
		r = min(l + Bsiz, m);
//		cerr << l << ' ' << r << endl;
		For(i, l, r) {
			if(q[i].first == 2) {
				int res = dis[q[i].second];
				For(j, l, i-1) {
					if(q[j].first == 1) {
						ckmin(res, getdist(q[i].second, q[j].second));
					}
				}
				printf("%d\n", res);
			}
		}
		For(i, l, r)
			if(q[i].first == 1)
				st[++cnt] = q[i].second;
		bfs();
	}
    return FastIO::Fflush(), 0;
}
/*

*/