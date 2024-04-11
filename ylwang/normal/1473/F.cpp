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
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
//#define int long long
const int P = 1000000007; //
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 20005;

int n, a[MAXN], b[MAXN];
struct Edge {
	int v, nxt, w;
};
struct Dinic { // Init!
	static const int N = MAXN + 5;
	static const int M = MAXN * 12 + 5;
	int lst[N], tot, dep[N], cur[N], s, t, n; Edge e[M << 1]; queue < int > q;
	Dinic() {tot = 1;}
	void init(int tn, int ts, int tt) {s = ts, t = tt, n = tn; mst(lst, 0);}
	inline void addedge(int u, int v, int w) {
		e[++tot] = (Edge) {v, lst[u], w}; lst[u] = tot;
		e[++tot] = (Edge) {u, lst[v], 0}; lst[v] = tot;
	}
	bool bfs() {
		mst(dep, 0); dep[s] = 1, q.push(s);
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int i = lst[u]; i; i = e[i].nxt) {
				int v = e[i].v;
				if(!dep[v] && e[i].w)
					dep[v] = dep[u] + 1, q.push(v);
			}
		}
		return dep[t];
	}
	int dfs(int u, int nowflow) {
		if(u == t) return nowflow;
		int flow = 0;
		for(int &i = cur[u]; i; i = e[i].nxt) {
			int v = e[i].v, di = 0;
			if(dep[v] == dep[u] + 1 && (di = dfs(v, min(nowflow, e[i].w)))) 
				nowflow -= di, flow += di, e[i].w -= di, e[i ^ 1].w += di;
			if(!nowflow) break;
		}
		return flow;
	}
	int solve() {
		int maxflow = 0, di;
		while(bfs()) {
			memcpy(cur, lst, sizeof(cur));
			while(di = dfs(s, INF)) maxflow += di;
		}
		return maxflow;
	}
}d;
int used[205]; 
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    n = read();
	For(i, 1, n) a[i] = read();
	int ans = 0; For(i, 1, n) ans += max(b[i] = read(), 0);
	d.init(n + 1, 0, n + 1);
	For(i, 1, n) {
		if(b[i] > 0) d.addedge(0, i, b[i]);
		else d.addedge(i, n + 1, -b[i]);
	}
	For(i, 1, n) {
		mst(used, 0);
		foR(j, i - 1, 1) {
			if(a[i] % a[j] == 0 && !used[a[j]]) d.addedge(i, j, INF), used[a[j]] = 1;
		}
	}
	int t = d.solve();
	printf("%d\n", ans - t);
    return FastIO::Fflush(), 0;
}
/*
 
*/