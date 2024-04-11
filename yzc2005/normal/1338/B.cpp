#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, d[N], mx;
vector<int> g[N];
bool f0, f1;

void dfs(int u, int fa, int dep) {
	if(d[u] == 1) {
		if(dep & 1) f1 = 1;
		else f0 = 1;
	}
	int cnt = 0;
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u, dep + 1);
		cnt += (d[v] == 1);
	}
	if(cnt) mx -= cnt - 1;
}

int main() {
	scanf("%d", &n), mx = n - 1;
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].emplace_back(v), g[v].emplace_back(u);
		++d[u], ++d[v];
	}
	for(int i = 1; i <= n; ++i) 
		if(d[i] > 1) {
			dfs(i, 0, 0);
			break;
		}
	printf("%d %d\n", 1 + (f0 && f1) * 2, mx);
}