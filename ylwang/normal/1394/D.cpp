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
#define int long long
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
int n, t[MAXN], h[MAXN], f[MAXN], g[MAXN]; // f[u][0/1] :  u  / , 
vector < int > e[MAXN];
int in[MAXN], out[MAXN], a[MAXN], used[MAXN];
void dfs(int u, int fa) { 
//cerr << u << endl;
	used[u] = 1; int sum = 0, cnt = 0;
	for(auto v : e[u]) if(v != fa) dfs(v, u); 
	for(auto v : e[u]) if(v != fa) a[++cnt] = f[v] - g[v], sum += g[v];
//	if(!cnt) return;
	sort(a + 1, a + 1 + cnt, greater < int > ());
//	cerr << cnt << endl;
	For(i, 0, cnt) {
		sum += a[i];
//		cerr << sum << endl;
		if(fa) {
			ckmax(f[u], sum + t[u] * min(in[u] + cnt - i + 1, out[u] + i));
			ckmax(g[u], sum + t[u] * min(in[u] + cnt - i, out[u] + i + 1));
		} else {
			ckmax(f[u], sum + t[u] * min(in[u] + cnt - i, out[u] + i));
		}
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n);
	For(i, 1, n) FI(t[i]);
	For(i, 1, n) FI(h[i]);
	int res = 0;
	For(i, 1, n-1) {
		int u, v; FI(u); FI(v);
		res += t[u] + t[v];
		if(h[u] == h[v]) {
			e[u].pb(v); e[v].pb(u);
		} else {
			if(h[u] < h[v]) swap(u, v);
			out[u]++, in[v]++;
		}
	}
//	For(i, 1, n) cerr << e[i].size() << endl;
//	For(i, 1, n) cerr << in[i] << ' ' << out[i] << endl;
//	cerr << res << endl;
	For(i, 1, n) {
		if(!used[i]) {
			dfs(i, 0); res -= f[i];
		}
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}
/*

*/