#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=5007, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline void dec(int &x, int y) {x-=y, x+=x>>31&mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a))
		if (b&1) mul(res, a);
	return res;
}
int n, a, b, p, pw[N], ipw[N], f[N], g[N], h[N][N];
int main() {
	n=read(), a=read(), b=read(), p=(ll)a*qpow(b, mod-2)%mod, pw[0]=ipw[0]=1;
	for (int i=1; i<=n; i++) pw[i]=(ll)pw[i-1]*p%mod, ipw[i]=(ll)ipw[i-1]*(mod+1-p)%mod;
	h[0][0]=1;
	for (int i=1; i<=n; i++) {
		h[i][0]=1;
		for (int j=1; j<=i; j++)
			h[i][j]=((ll)h[i-1][j]*ipw[j]+(ll)h[i-1][j-1]*pw[i-j])%mod;
	}
	g[0]=1;
	for (int i=1; i<=n; i++) {
		g[i]=1;
		for (int j=1; j<i; j++) dec(g[i], (ll)g[j]*h[i][j]%mod);
	}
	for (int i=1; i<=n; i++) {
		int res=0;
		for (int j=1; j<i; j++) inc(res, ((j*(j-1ll)>>1)+(i-j)*j+f[j]+f[i-j])*g[j]%mod*h[i][j]%mod);
		inc(res, (i*(i-1ll)>>1)*g[i]%mod*h[i][i]%mod);
		f[i]=(ll)res*qpow(mod+1-(ll)g[i]*h[i][i]%mod, mod-2)%mod;
	}
	printf("%d\n", f[n]);
	return 0;
}