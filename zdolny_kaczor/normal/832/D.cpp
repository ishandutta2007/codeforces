#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#define cerr if(0) cerr
#endif
const int MN = 1e5 + 44;
const int LOG = 17;
VI un[MN];
int jump[MN][LOG];
int dep[MN];
int in[MN], out[MN];
void dfs(int x, int y, int d) {
	jump[x][0] = y;
	static int timer = 0;
	dep[x] = d;
	in[x] = timer++;
	for (auto v : un[x])
		if (v != y) {
			dfs(v, x, d + 1);
		}
	out[x] = timer++;
}
bool under(int x, int y) {
	return in[x] >= in[y] && out[x] <= out[y];
}
int lca(int a, int b) {
	if (under(b, a))
		return a;
	for (int i = LOG - 1; i >= 0; --i) {
		int aa = jump[a][i];
		if (!under(b, aa))
			a = aa;
	}
	return jump[a][0];
}
int len(int a, int b) {
	return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		un[x].PB(i);
		un[i].PB(x);
	}
	dfs(1, 1, 0);
	for (int i = 1; i < LOG; ++i)
		for (int v = 1; v <= n; ++v)
			jump[v][i] = jump[jump[v][i - 1]][i - 1];
	while (q--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int x = lca(a, b) ^ lca(b, c) ^ lca(c, a);
		printf("%d\n", 1 + max(len(a, x), max(len(b, x), len(c, x))));
	}
}