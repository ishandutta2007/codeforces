#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
namespace Flow {
	const int N = 200005, M = 3000005;
	int n, s, t, head[N], cnt, cur_head[N], d[N], que[N];
	struct edge {
		int to, nxt, cap;
	} e[M];
	inline void add_edge(int u, int v, int w) {
		e[++cnt] = {v, head[u], w};
		head[u] = cnt;
	}
	inline void add(int u, int v, int w) {
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}
	bool bfs() {
		int l = 1, r = 0;
		memset(d + 1, -1, n * 4);
		d[s] = 0;
		que[++r] = s;
		while (l <= r) {
			int u = que[l++];
			for (int i = head[u]; i; i = e[i].nxt) {
				if (!e[i].cap) continue;
				int v = e[i].to;
				if (~d[v]) continue;
				d[v] = d[u] + 1;
				if (v == t) return true;
				que[++r] = v;
			}
		}
		return false;
	}
	int dfs(int u, int flow) {
		if (u == t) return flow;
		int rest = flow;
		for (int &i = cur_head[u]; i && rest; i = e[i].nxt) {
			int v = e[i].to, w = e[i].cap;
			if (d[v] != d[u] + 1 || !w) continue;
			int val = dfs(v, min(rest, w));
			if (!val) {
				d[v] = -1;
			} else {
				rest -= val;
				e[i].cap -= val;
				e[i ^ 1].cap += val;
			}
		}
		return flow - rest;
	}
	int solve() {
		int res = 0;
		while (bfs()) {
			memcpy(cur_head + 1, head + 1, n * 4);
			res += dfs(s, inf);
		}
		return res;
	}
	void init(int _n, int _s, int _t) {
		n = _n, s = _s, t = _t;
		memset(head + 1, 0, n * 4);
		cnt = 1;
	}
}
const int N = 50005;
int n, a[N], b[N];
vector<int> d[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		b[a[i]] = i;
	Flow::init(n * 4 + 2, n * 4 + 1, n * 4 + 2);
	auto id_out = [&](int x) {
		return x;	
	};
	auto id_in = [&](int x) {
		return x + 2 * n;
	};
	for (int i = 1; i <= 2 * n; ++i) {
		Flow::add(Flow::s, id_out(i), 1);
		Flow::add(id_in(i), Flow::t, 1);
	}
	for (int i = 1; i <= n; ++i)
		Flow::add(id_out(i), id_in(i + n), 1);
	for (int i = 1; i <= n; ++i) {
		for (auto x : d[a[i]]) {
			int j = b[x];
			if (!j) continue;
			Flow::add(id_out(i), id_in(j), 1);
			Flow::add(id_out(i + n), id_in(j + n), 1);
		}
	}
	int ans = 2 * n - Flow::solve();
	printf("%d\n", n - ans);
	for (int i = 1; i <= n; ++i)
		b[a[i]] = 0;
}
int main() {
	for (int i = 1; i < N; ++i)
		for (int j = i + i; j < N; j += i)
			d[j].emplace_back(i);
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}