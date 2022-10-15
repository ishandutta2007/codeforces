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
const int N=2e5+7, mod=998244353, inf=0x3f3f3f3f;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, a[N], b[N], c[N], d[N];
inline void clear() {}
inline void work() {
	n=read(); ll ans=0;
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=n; i++) ans+=b[i]=read();
	int c0=0, c1=0;
	for (int i=1; i<=n; i++) (a[i]?c[++c0]:d[++c1])=b[i];
	sort (c+1, c+c0+1, greater<int>());
	sort (d+1, d+c1+1, greater<int>());
	for (int i=1; i<=min(c0, c1); i++) ans+=c[i]+d[i];
	if (c0==c1) ans-=min(c[c0], d[c1]);
	cout<<ans<<'\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work(), clear();
	return 0;
}