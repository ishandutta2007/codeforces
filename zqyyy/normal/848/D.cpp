// LUOGU_RID: 90873310
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<10]; // '\n' for function isspace in function readstr
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<10, stdin), p1==p2?'\n':*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc(); (*s++)='\0';
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=57, mod=1e9+7;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, m, f[N][N], g[N][N], dp[N][N], ifac[N];
// i used, j flow
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read()+1, m=read(), f[0][1]=dp[0][0]=1, ifac[0]=1;
	for (int i=1; i<=n; i++) ifac[i]=(ll)ifac[i-1]*qpow(i, mod-2)%mod;
	for (int i=1; i<=n; i++) {
		for (int j=n; j; j--)
			for (int k=0; k<i; k++) {
				inc(g[i][j], (ll)f[k][j]*f[i-1-k][j]%mod);
				for (int l=j+1; l<=n; l++) inc(g[i][j], 2ll*f[k][j]*f[i-1-k][l]%mod);
			}
		for (int j=1; j<=n; j++)
			for (int x=n; x>=0; x--)
				for (int y=n; y>=0; y--)
					for (int k=1, sum=1; i*k<=x && j*k<=y; k++)
						mul(sum, g[i][j]+k-1), inc(dp[x][y], (ll)dp[x-i*k][y-j*k]*sum%mod*ifac[k]%mod);
		for (int j=1; j<=n; j++) f[i][j]=dp[i][j-1];
	}
	printf("%d\n", f[n-1][m]);
	return 0;
}