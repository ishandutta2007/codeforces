#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
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
#endif
using namespace std;
const int MN = 5e3 + 44;
pair <int, int> dp[MN][MN];
vector <pair <int, int> > graph[MN];
bool visited[MN];
int n, m, t;
const int inf = 1e9 + 44;
void calc(int x) {
	for (int i = 1; i <= n; ++i)
		dp[x][i] = make_pair(inf, inf);
	debug("calc %d\n", x);
	for (auto e : graph[x]) {
		for (int i = 1; i <= n; ++i) {
			pair <int, int> candidate = make_pair(min(inf, dp[e.first][i - 1].first + e.second), e.first);
			dp[x][i] = min(dp[x][i], candidate);
		}
	}
	if (x == n)
		dp[x][0] = make_pair(0, 0);
	else
		dp[x][0] = make_pair(inf, inf);
}
void dfs(int x) {
	debug("dfs %d\n", x);
	if (visited[x])
		return;
	visited[x] = true;
	for (auto v : graph[x])
		dfs(v.first);
	calc(x);
}
int main() {
	debug("%d\n", 2 * (int)(1e9 + 44));
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			dp[i][k].first = 1e9 + 44;
		}
	}
	dp[n][1] = make_pair(0, 0);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].emplace_back(b, c);
	}
	int res = 0;
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		debug("dp[1][i = %d] = (%lld, %d)\n", i, dp[1][i].first, dp[1][i].second);
		if (dp[1][i].first <= t) {
			res = max(res, i);
		}
	}
	printf("%d\n", res + 1);
	int wh = 1;
	while (wh != n) {
		printf("%d ", wh);
		wh = dp[wh][res].second;
		res--;
	}
	printf("%d\n", n);
}