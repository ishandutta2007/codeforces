#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1e5+7;
int n, m, a[N], b[N];
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=m; i++) a[i]=read();
	sort(a+1, a+m+1);
	for (int i=1; i<m; i++) b[i]=a[i+1]-a[i]-1;
	b[m]=a[1]-1+n-a[m], sort(b+1, b+m+1, greater<int>());
	int ans=0, num=0;
	for (int i=1; i<=m; i++) {
		b[i]-=num;
		if (b[i]<=0) break;
		ans++, b[i]-=2, num+=2;
		if (b[i]<=0) break;
		ans+=b[i], num+=2;
	}
	printf("%d\n", n-ans);
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