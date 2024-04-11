#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() {
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
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
const int N=82;
int mod;
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
int n, K, C[N][N], pw[N*N], dw[N][N];
int f[N][N], g[N][N], h[N][N];
inline void init(int n) {
	C[0][0]=1;
	for (int i=1; i<=n; i++) {
		C[i][0]=1;
		for (int j=1; j<=i; j++) C[i][j]=add(C[i-1][j], C[i-1][j-1]);
	}
	pw[0]=1;
	for (int i=1; i<=n*n; i++) pw[i]=add(pw[i-1], pw[i-1]);
	for (int i=0; i<=n; i++) {
		int x=pw[i]-1; dw[i][0]=1;
		for (int j=1; j<=n; j++) dw[i][j]=(ll)dw[i][j-1]*(x-j+1)%mod;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), K=read(), mod=read(), init(max(n, K));
	for (int i=0; i<=n; i++)
		for (int j=0; j<=K; j++) {
			f[i][j]=qpow(pw[i]-1, j);
			for (int k=0; k<=j; k++) {
				int tmp=(ll)C[j][k]*dw[k][i]%mod;
				if (j-k&1) dec(h[i][j], tmp);
				else inc(h[i][j], tmp);
			}
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=K; j++)
			for (int k=0; k<i; k++)
				for (int l=0; l<j; l++)
					if (n%2==0 || i!=n || k!=i-1)
						inc(g[i][j], (ll)C[i][k]*C[j][l]%mod*pw[l*(i-k)]%mod*h[i-k][j-l]%mod*(f[k][l]+mod-g[k][l])%mod);
	int ans=0;
	for (int i=0; i<=K; i++) inc(ans, (ll)C[K][i]*(f[n][i]+mod-g[n][i])%mod);
	printf("%d\n", ans);
	return 0;
}