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
const int MN = 1e5 + 44;
VI graf[MN];
VPII ans;
int nr[MN];
int low[MN];
int timer = 0;
void err() {
	printf("0\n");
	exit(0);
}
void dfs(int x, int y = -1) {
	nr[x] = low[x] = ++timer;
	for (auto v : graf[x]) {
		if (v != y) {
			if (nr[v] == 0) {
				ans.PB(MP(x, v));
				dfs(v, x);
				mini(low[x], low[v]);
			}
			else if (nr[v] < nr[x]) {
				ans.PB(MP(x, v));
				mini(low[x], nr[v]);
			}
		}
	}
	if (low[x] == nr[x] && y != -1)
		err();
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
	}
	dfs(1);
	for (auto x : ans)
		printf("%d %d\n", x.f, x.s);
}