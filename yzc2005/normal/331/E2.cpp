#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
inline void add(int &x, int y) {
	(x += y) >= P && (x -= P);	
}
int n, m;
bool to[55][55];
vector<int> g[55][55];
int f[55][55][105], st[55][105], ed[55][105];
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
			while (!rest.empty() && cnt <= lim) {
				int nxt = rest.front();
				if (!to[cur][nxt]) break;
				rest.pop_front();
				++cnt;
				for (auto p : g[cur][nxt])
					rest.emplace_back(p);
				cur = nxt;
			}
			if (!rest.empty() || cnt > lim) continue;
			int ed = cur;
			rest.clear();
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
			}
			if (!rest.empty() || cnt > lim) continue;
			int st = cur;
			++f[st][ed][cnt];
		}
	}
	vector<tuple<int, int, int>> tr;
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			if (g[u][v].empty() || g[u][v].back() != u) continue;
			deque<int> rest;
			auto it = --g[u][v].end();
			int cnt = 1;
			if (it != g[u][v].begin()) {
				do {
					rest.emplace_front(*(--it));
				} while (it != g[u][v].begin());
			}
			int cur = u;
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
			}
			if (!rest.empty() || cnt > lim) continue;
			tr.emplace_back(cur, v, cnt);
		}
	}
	for (int i = 1; i <= 2 * n; ++i) {
		for (auto p : tr) {
			int u = get<0>(p), v = get<1>(p), d = get<2>(p);
			if (i < d) continue;
			for (int w = 1; w <= n; ++w)
				add(f[u][w][i], f[v][w][i - d]);
		}
	}
	tr.clear();
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			if (g[u][v].empty() || g[u][v][0] != v) continue;
			deque<int> rest;
			auto it = ++g[u][v].begin();
			while (it != g[u][v].end())
				rest.emplace_back(*(it++));
			int cur = v;
			int cnt = 1;
			while (!rest.empty() && cnt <= lim) {
				int nxt = rest.front();
				if (!to[cur][nxt]) break;
				rest.pop_front();
				++cnt;
				for (auto p : g[cur][nxt])
					rest.emplace_back(p);
				cur = nxt;
			}
			if (!rest.empty() || cnt > lim) continue;
			tr.emplace_back(u, cur, cnt);
		}
	}
	for (int i = 1; i <= 2 * n; ++i) {
		for (auto p : tr) {
			int u = get<0>(p), v = get<1>(p), d = get<2>(p);
			if (i < d) continue;
			for (int w = 1; w <= n; ++w)
				add(f[w][v][i], f[w][u][i - d]);
		}
	}
	vector<pair<int, int>> tr1;
	for (int u = 1; u <= n; ++u)
		for (int v = 1; v <= n; ++v)
			if (to[u][v] && g[u][v].empty()) tr1.emplace_back(u, v);
	for (int i = 1; i <= 2 * n; ++i) {
		for (int u = 1; u <= n; ++u)
			for (int v = 1; v <= n; ++v)
				add(ed[v][i], f[u][v][i]);
		for (auto p : tr1) {
			int u = p.first, v = p.second;
			add(st[v][i], ed[u][i - 1]);
		}
		for (int u = 1; u <= n; ++u) {
			for (int v = 1; v <= n; ++v) {
				for (int j = 1; j < i; ++j) {
					int v1 = f[u][v][j], v2 = st[u][i - j];
					if (!v1 || !v2) continue;
					add(ed[v][i], 1ull * v1 * v2 % P);
				}
			} 
		}
	}
	for (int i = 1; i <= 2 * n; ++i) {
		int ans = 0;
		for (int u = 1; u <= n; ++u)
			add(ans, ed[u][i]);
		printf("%d\n", ans);
	}
	return 0;
}