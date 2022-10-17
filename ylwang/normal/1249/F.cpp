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
#define ull unsigned ll
using namespace std;
const int P = 1000000007;
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
const int MAXN = 2e4 + 5;
const int MAXK = 205;
int n, k;
struct Edge {
	int v, nxt;
}e[MAXN<<1];
int a[MAXN], lst[MAXN], tot = 0;
inline void addedge(int u, int v) {
	e[++tot] = (Edge) {v, lst[u]};
	lst[u] = tot;
}
int f[MAXN][MAXK + 1], g[MAXK + 1]; // dp[i][j] :  i  j
void dfs(int u, int fa) {
	f[u][0] = a[u];
	Foe(tt, u) {
		if(v == fa) continue;
		dfs(v, u); mst(g, 0);
		For(i, 0, k) {
			For(j, k-i, k) {
				ckmax(g[min(i, j+1)], f[u][i] + f[v][j]);
			}
		}
		For(i, 0, k) f[u][i] = g[i];
	}
}
signed main()
{
//	file("score");
	FI(n); FI(k);
	For(i, 1, n) FI(a[i]);
	For(i, 1, n-1) {
		int u, v; FI(u); FI(v);
		addedge(u, v); addedge(v, u);
	}
	dfs(1, 0);
	int res = 0;
//	For(u, 1, n) {
//		For(i, 0, k) {
//			cerr << dp[u][i] << ' ';
//		} 
//		cerr << endl;
//	}
	For(i, 0, k)
		ckmax(res, f[1][i]);
	printf("%d\n", res);
    return FastIO::Fflush(), 0;
    
}
/*  

*/