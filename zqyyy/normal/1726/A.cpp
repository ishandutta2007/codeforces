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
const int N=2007;
int n, a[N];
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	if (n==1) {printf("%d\n", 0); return;}
	int ans=-1000;
	for (int i=1; i<n; i++) ckmax(ans, a[i]-a[i+1]);
	ckmax(ans, *max_element(a+2, a+n+1)-a[1]);
	ckmax(ans, a[n]-*min_element(a+1, a+n));
	printf("%d\n", ans);
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}