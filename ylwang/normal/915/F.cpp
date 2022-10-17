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
const int MAXN = 1e6 + 5;
int n, a[MAXN], p[MAXN];
vector < int > e[MAXN];
bool cmp(int i, int j) {return a[i] < a[j];}
bool cmp2(int i, int j) {return a[i] > a[j];}
struct DSU {
	int f[MAXN], siz[MAXN];
	void init(int n) {
		For(i, 1, n) f[i] = i, siz[i] = 1;
	}
	inline int find(int x) {
//		cerr << x << ' ' << f[x] << endl;
		if(x == f[x]) return x;
		return f[x] = find(f[x]);
	}
	inline void merge(int x, int y) {
//		cerr << x << ' ' << y << endl;
		int fx = find(x), fy = find(y);
//		cerr << fx << ' ' << fy << endl;
		if(fx == fy) return;
		f[fy] = fx; siz[fx] += siz[fy];
	}
}dsu;

int ok[MAXN];
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n);
	For(i, 1, n) FI(a[i]);
	For(i, 1, n-1) {
		int u, v; FI(u), FI(v);
		e[u].pb(v); e[v].pb(u);
	}
	ll res = 0;
	For(i, 1, n) p[i] = i;
	sort(p + 1, p + 1 + n, cmp);
	
	dsu.init(n); mst(ok, 0);
	For(i, 1, n) {
//		cerr << i << ' ' << p[i] << endl;
		int u = p[i];
		ok[u] = 1; int now = 1; res += a[u];
		for(auto v : e[u]) {
			if(ok[v]) {
				int sz = dsu.siz[dsu.find(v)];
				res += a[u] * now * sz; now += sz;
				dsu.merge(u, v);
			}
		}
//		cerr << i << ' ' << u << ' ' << mul << endl;
//		cerr << i << endl;
//assert(res >= 0);
	}
//	cerr << "?" << endl;
//cerr << res <<endl;
	sort(p + 1, p + 1 + n, cmp2);
	dsu.init(n); mst(ok, 0);
	For(i, 1, n) {
		int u = p[i];
		ok[u] = 1; int now = 1; res -= a[u];
		for(auto v : e[u]) {
			if(ok[v]) {
				int sz = dsu.siz[dsu.find(v)];
				res -= a[u] * now * sz; now += sz;
				dsu.merge(u, v);
			}
		}
		
	}
	cout << res << endl; 
    return FastIO::Fflush(), 0;
}
/*
6
9562 4694 7617 7624 9137 7920 
1 2
2 3
2 4
3 5
2 6

*/