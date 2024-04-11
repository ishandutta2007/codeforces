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
const int N=507;
int n, a[N], sum[N], f[N][N][N];
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read(), sum[i]=sum[i-1]+a[i];
	memset(f, 0xc0, sizeof f), f[0][0][0]=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<=i; j++) {
			int mx=0;
			for (int k=0; k<=i; k++) {
				int v=f[i][j][k];
				ckmax(mx, v), ckmax(f[i+1][j+1][k], v+a[k]);
			}
			ckmax(f[i+1][j][i+1], mx+a[i+1]);
			for (int k=i; k<=min(n, 2*i); k++) {
				int v=f[i][j][k];
				ckmax(f[i+1][j+1][k], v+a[k]), ckmax(mx, v);
				int l=k+1, len=l-i-1;
				if (j+len<=i+1) ckmax(f[i+1][j+len][l], mx+a[l]);
			}
			int l=2*i+2, len=l-i-1;
			if (j+len<=i+1) ckmax(f[i+1][j+len][l], mx+a[l]);
		/*	for (int k=i+2; k<=min(n, 2*i+2); k++) {
				int p=(i+k+1)/2;
				ckmax(f[p][j+k-p][k], mx+sum[p-1]-sum[i]+a[k]);
			}*/
		}
	int ans=sum[n];
	for (int j=0; j<=n; j++)
		for (int k=1; k<=n; k++) ckmax(ans, f[n][j][k]);
	printf("%d\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=1; //read();
	while (test--) work();
	return 0;
}