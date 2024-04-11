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

#define long long long 
const int N = 300005;
const long INF = 0x3f3f3f3f3f3f3f3f;
vector <int> e[N];
int a[N];
long val[N], mx=-INF;
int n;

void dfs1(int u, int f) {
	val[u] = a[u];
	for (int v: e[u]) if (v!=f) {
		dfs1(v,u);
		val[u] += max(0LL, val[v]); }
	checkMax(mx, val[u]); }

int cnt = 0;
void dfs2(int u, int f) {
	val[u] = a[u];
	for (int v: e[u]) if (v!=f) {
		dfs2(v,u);
		val[u] += max(0LL, val[v]); }
	if (val[u] == mx) {
		val[u] = -INF; cnt++; } }

int main() {
	scanf("%d",&n);
	repa (i,n) scanf("%d",&a[i]);
	rep (i,n-1) { int u,v; scanf("%d%d",&u,&v); e[u].push_back(v); e[v].push_back(u); }
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld %d\n", mx*cnt, cnt);
	return 0;
}