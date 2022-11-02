#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fi first
#define se second
using namespace std;

const int maxn = 2e5;
int n, k, sz[maxn + 3], dep[maxn + 3], a[maxn + 3];
vector<int> G[maxn + 3];

void add(int u, int v) {
	G[u].push_back(v);
}

void dfs(int u, int p = 0) {
	sz[u] = 1;
	rep(i, 0, G[u].size() - 1) {
		int v = G[u][i];
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int main() {
	scanf("%d %d", &n, &k);
	rep(i, 1, n - 1) {
		int u, v; scanf("%d %d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1);
	rep(i, 1, n) a[i] = dep[i] - (sz[i] - 1);
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
	long long res = 0;
	rep(i, 1, k) res += a[i];
	printf("%lld\n", res);
	return 0;
}