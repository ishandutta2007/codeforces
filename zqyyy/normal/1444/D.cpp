#include <bits/stdc++.h>
using namespace std;
#define y1 __y1__
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1007;
int n, m, a[N], b[N];
bitset<N*N> f[N];
int sx, sy, c1, c2, d1, d2, x1[N], x2[N], y1[N], y2[N];
inline bool init() {
	f[0].set(0);
	for (int i=1; i<=n; i++) f[i]=f[i-1], f[i]|=f[i]<<a[i];
	int p=sx/2; if (!f[n].test(p)) return false;
	c1=c2=0;
	for (int i=n; i; i--)
		if (f[i-1].test(p)) x1[++c1]=a[i];
		else p-=a[i], x2[++c2]=a[i];
	for (int i=1; i<=m; i++) f[i]=f[i-1], f[i]|=f[i]<<b[i];
	p=sy/2; if (!f[m].test(p)) return false;
	d1=d2=0;
	for (int i=m; i; i--)
		if (f[i-1].test(p)) y1[++d1]=b[i];
		else p-=b[i], y2[++d2]=b[i];
	return true;	
}
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	m=read();
	for (int i=1; i<=m; i++) b[i]=read();
	sx=accumulate(a+1, a+n+1, 0), sy=accumulate(b+1, b+m+1, 0);
	if (n!=m || (sx&1) || (sy&1) || !init()) {puts("No"); return; }
	if (c1>d1) {
		if (c2<c1) {
			for (int i=1; i<=max(c1, c2); i++) swap(x1[i], x2[i]);
			swap(c1, c2);
		}
		if (d1<d2) {
			for (int i=1; i<=max(d1, d2); i++) swap(y1[i], y2[i]);
			swap(d1, d2);	
		}
	}
	assert(c1<=d1);
	sort(x1+1, x1+c1+1, greater<int>()), sort(x2+1, x2+c2+1, greater<int>());
	sort(y1+1, y1+d1+1), sort(y2+1, y2+d2+1);
	copy(x2+1, x2+c2+1, x1+c1+1), copy(y2+1, y2+d2+1, y1+d1+1);
	int x=0, y=0; puts("Yes");
	for (int i=1; i<=n; i++) {
		i<=c1?x+=x1[i]:x-=x1[i];
		printf("%d %d\n", x, y);
		i<=d1?y+=y1[i]:y-=y1[i];
		printf("%d %d\n", x, y);
	}
}
int main(){
#ifdef LOCAL
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while (test--) work();
	return 0;
}