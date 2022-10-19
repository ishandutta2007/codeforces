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
//(2x+1)
ll l, r;
inline void work() {
	l=read(), r=read();
	ll L=sqrtl(l), R=sqrtl(r);
	auto calc=[&](ll l, ll r, ll x)->ll{
		l=((l-1)/x+1)*x;
		return l<=r?(r-l)/x+1:0;
	};
	if (L==R) {
		printf("%lld\n", calc(l, r, L));
		return;
	}
	ll ans=calc(l, (L+1)*(L+1)-1, L)+calc(R*R, r, R);
	L++, R--, ans+=3*(R-L+1);
	printf("%lld\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}