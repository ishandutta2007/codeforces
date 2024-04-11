#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n, x;
inline void work() {
	n=read(), x=read(); int ans=0, mn=1e9, mx=0;
	for (int i=1; i<=n; i++) {
		int v=read();
		mn=min(mn, v), mx=max(mx, v);
		if (mx-mn>2*x) mx=mn=v, ans++;
	}
	printf("%d\n", ans);
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}