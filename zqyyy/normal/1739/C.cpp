#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=127, mod=998244353, inf=0x3f3f3f3f;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, C[N][N], d[N];
inline void work() {
	n=read(); int ans1=0, ans2=0;
	for (int i=n/2, o=1; i>0; i--) {
		inc(o?ans1:ans2, C[i+i-1][i]);
		inc(o?ans2:ans1, C[i+i-2][i]);
		o^=1;
	}
	cout<<ans1<<" "<<ans2<<" 1\n";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	C[0][0]=1, n=120;
	for (int i=1; i<=n; i++) {
		C[i][0]=1;
		for (int j=1; j<=i; j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	int test=read();
	while (test--) work();
	return 0;
}