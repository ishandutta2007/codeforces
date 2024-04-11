#include <bits/stdc++.h>

const int kMaxN = 2e4 + 5;

int n, m, ed[kMaxN], od[kMaxN], dep[kMaxN], tot = 0;
bool ans[kMaxN], ra_e[kMaxN];
std::vector<int> e[kMaxN], id[kMaxN];
void AddEdge(int u, int v, int idx) { e[u].push_back(v); id[u].push_back(idx); }
void Dfs(int cur, int fa) {
	for(int i = 0; i < e[cur].size(); ++i) {
		int v = e[cur][i], idx = id[cur][i];
		if(v == fa) continue;
		if(!dep[v]) { dep[v] = dep[cur] + 1; Dfs(v, cur); }
		else {
			int lop = dep[cur] - dep[v] + 1;
			if(lop <= 0) continue;
			if(lop % 2 == 0) ++ed[cur], --ed[v];
			else ++od[cur], ++tot, --od[v], ra_e[idx] = true;
		}
	}
}
bool vis[kMaxN]; int s1[kMaxN], s2[kMaxN];
void Dfs2(int cur, int f_idx) {
	vis[cur] = true;
	for(int i = 0; i < e[cur].size(); ++i) {
		int v = e[cur][i], idx = id[cur][i];
		if(idx == f_idx) continue;
		if(!vis[v]) {
			Dfs2(v, idx);
			s1[cur] += s1[v]; s2[cur] += s2[v];
		} else if(ra_e[idx] && tot == 1) ans[idx] = true;
	}
	s1[cur] += ed[cur]; s2[cur] += od[cur];
	if(s2[cur] == tot && !s1[cur]) ans[f_idx] = true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		AddEdge(u, v, i); AddEdge(v, u, i);
	}
	for(int i = 1; i <= n; ++i)
		if(!dep[i]) {
			dep[i] = 1;
			Dfs(i, 0);
		}
	if(!tot) {
		printf("%d\n", m);
		for(int i = 1; i <= m; ++i)
			printf("%d ", i);
	} else {
		for(int i = 1; i <= n; ++i)
			if(!vis[i]) Dfs2(i, 0);
		int cnt = 0;
		for(int i = 1; i <= m; ++i) cnt += ans[i];
		printf("%d\n", cnt);
		for(int i = 1; i <= m; ++i)
			if(ans[i]) printf("%d ", i);
	}
	return 0;
}