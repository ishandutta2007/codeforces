#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e6+7, mod=1e9+7, inv2=5e8+4;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
int n, pw[N], ipw[N], f[N], g[N];
inline void work() {
	n=read();
	if (n==1) {puts("1"); return;}
	puts("0"), g[n+1]=0;
	for (int i=n; i; i--) {
		f[i]=ipw[(i+1)/2-(i==n)];
		if (i*2<=n) mul(f[i], mod+1-g[i*2]);
		g[i]=(g[i+1]+f[i])%mod;
	}
	for (int i=2; i<=n; i++) printf("%d\n", f[i]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=1e6+2, pw[0]=ipw[0]=1;
	for (int i=1; i<=n; i++) pw[i]=2ll*pw[i-1]%mod, ipw[i]=(ll)ipw[i-1]*inv2%mod;
	int test=read();
	while (test--) work();
	return 0;
}