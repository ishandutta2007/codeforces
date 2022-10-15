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
const int N=1e5+7;
int n, K, a[N];
inline void work() {
	n=read(), K=read();
	for (int i=1; i<=n; i++) a[i]=read();
	ll ans=0, res=0;
	for (int i=1; i<=n; i++) {
		ll sum=res;
		for (int j=i, pw=1; j<=min(i+29, n); j++)
			pw<<=1, sum+=a[j]/pw;
		ckmax(ans, sum), res+=a[i]-K;
	}
	ckmax(ans, res), printf("%lld\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}