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
const int MAXN = 2e5 + 5;
inline int random(int l, int r) {
	return (rand() << 15 | rand()) % (r - l + 1) + l;
}
int n, m;
struct Edge {
	int u, v, nxt;
}e[MAXN];
int lst[MAXN], tot;
inline void addedge(int u, int v) {
	e[++tot] = (Edge) {u, v, lst[u]};
	lst[u] = tot;
}
int vis[MAXN], ins[MAXN], rt;
int dfs1(int u) {
	vis[u] = ins[u] = 1;
	int res = 1;
//	cerr << u << ' ' << lst[u] << endl;
	Foe(i, u) {
//		cerr << u << ' ' << v << endl;
		if(!vis[v]) res &= dfs1(v);
		else if(!ins[v]) return ins[u] = 0, 0;
	}
	return ins[u] = 0, res;
}
int ik[MAXN], cnt[MAXN], to[MAXN], dep[MAXN];
void dfs2(int u) {
	vis[u] = 1;
	Foe(i, u) {
		if(!vis[v]) ik[i] = 1, dep[v] = dep[u] + 1, dfs2(v);
		else {
			cnt[u]++, cnt[v]--;
			if(!to[u] || dep[to[u]] > dep[v]) to[u] = v;
		}
	}
}

void dfs3(int u) {
	Foe(i, u) {
		if(!ik[i]) continue;
		dfs3(v); cnt[u] += cnt[v];
		if(!to[u] || dep[to[u]] > dep[to[v]])  to[u] = to[v];
	}
}
vector < int > ans; int ok[MAXN];
void dfs4(int u) {
//	cerr << u << ' ' << to[u] << ' ' << cnt[u] << ' ' << ok[0] << endl;
	if(!(ok[to[u]] || to[u] == u) || cnt[u] > 1) ok[u] = 0;
//	cerr << u << ' ' << to[u] << ' ' << ok[to[u]] << ' ' << cnt[u] << endl;
	Foe(i, u) {
//		cerr << u << ' ' << v << endl;
//		cerr << i << endl;
		if(ik[i]) dfs4(v);
	}
}
void init() {
	ans.clear(); tot = 0;
	For(i, 1, m) ok[i] = cnt[i] = to[i] = vis[i] = lst[i] = dep[i] = 0;
	For(i, 1, m) ik[i] = 0;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    srand(20181003);
    int T; FI(T);
    For(td, 1, T) {
    	fprintf(stderr, "testdata %d : \n", td);
    	FI(n); FI(m);
		init();
    	For(i, 1, m) {
    		int u, v; FI(u), FI(v);
    		addedge(u, v);
		}
		
		For(ZTYAKIOI, 1, 103) {
			rt = random(1, n); For(i, 1, n) vis[i] = 0;
			if(dfs1(rt)) goto ok;
		}
		printf("-1\n"); continue;
		ok:;
//		cerr << rt << endl;
		For(i, 1, m) vis[i] = 0;
		dfs2(rt); dfs3(rt);
//		cerr << rt << endl;
//		For(i, 1, n) {
//			cerr << i << ' ' << cnt[i] << ' ' << to[i] << endl;
//		}
		
		For(i, 0, n) ok[i] = 1;
		dfs4(rt); For(i, 1, n) if(ok[i]) ans.pb(i);
		if(ans.size() * 5 < n) printf("-1\n");
		else {
			sort(ans.begin(), ans.end());
			for(auto it : ans) printf("%d ", it);
			printf("\n");
		}
		end:;
	}
	return FastIO::Fflush(), 0;
}
/*

*/