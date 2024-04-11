#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
#define int long long
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
    void write(ll x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 2e5 + 5;
int n, m, r, a[MAXN], b[MAXN], c[MAXN];
int sqr(int x) {
	return x * x;
}
signed main()
{
	#ifndef ONLINE_JUDGE 
    	file("pro");
    #endif
    int T = read();
    while(T--) {
    	n = read(), m = read(), r = read();
    	For(i, 1, n) a[i] = read();
    	For(i, 1, m) b[i] = read();
    	For(i, 1, r) c[i] = read();
    	sort(a + 1, a + 1 + n); a[0] = INT_MIN, a[n + 1] = INT_MAX;
    	sort(b + 1, b + 1 + m); b[0] = INT_MIN, b[m + 1] = INT_MAX;
    	sort(c + 1, c + 1 + r); c[0] = INT_MIN, c[r + 1] = INT_MAX;
    	int ans = 9e18;
    	For(i, 1, n) {
    		int X = b[upper_bound(b + 1, b + 1 + m, a[i]) - b - 1], Z = c[lower_bound(c + 1, c + 1 + r, a[i]) - c];
    		if(X != INT_MIN && Z != INT_MAX && X != INT_MAX && Z != INT_MIN) ckmin(ans, sqr(X - a[i]) + sqr(a[i] - Z) + sqr(X - Z)); 
    		X = b[lower_bound(b + 1, b + 1 + m, a[i]) - b], Z = c[upper_bound(c + 1, c + 1 + r, a[i]) - c - 1];
    		if(X != INT_MIN && Z != INT_MAX && X != INT_MAX && Z != INT_MIN)  ckmin(ans, sqr(X - a[i]) + sqr(a[i] - Z) + sqr(X - Z)); 
		}
//		cerr << ans << endl;
		For(i, 1, m) {
    		int X = a[upper_bound(a + 1, a + 1 + n, b[i]) - a - 1], Z = c[lower_bound(c + 1, c + 1 + r, b[i]) - c];
//    		cerr << i << ' ' << X << ' ' << Z << endl;
    		if(X != INT_MIN && Z != INT_MAX && X != INT_MAX && Z != INT_MIN)  ckmin(ans, sqr(X - b[i]) + sqr(b[i] - Z) + sqr(X - Z)); 
    		X = a[lower_bound(a + 1, a + 1 + n, b[i]) - a], Z = c[upper_bound(c + 1, c + 1 + r, b[i]) - c - 1];
    	if(X != INT_MIN && Z != INT_MAX && X != INT_MAX && Z != INT_MIN)  ckmin(ans, sqr(X - b[i]) + sqr(b[i] - Z) + sqr(X - Z)); 
		}
//		cerr << ans << endl;
		For(i, 1, r) {
    		int X = a[upper_bound(a + 1, a + 1 + n, c[i]) - a - 1], Z = b[lower_bound(b + 1, b + 1 + m, c[i]) - b];
    		if(X != INT_MIN && Z != INT_MAX && X != INT_MAX && Z != INT_MIN)  ckmin(ans, sqr(X - c[i]) + sqr(c[i] - Z) + sqr(X - Z)); 
//    		cerr << i << ' ' << X << ' ' << Z << endl;
			X = a[lower_bound(a + 1, a + 1 + n, c[i]) - a], Z = b[upper_bound(b + 1, b + 1 + m, c[i]) - b - 1];
//			cerr << i << ' ' << X << ' ' << Z << endl;
    		if(X != INT_MIN && Z != INT_MAX && X != INT_MAX && Z != INT_MIN)  ckmin(ans, sqr(X - c[i]) + sqr(c[i] - Z) + sqr(X - Z)); 
		}
//		cerr << ans << endl;
		printf("%lld\n", ans);
	}
    return FastIO::Fflush(), 0;
}
/*
ai - s3x^2 + 3x - 1
*/