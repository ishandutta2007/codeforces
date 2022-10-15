#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=3e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
inline void dec(int &x, int y) {x-=y, x+=x>>31&mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int fac[N], ifac[N];
inline int C(int n, int m) {
	if (m<0 || n<m) return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int n, f[N], g[N];
inline void work() {
	n=read(), f[0]=1, g[0]=1;
	for (int i=1; i<=n; i++) f[i]=(f[i-1]+(ll)(i-1)*f[i-2])%mod;
	for (int i=2; i<=n/2; i+=2) g[i]=2ll*(i-1)*g[i-2]%mod;
	int ans=0;
	for (int i=0; i<=n/2; i+=2) inc(ans, (ll)g[i]*f[n-i*2]%mod*C(n-i, i)%mod);
	printf("%d\n", ans);
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	fac[0]=1, n=3e5;
	for (int i=1; i<=n; i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n], mod-2);
	for (int i=n; i; i--) ifac[i-1]=(ll)ifac[i]*i%mod;
	int test=read();
	while (test--) work();
	return 0;
}