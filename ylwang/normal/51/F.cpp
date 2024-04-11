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
const int MAXN = 2e5 + 5;
int n, m, ans, tcnt; 
struct Edge {
	int v, nxt;
};
struct Tree {
	vector < int > e[MAXN]; int dep[MAXN], mxp;
	inline int dfs(int u, int fa) {
		dep[u] = dep[fa] + 1; 
		if(mxp == -1 || dep[mxp] < dep[u]) mxp = u;
		int res = 0;
		for(auto v : e[u]) {
			if(v == fa) continue;
			res += dfs(v, u);
		}
//		cerr << res << endl; 
		if(e[u].size() != 1) return res + 1;
		else return res;
	} 
	int solve(int u) {
		if(e[u].size() == 0) return tcnt++, 0;
		mxp = -1; int c = dfs(u, 0); tcnt++;
		int t = mxp; mxp = -1; dfs(t, 0);
//		cerr << u << ' ' << c << ' ' << dep[mxp] << endl;
		return c - dep[mxp] + 2;
	}
}t;
struct Graph {
	Edge e[MAXN]; int tot = 1, lst[MAXN], vis[MAXN];
	inline void addedge(int u, int v) {
		e[++tot] = (Edge) {v, lst[u]};
		lst[u] = tot;
	}
	int dfn[MAXN], low[MAXN], ind = 0, cnt, siz[MAXN], col[MAXN];
	stack < int > s;
	void tarjan(int u) {
		dfn[u] = low[u] = ++ind, s.push(u);
		Foe(i, u) {
			if(vis[i >> 1]) continue; vis[i >> 1] = 1;
			if(!dfn[v]) tarjan(v);
			ckmin(low[u], low[v]);
		}
		if(low[u] == dfn[u]) {
			cnt++;
			while(s.top() != u) {
				int t = s.top(); s.pop();
				siz[cnt]++, col[t] = cnt;
			}
			int t = s.top(); s.pop();
			siz[cnt]++, col[t] = cnt;
			ans += siz[cnt] - 1;
		}
	}
	map < Pair, int > used;
	void add(int u, int v) {
		u = col[u], v = col[v]; if(v == u) return;
		if(u > v) swap(u, v);
		if(!used[mkp(u, v)]) {
			used[mkp(u, v)] = 1;
			t.e[u].pb(v), t.e[v].pb(u);
		}
	}
	void buildtree() {
//		cerr << cnt << endl; 
		For(u, 1, n) Foe(i, u)
			add(u, v);
	}
}g;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    cin >> n >> m;
    For(i, 1, m) {
    	int u, v; FI(u), FI(v);
    	g.addedge(u, v), g.addedge(v, u);
	}
	For(i, 1, n) if(!g.dfn[i]) g.tarjan(i);
//	cerr << ans << endl;
	g.buildtree();
	For(i, 1, g.cnt) if(!t.dep[i]) {
		ans += t.solve(i);
	}
	cout << ans + tcnt - 1 << endl;
    return FastIO::Fflush(), 0;
}