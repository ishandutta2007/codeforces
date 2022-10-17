#pragma GCC optimize("Ofast")
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
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];} 
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 2e5 + 5;
int q, s[MAXN], t[MAXN];
struct Tree {
	int n, s1[MAXN], s2[MAXN], f[MAXN][20], ok = 1, dep[MAXN];
	vector < int > e[MAXN];
	void addedge(int u, int v) {e[u].pb(v);}
	void dfs(int u, int fa) {
		dep[u] = dep[fa] + 1;
		f[u][0] = fa; For(i, 1, 19) f[u][i] = f[f[u][i-1]][i-1];
		for(auto v : e[u]) if(v != fa) dfs(v, u);
	}
	inline int lca(int u, int v) {
		if(dep[u] < dep[v]) swap(u, v);
		foR(i, 19, 0) if(dep[f[u][i]] >= dep[v]) u = f[u][i];
//		cerr << dep[u] << ' ' << dep[v]<< endl;
		if(u == v) return u;
		foR(i, 19, 0)
			if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
		return f[u][0];
	} 
	void check(int u, int fa) {
		for(auto v : e[u]) {
			if(v == fa) continue;
			check(v, u);
			s1[u] += s1[v], s2[u] += s2[v];
		}
//		cerr << u << ' ' << s1[u] << ' ' << s2[u] << endl;
		if(dep[u] != 1 && s1[u] && s2[u]) ok = 0;
//		cerr << u << endl;
//		assert(s1[u] >= 0); assert(s2[u] >= 0);
	}
	bool solve() {
		For(i, 1, n) if(!f[i][0]) dfs(i, i);
		For(i, 1, q) {
			if(f[s[i]][19] != f[t[i]][19]) return 0;
		}
		For(i, 1, q) {
			int u = s[i], v = t[i], l = lca(u, v);
//			cerr << u << ' ' << v << ' ' << l << endl;
			s1[u]++, s1[l]--; s2[v]++, s2[l]--;
		}
//		cerr << endl;
		For(i, 1, n) {
			if(dep[i] == 1) {
				assert(f[i][0] == i); check(i, i);
			}
		}
		return ok;
	}
	 
}T;
struct Graph {
	int n, m, bel[MAXN];
	map < Pair, int > cnt;
	vector < int > e[MAXN];
	int dfn[MAXN], low[MAXN], ind = 0, S[MAXN], top = 0, vis[MAXN<<1];
	void tarjan(int u, int fa) {
		dfn[u] = low[u] = ++ind; S[++top] = u;
		for(auto v : e[u]) {
			if(v == fa && cnt[mkp(u, v)] <= 1) continue;
			if(dfn[v]) {
				low[u] = min(low[u], dfn[v]);
			} else {
				tarjan(v, u);
				low[u] = min(low[u], low[v]);
			}
		}
		if(low[u] == dfn[u]) {
//			cerr << u << endl;
			++T.n;
			while(S[top] != u)
				bel[S[top--]] = T.n;
			bel[S[top--]] = T.n;
		}
	}
	void init() {
		FI(n); FI(m); FI(q);
		while(m--) {
			int u = 0, v = 0; FI(u); FI(v);
			e[u].pb(v); e[v].pb(u); cnt[mkp(u, v)]++, cnt[mkp(v, u)]++;
		}
		For(i, 1, n) if(!dfn[i]) tarjan(i, 0);
//		For(i, 1, n) cerr << bel[i] << endl;
//		cerr << endl;
		For(u, 1, n) {
			for(auto v : e[u])
				if(bel[u] != bel[v]) T.addedge(bel[u], bel[v]);
		}
		For(i, 1, q) {
			FI(s[i]); FI(t[i]);
			s[i] = bel[s[i]], t[i] = bel[t[i]];
//			cerr << i << ' ' << s[i] << ' ' << t[i] << '*' << endl;
			if(s[i] == t[i]) i--, q--;
		}
		cerr << q << endl;
//		For(i, 1, q) cerr << s[i] <<endl;
	}
}G; 

signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	G.init();
//	For(i, 1, q) cerr << s[i] << endl;
	printf(T.solve() ? "Yes\n" : "No\n");
    return FastIO::Fflush(), 0;
}
/*

*/