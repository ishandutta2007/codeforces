#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
const int N=7, M=15625, inf=5e8;
constexpr int pw[7]={1, 5, 25, 125, 625, 3125, 15625};
int n, m, a[N], b[N], c[N][N], f[N][M];
inline void decode(int x, int *a) {
	for (int i=1; i<=m; i++) a[i]=x%5, x/=5;
}
inline int encode(int *a) {
	int x=0;
	for (int i=m; i; i--) x*=5, x+=a[i];
	return x;
}
int now[N];
void dfs(int i, int j, int v, int x) {
	if (j==m+1) {
		if (!x) ckmin(f[i][encode(now)], v);
		return;
	}
	dfs(i, j+1, v, x); int lim=min(x, now[j]);
	for (int k=1; k<=lim; k++)
		now[j]-=k, dfs(i, j+1, v+c[i][j], x-k), now[j]+=k;
}
int main(){
#ifdef LOCAL
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read();
	for (int i=1; i<=m; i++) b[i]=read();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) c[i][j]=read();
	memset(f, 0x3f, sizeof(f)), f[0][encode(b)]=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<pw[m]; j++)
			if (f[i][j]<inf) decode(j, now), dfs(i+1, 1, f[i][j], a[i+1]);
	int mn=*min_element(f[n], f[n]+pw[m]);
	printf("%d\n", mn>inf?-1:mn);
	return 0;
}