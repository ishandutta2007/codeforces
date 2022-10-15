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
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
const int N=507, M=6e5+7;
int n, m, Q, a[N][N];
char str[N];
struct Query {int x1, y1, x2, y2, id;} q[M], q1[M], q2[M];
bool ans[M];
bitset<N> f[N][N], g[N][N];
void solve(int l, int r, int ql, int qr) {
	if (l>r || ql>qr) return;
	int mid=(l+r)>>1;
	for (int i=l; i<=mid; i++)
		for (int j=1; j<=m; j++) f[i][j].reset();
	for (int i=mid; i<=r; i++)
		for (int j=1; j<=m; j++) g[i][j].reset();
	for (int i=1; i<=m; i++) if (a[mid][i]) f[mid][i].set(i), g[mid][i].set(i);
	for (int i=mid; i>=l; i--)
		for (int j=m; j; j--) {
			if (!a[i][j]) continue;
			if (i<mid) f[i][j]|=f[i+1][j];
			if (j<m) f[i][j]|=f[i][j+1];
		}
	for (int i=mid; i<=r; i++)
		for (int j=1; j<=m; j++) {
			if (!a[i][j]) continue;
			if (i>mid) g[i][j]|=g[i-1][j];
			if (j>1) g[i][j]|=g[i][j-1];
		}
	int c1=0, c2=0;
	for (int i=ql; i<=qr; i++)
		if (q[i].x2<mid) q1[++c1]=q[i];
		else if (q[i].x1>mid) q2[++c2]=q[i];
		else ans[q[i].id]=(f[q[i].x1][q[i].y1]&g[q[i].x2][q[i].y2]).any();
	for (int i=ql; i<=ql+c1-1; i++) q[i]=q1[i-ql+1];
	for (int i=qr-c2+1; i<=qr; i++) q[i]=q2[qr-i+1];
	solve(l, mid-1, ql, ql+c1-1), solve(mid+1, r, qr-c2+1, qr);
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), m=read();
	for (int i=1; i<=n; i++) {
		scanf("%s", str+1);
		for (int j=1; j<=m; j++) a[i][j]=str[j]=='.';
	}
	Q=read();
	for (int i=1; i<=Q; i++) q[i].x1=read(), q[i].y1=read(), q[i].x2=read(), q[i].y2=read(), q[i].id=i;
	solve(1, n, 1, Q);
	for (int i=1; i<=Q; i++) puts(ans[i]?"Yes":"No");
	return 0;
}