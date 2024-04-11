#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=107;
int n, m, a[N];
ll ans1, ans2, v[N];
inline void work(int s) {
	for (int i=1; i<=n; i++) a[i]=v[i]%s;
	sort (a+1, a+n+1); int x=s/2, y=s-x;
	if (x==y) {
		int cnt=0;
		for (int i=1; i<=n; i++) cnt+=v[i]/x;
		cnt&1?ans1++:ans2++; x--, y++;
	}
	int p=upper_bound(a+1, a+n+1, x)-a-1, L=max(1, s-m);
	if (p) ckmax(L, a[p]+1);
	if (p<n) ckmax(L, s-a[p+1]);
	if ((n-p)&1) {
		if (n>1) ckmax(L, a[n-1]/2+1);
		if (L<=x) ans1+=(x-L+1)*2;
	} else {
		ckmax(L, a[n]/2+1);
		if (L<=x) ans2+=(x-L+1)*2;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=read();
	for (int i=1; i<=n; i++) v[i]=read();
	for (int s=2; s<=m+m; s++) work(s);
	ll ans=((ll)m*m-ans1-ans2)/2;
	printf("%lld %lld %lld %lld\n", ans, ans, ans1, ans2);
	return 0;
}