#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1007;
int n, K, f[N][N], x[N], y[N];
char a[N][N], ans[N][N];
inline void work() {
	n=read(), K=read();
	for (int i=1; i<=n; i++) scanf("%s", a[i]+1);
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=n+1; j++) f[i][j]=0, ans[i][j]='0';
	for (int i=1; i<K; i++) x[i]=y[i]=0, a[i][n]=a[n][i]='0', f[n][i]=f[i][n]=K-i;
	for (int i=n; i; i--)
		for (int j=n; j; j--) {
			ckmax(f[i][j], max({f[i][j+1], f[i+1][j], f[i+1][j+1]+(a[i][j]=='0')}));
			if (f[i][j]==K) {puts("NO"); return;}
		}
	for (int i=n; i; i--)
		for (int j=1; j<=n; j++) {
			if (a[i][j]=='1') continue;
			int p=f[i][j];
			if (x[p]) {
				for (int k=x[p]; k>=i; k--) ans[k][y[p]]='1';
				for (int k=y[p]; k<=j; k++) ans[i][k]='1';
			}
			x[p]=i, y[p]=j;
		}
	puts("YES");
	for (int i=1; i<=n; i++, putchar(10))
		for (int j=1; j<=n; j++) putchar(ans[i][j]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	for (int T=read(); T; T--) work();
	return 0;
}