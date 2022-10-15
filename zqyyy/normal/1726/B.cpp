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
inline void work() {
	int n=read(), m=read();
	if ((m<n) || (n%2==0 && m%2==1)) {puts("No"); return;}
	puts("Yes");
	if (n&1) {
		for (int i=1; i<n; i++) printf("1 ");
		printf("%d\n", m-n+1);
	} else {
		for (int i=1; i<=n-2; i++) printf("1 ");
		m-=n-2;
		printf("%d %d\n", m/2, m/2);
	}
}
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	int test=read();
	while (test--) work();
	return 0;
}