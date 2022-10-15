#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e5+7, M=18, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int d, n, m, a[N], p[M], g[M][M], tmp[M][M], f[M];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	d=read(), n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=m; i++) p[i]=read();
	sort(p+1, p+m+1), p[0]=-d*3, p[m+1]=d*3, m++;
	for (int i=0; i<=m; i++)
		for (int j=i+1; j<=m; j++) g[i][j]=1;
	auto upd=[&](int x) {
		int pos=lower_bound(p, p+m+1, x)-p;
		for (int j=0; j<pos; j++)
			for (int k=pos; k<=m; k++)
				mul(g[j][k], min({d+1, p[k]-x, x-p[j]}));
	};
	for (int i=1; i<=n; i++) upd(a[i]);
	memcpy(tmp, g, sizeof tmp);
	for (int Q=read(); Q; Q--) {
		upd(read()), f[0]=mod-1;
		for (int i=1; i<=m; i++) {
			f[i]=0;
			for (int j=0; j<i; j++) dec(f[i], (ll)f[j]*g[j][i]%mod);
		}
		printf("%d\n", f[m]);
		for (int i=0; i<=m; i++)
			for (int j=i+1; j<=m; j++) g[i][j]=tmp[i][j];
	}
	return 0;
}