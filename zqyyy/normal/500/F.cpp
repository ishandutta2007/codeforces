#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=4007, M=20007;
struct node {int c, h, t;} a[N];
struct Query {int a, b, id;} q[M];
int n, m, p, Q, f1[N][N], f2[N], ans[M];
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=4000, p=read();
	for (int i=1; i<=n; i++) a[i].c=read(), a[i].h=read(), a[i].t=read();
	sort (a+1, a+n+1, [](auto x, auto y) {return x.t<y.t;});
	Q=read();
	for (int i=1; i<=Q; i++) q[i].a=read(), q[i].b=read(), q[i].id=i;
	sort(q+1, q+Q+1, [](auto x, auto y) {return x.a<y.a;});
	for (int i=1, l=1, r=0, mid=0; i<=Q; i++) {
		while (r<n && a[r+1].t<=q[i].a) {
			r++;
			for (int j=m; j>=a[r].c; j--) ckmax(f2[j], f2[j-a[r].c]+a[r].h);
		}
		while (l<=r && a[l].t+p-1<q[i].a) {
			l++;
			if (l>mid) {
				mid=r;
				for (int j=0; j<=m; j++) f2[j]=f1[mid+1][j]=0;
				for (int k=mid; k>=l; k--) {
					for (int j=0; j<=m; j++) f1[k][j]=f1[k+1][j];
					for (int j=a[k].c; j<=m; j++)
						ckmax(f1[k][j], f1[k+1][j-a[k].c]+a[k].h);
				}
			}
		}
		for (int j=0; j<=q[i].b; j++) ckmax(ans[q[i].id], f1[l][j]+f2[q[i].b-j]);
	}
	for (int i=1; i<=Q; i++) printf("%d\n", ans[i]);
	return 0;
}