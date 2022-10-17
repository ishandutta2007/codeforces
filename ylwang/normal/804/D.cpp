#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
//#define int long long
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
const int MAXN = 1e5 + 5;
int bel[MAXN], n, m, q, f[MAXN], g[MAXN];
int cnt, d[MAXN], siz[MAXN]; vector < int > F[MAXN], sum[MAXN];
vector < int > e[MAXN];
void pushr(int u, int val) {
	if(val > f[u]) g[u] = f[u], f[u] = val;
	else if(val > g[u]) g[u] = val;
}
void dfs1(int u, int fa) {
	bel[u] = cnt, f[u] = g[u] = 0, siz[cnt]++;
	for(auto v : e[u]) {
		if(v == fa) continue; dfs1(v, u);
		pushr(u, f[v] + 1);
	}
}
void dfs2(int u, int fa) {
	ckmax(d[cnt], f[u]);
	for(auto v : e[u]) {
		if(v == fa) continue;
		if(f[v] + 1 == f[u]) pushr(v, g[u] + 1);
		else pushr(v, f[u] + 1);
		dfs2(v, u);
	}
}
void dfs3(int u, int fa) {
	F[cnt].pb(f[u]);
	for(auto v : e[u]) if(v != fa) dfs3(v, u);
}
map < Pair, double > ans;
double query(int x, int y) {
	if(x == y) return -1;
	if(ans.count(mkp(x, y))) return ans[mkp(x, y)];
	ll res = 0;
	for(auto v : F[x]) {
		int pos = upper_bound(F[y].begin(), F[y].end(), max(d[x], d[y]) - v, greater<int>()) - F[y].begin() - 1;
//		cerr << v << ' ' << max(d[x], d[y]) - v << ' ' << pos << endl;
//		for(auto w : F[y]) {
//			cerr << w << ' ';
//		}
//		cerr << endl;
		res += sum[y][pos] + 1ll * (v + 1) * (pos + 1), res += 1ll * (siz[y] - pos - 1) * max(d[x], d[y]);
	}
	return ans[mkp(x, y)] = 1.0 * res / siz[x] / siz[y];
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(m); FI(q);
    For(i, 1, m) {
    	int u, v; FI(u), FI(v);
    	e[u].pb(v), e[v].pb(u);
	}
	For(i, 1, n) {
		if(!bel[i]) cnt++, dfs1(i, 0), dfs2(i, 0), dfs3(i, 0);
	}
//	cerr << "?" << endl;
	For(i, 1, cnt) {
//		cerr << d[i] << endl;
//		cerr << i << ' ' << F[i].size() << endl;
		sort(F[i].begin(), F[i].end(), greater<int>());
		For(j, 0, (int)F[i].size()-1)
			sum[i].pb((j > 0 ? sum[i].back() : 0) + F[i][j]);
//		cerr << endl;
	}
		
	while(q--) {
		int x, y; FI(x); FI(y);
		x = bel[x], y = bel[y]; if(siz[x] > siz[y]) swap(x, y);
		if(query(x, y) != -1) printf("%.10lf\n", query(x, y));
		else printf("-1\n");
	}
    return FastIO::Fflush(), 0;
}
/*
Think twice!
*/