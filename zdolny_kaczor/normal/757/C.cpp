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
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif

#define hash kbxsta
#define count asntoehu
const int MN = 1e6 + 44;
#define fac f
const int MOD = 1e9 + 7;
LL f[MN];
map <int, int> type[MN];
LL hv[MN * 2];
LL hash(map <int, int> &m) {
	debug("hash:\n");
	LL res = 0;
	int i = 0;
	for (auto & x: m) {
		debug("%d %d\n", x.first, x.second);
		i++;
		res += x.first * hv[i * 2] + x.second * hv[i * 2 + 1];
		res *= 11;
	}
	return res;
}
map <LL, int> c2;
int main() {
	f[0] = 1;
	for (int i = 0; i < 2 * MN; ++i)
		hv[i] = 2 * rand() + (((LL)rand()) << 33) + 1;
	for (int i = 1; i < MN; ++i)
		f[i] = f[i - 1] * i % MOD;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int g;
		scanf("%d", &g);
		while (g--) {
			int x;
			scanf("%d", &x);
			type[x][i]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		c2[hash(type[i])]++;
	}
	LL res = 1;
	for (auto & x : c2) {
		debug("add %d\n", x.second);
		res = res * fac[x.second] % MOD;
	}
	printf("%lld\n", res);
}