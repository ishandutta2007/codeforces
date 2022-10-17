#include <bits/stdc++.h>
using namespace std;
int n, m;
bool to[55][55];
vector<int> g[55][55];
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		to[u][v] = true;
		g[u][v].resize(k);
		for (auto &x : g[u][v])
			scanf("%d", &x);
	}
	int lim = 2 * n;
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			if (!to[u][v]) continue;
			auto p1 = find(g[u][v].begin(), g[u][v].end(), u);
			if (p1 == g[u][v].end()) continue;
			auto p2 = p1 + 1;
			if (p2 == g[u][v].end() || *p2 != v) continue;
			deque<int> rest;
			for (++p2; p2 != g[u][v].end(); ++p2)
				rest.emplace_back(*p2);
			int cur = v;
			int cnt = 1;
			deque<int> path = {u, v}; 
			while (!rest.empty() && cnt <= lim) {
				int nxt = rest.front();
				if (!to[cur][nxt]) break;
				rest.pop_front();
				++cnt;
				for (auto p : g[cur][nxt])
					rest.emplace_back(p);
				cur = nxt;
				path.emplace_back(cur);
			}
			if (!rest.empty() || cnt > lim) continue;
			if (p1 != g[u][v].begin()) {
				do {
					rest.emplace_front(*(--p1));
				} while (p1 != g[u][v].begin());
			}
			cur = u;
			while (!rest.empty() && cnt <= lim) {
				int nxt = rest.back();
				if (!to[nxt][cur]) break;
				rest.pop_back();
				++cnt;
				reverse(g[nxt][cur].begin(), g[nxt][cur].end());
				for (auto p : g[nxt][cur])
					rest.emplace_front(p);
				reverse(g[nxt][cur].begin(), g[nxt][cur].end());
				cur = nxt;
				path.emplace_front(cur);
			}
			if (!rest.empty() || cnt > lim) continue;
			printf("%d\n", (int) path.size());
			for (auto x : path)
				printf("%d ", x);
			exit(0);
		}
	}
	puts("0");
	return 0;
}