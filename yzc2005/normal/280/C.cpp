#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
double ans;
vector<int> g[N];

void dfs(int u, int d, int f) {
	ans += (double) 1 / d;
	for(int i = 0; i < g[u].size(); ++i) if(g[u][i] != f) dfs(g[u][i], d + 1, u);
}

int main() {
	cin >> n;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 1, 0);
	printf("%lf", ans);
}