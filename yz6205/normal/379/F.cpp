#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
template <typename T> bool checkMax(T& a, T b) { return a<b ? a=b,1 : 0; }
template <typename T> bool checkMin(T& a, T b) { return b<a ? a=b,1 : 0; }
#ifdef __LOCALE__
#define ses(a) cout << #a << "=" << a << ' '
#define see(a) cout << #a << "=" << a << endl
#else
#define ses(a)
#define see(a)
#endif

const int N = 1000005;
const int B = 24;
int fa[N][B], d[N];
int n;

void getFa(int u, int f) {
	fa[u][0] = f; d[u] = d[f] + 1;
	rep (i,B-1) fa[u][i+1] = fa[ fa[u][i] ][i]; }

void up(int& u, int d) {
	rep (i,B) { if ((d>>i) & 1) { u = fa[u][i]; } } }
int lca(int u, int v) {
	if (d[u] < d[v]) { swap(u,v); } up(u, d[u] - d[v]);
	for (int i=B-1;i>=0;i--) { if (fa[u][i] != fa[v][i]) { u=fa[u][i]; v=fa[v][i]; } } 
	return u==v ? u : fa[u][0]; }
int dis(int u, int v) {
	return d[u] + d[v] - 2*d[ lca(u,v) ]; }

int main() {
	scanf("%d",&n);
	getFa(1,0); getFa(2,1); getFa(3,1); getFa(4,1);
	int la = 2, lb = 3, cur = 2;
	int ecnt = 5;
	rep (i,n) {
		int u; scanf("%d",&u);
		getFa(ecnt, u); 
		if ( checkMax(cur, dis(ecnt, la)) ) {
			lb = ecnt; }
		if ( checkMax(cur, dis(ecnt, lb)) ) {
			la = ecnt; }
		ecnt++;
		getFa(ecnt, u); 
		if ( checkMax(cur, dis(ecnt, la)) ) {
			lb = ecnt; }
		if ( checkMax(cur, dis(ecnt, lb)) ) {
			la = ecnt; }
		ecnt++; 
		printf("%d\n", cur); }
	return 0;
}