#include <bits/stdc++.h>

const int kN = 2e5 + 5;

int col[kN], fa[kN], ans[kN], d[kN]; std::vector<int> E[kN];
void Dfs(int cur) {
	for(auto x : E[cur])
		if(x != fa[cur]) {
			fa[x] = cur; Dfs(x);
			if(d[x] > 0) d[cur] += d[x];
		}
}
void GetAns(int cur) {
	if(d[cur] >= 0) ans[cur] = std::max(ans[fa[cur]], d[cur]);
	else ans[cur] = std::max(ans[fa[cur]] - 1, d[cur]);
	for(auto x : E[cur])
		if(x != fa[cur]) GetAns(x);
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", d + i), d[i] = d[i] ? 1 : -1;
	for(int i = 1; i < n; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		E[u].push_back(v); E[v].push_back(u);
	}
	Dfs(1); ans[1] = d[1];
	for(auto x : E[1]) GetAns(x);
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	return 0;
}