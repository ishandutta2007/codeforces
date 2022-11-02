#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
using namespace std;

const int maxn = 2e5;
int n, w, b;
vector<int> G[maxn + 5];

void dfs(int u, int x, int f = 0) {
	x == 0 ? w++ : b++;
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == f) continue;
		dfs(v, x ^ 1, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", min(w, b) - 1);
	return 0;
}