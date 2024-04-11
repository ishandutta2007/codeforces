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
ll n, r1, c1, r2, c2, r3, c3, x, y;
inline void work() {
	n=read(), r1=read(), c1=read(), r2=read(), c2=read(), r3=read(), c3=read(), x=read(), y=read();
	ll r=r1==r2?r1:r3, c=c1==c2?c1:c3;
	if (r%2!=x%2 && c%2!=y%2) puts("NO");
	else if ((r==1 || r==n) && (c==1 || c==n)) {
		if (x==r || y==c) puts("YES");
		else puts("NO");
	} else puts("YES");
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