#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, cnt[2];
vector<int> g[N];
void dfs(int u, int fa, bool d) {
	++cnt[d];
	for(auto v : g[u]) if(v != fa) 
		dfs(v, u, d ^ 1);
} 
int main() {
	scanf("%d", &n);
	for(int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0, 0);
	printf("%d\n", min(cnt[0], cnt[1]) - 1);
	return 0;
}