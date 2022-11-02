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

namespace Math {
	int gcd(int a, int b) { return b==0 ? a : gcd(b, a%b); }
	vector <int> primeFactor(int u) {
		vector <int> res;
		for (int i=2;i*i<=u;i++) {
			if (u%i == 0) { 
				res.push_back(i);
				while (u%i==0) { u/=i; } } }
		if (u!=1) { res.push_back(u); }
		return res; }
}

const int N = 100005;
const int M = 2000005;
vector <int> e[N];
int d[N], a[N], ans[N];
int n,q;

vector <int> pl[M];

void dfs(int u, int f) {
	ses(u);see(f);
	d[u] = d[f] + 1; ans[u] = 0;
	vector<int> fac = Math::primeFactor( a[u] );
	for (vector<int>::iterator it=fac.begin(); it!=fac.end(); it++) {
		if (d[ ans[u] ] < d[ pl[*it].back() ]) { ans[u] = pl[*it].back(); } 
		pl[*it].push_back(u); }
	for (vector<int>::iterator it=e[u].begin(); it!=e[u].end(); it++) if (*it != f) {
		dfs(*it, u); }
	for (vector<int>::iterator it=fac.begin(); it!=fac.end(); it++) {
		pl[*it].pop_back(); } }

int main() {
	scanf("%d%d",&n,&q);
	repa (i,n) { scanf("%d",&a[i]); }
	rep (i,n-1) { int u,v; scanf("%d%d",&u,&v); e[u].push_back(v); e[v].push_back(u); }
	rep (i,M) pl[i].push_back(0);
	dfs(1,0);
	while (q--) {
		int opt; scanf("%d",&opt);
		if (opt == 1) {
			int u; scanf("%d",&u);
			printf("%d\n", ans[u] == 0 ? -1 : ans[u]); }
		else {
			int u, w; scanf("%d%d", &u,&w);
			a[u] = w;
			dfs(1,0); } }
	while ((double)(clock()) / CLOCKS_PER_SEC < 9.8);
	return 0;
}