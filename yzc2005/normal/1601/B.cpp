#include <bits/stdc++.h>
using namespace std;
const int M = 2e6;
int n, a[M], b[M], prv[M], rp[M];
int id[M], cnt;
vector<pair<int, int>> g[M];
int dis[M];
inline void add(int u, int v, int w = 0) {
	g[u].emplace_back(v, w);
}
void build(int p, int l, int r) {
	if (l == r) {
		id[p] = l;
		return;
	}
	id[p] = ++cnt;
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	add(id[p], id[p << 1]);
	add(id[p], id[p << 1 | 1]);
}
void modify(int p, int l, int r, int ll, int rr, int u) {
	if (l >= ll && r <= rr) {
		add(u, id[p], 1);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= ll) modify(p << 1, l, mid, ll, rr, u);
	if (mid < rr) modify(p << 1 | 1, mid + 1, r, ll, rr, u);
}
int solve() {
	priority_queue<pair<int, int>> pq;
	memset(dis, 0x3f, sizeof dis);
	dis[n] = 0;
	pq.emplace(0, n);
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int u = p.second;
		if (dis[u] + p.first != 0) continue;
		for (auto it : g[u]) {
			int v = it.first, w = it.second;
			int tmp = v;
			if (tmp <= n) v = b[v];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				prv[v] = u;
				if (tmp <= n) rp[v] = tmp;
				pq.emplace(-dis[v], v);
			}
		}
	}
	return dis[0] >= 1e9 ? -1 : dis[0];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]), b[i] += i;
	cnt = n;
	build(1, 0, n);
	for (int i = 1; i <= n; ++i)
		if (a[i]) modify(1, 0, n, i - a[i], i - 1, i);
	int ans = solve();
	printf("%d\n", ans);
	if (~ans) {
		vector<int> nodes;
		int cur = 0;
		while (cur != n) {
			if (cur <= n) nodes.emplace_back(rp[cur]);
			cur = prv[cur];
		}
		reverse(nodes.begin(), nodes.end());
		for (auto x : nodes)
			printf("%d ", x); 
	}
	return 0;
}