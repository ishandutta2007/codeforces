#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
const int MAXN = 1 << 21 | 1;
const int MAXA = 1 << 21 | 1;
int n, val[MAXN << 1];
int deg[MAXA], lst[MAXA], vis[MAXN << 1], cnt[MAXA];
struct Edge {
	int v, nxt, x, y;
}e[MAXN << 1]; int tot = 1;
inline void addedge(int u, int v, int x, int y) {
	e[++tot] = (Edge) {v, lst[u], x, y};
	lst[u] = tot;
}
vector < int > ans;
inline void dfs(int u) {
//	cerr << u << endl;
	for(int i = lst[u]; i; i = lst[u]) {
		Edge now = e[i];
//		cerr << u << ' ' << lst[u] << ' ' << i << ' ' << e[i].nxt << endl;
		lst[u] = now.nxt;
//		assert(cnt[i] <= 1); 
		cnt[i]++;
//		cerr << i << ' ' << cnt[i] << endl;
		if(!vis[i >> 1]) {
			vis[i >> 1] = 1;
			dfs(now.v); 
			ans.pb(now.y), ans.pb(now.x);
		}
	}
}
bool used[MAXA]; vector < int > E[MAXA];
inline void dfs2(int u) {
	used[u] = 1;
	for(auto v : E[u])
		if(!used[v]) dfs2(v);
}
bool check(int mid) {
	For(i, 0, (1 << mid) - 1) used[i] = 0, E[i].clear();
	for(rint i = 1; i <= 2 * n; i += 2) {
		int u = val[i] & ((1 << mid) - 1), v = val[i + 1] & ((1 << mid) - 1);
		E[u].pb(v), E[v].pb(u);
	}
	For(i, 0, (1 << mid) - 1) if(E[i].size() & 1) return 0;
	dfs2(val[1] & ((1 << mid) - 1));
	For(i, 0, (1 << mid) - 1)
		if(E[i].size() && !used[i]) return 0;
	return 1;
}
void get(int mid) {
	e[0].nxt = 0; mst(lst, 0); mst(vis, 0); tot = 1; ans.clear(); 
	for(int i = 1; i <= 2 * n; i += 2) {
		int u = val[i] & ((1 << mid) - 1), v = val[i + 1] & ((1 << mid) - 1);
		addedge(u, v, i, i + 1); addedge(v, u, i + 1, i);
	}
	dfs(val[1] & ((1 << mid) - 1));
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); For(i, 1, 2 * n) FI(val[i]);
    int l = 0, r = 20, res = 0;
    while(l <= r) {
    	int mid = (l + r) >> 1;
//    	cerr << l << ' ' << r << ' ' << mid << endl;
    	if(check(mid)) {
    		l = mid + 1, res = mid;
		} else r = mid - 1;
	}
	cout << res << endl;
	get(res); 
	for(auto v : ans) printf("%d ", v);
//	For(i, 2, 2 * n + 1) {
//		printf("%d ", ans[i]);
//	}
	return FastIO::Fflush(), 0;
}
/*

*/