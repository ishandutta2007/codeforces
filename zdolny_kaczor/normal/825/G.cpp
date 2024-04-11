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
#define cc(x) x.f, x.s
const int MN = 1e6 + 44;
VI graf[MN];
int m[MN];
void dfs(int x, int y = -1, int mi = MN) {
	mini(mi, x);
	m[x] = mi;
	for (auto v : graf[x])
		if (v != y)
			dfs(v, x, mi);
}
int main() {
	int minim = MN;
	int n, q;
	scanf("%d%d", &n, &q);
	int last = 0;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
	}
	bool first = true;
	for (int i = 0; i < q; ++i) {
		int t, x;
		scanf("%d%d", &t, &x);
		x += last;
		x %= n;
		x++;
		if (t == 1) {
			debug("color vertex %d\n");
			if (first) {
				dfs(x);
				first = false;
			}
			mini(minim, m[x]);
		}
		else {
			last = min(minim, m[x]);
			debug("ans[%d]:", x);
			printf("%d\n", last);
		}
	}
}