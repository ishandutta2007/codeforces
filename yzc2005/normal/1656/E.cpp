#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
vector<int> e[N];
int f(int x) {
	if (x == 0) return 0;
	return (x & 1) ? 1 : -1; 
}
void dfs(int u, int fa, int d) {
	int sum = 0;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u, d + 1), sum += f(d + 1);
	}
	a[u] = f(d) - sum;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		e[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], " \n"[i == n]);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}