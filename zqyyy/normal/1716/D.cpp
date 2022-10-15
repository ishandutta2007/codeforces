#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=2e5+7, mod=998244353;
inline void inc(int &x, int y) {x+=y-mod, x+=x>>31&mod;}
int n, K, ans[N], f[N];
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), K=read(), f[0]=1;
	do {
		for (int i=0; i<K; i++) {
			int v=0;
			for (int j=i; j<=n; j+=K)
				swap(v, f[j]), inc(v, f[j]), inc(ans[j], f[j]);
		}
		K++;
	} while (K<=n && count(f, f+n+1, 0)<=n);
	for (int i=1; i<=n; i++) printf("%d%c", ans[i], " \n"[i==n]);
	return 0;
}