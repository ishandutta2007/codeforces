#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
namespace flow {
	const int N = 2005, M = 100005;
	int s, t, cnt = 1;
	int dis[N], que[N], head[N], cur_head[N];
	struct edge {
		int to, nxt;
		long long cap;
	} e[M];
	inline void add_e(int u, int v, long long w) {
		e[++cnt] = {v, head[u], w};
		head[u] = cnt;
	}
	inline void add(int u, int v, long long w) {
		add_e(u, v, w);
		add_e(v, u, 0);
	}
	bool bfs() {
		memset(dis, -1, (t + 1) * 4);
		dis[s] = 0;
		int l = 1, r = 0;
		que[++r] = s;
		while (l <= r) {
			int u = que[l++];
			for (int i = head[u]; i; i = e[i].nxt) {
				int v = e[i].to;
				long long w = e[i].cap;
				if (~dis[v] || !w) continue;
				dis[v] = dis[u] + 1;
				que[++r] = v;
			}
		}
		memcpy(cur_head, head, (t + 1) * 4);
		return ~dis[t];
	}
	long long dfs(int u, long long f) {
		if (u == t) return f;
		long long rest = f;
		for (int &i = cur_head[u]; i && rest; i = e[i].nxt) {
			int v = e[i].to;
			if (!e[i].cap || dis[v] != dis[u] + 1) continue;
			long long cur = dfs(v, min(rest, e[i].cap));
			if (!cur) dis[v] = -1;
			rest -= cur;
			e[i].cap -= cur;
			e[i ^ 1].cap += cur;
		}
		return f - rest;
	}
	long long solve() {
		long long res = 0;
		while (bfs())
			res += dfs(s, inf);
		return res;
	}
}
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, tot, x[1005], y[1005], w[1005], t[1005], id[1005][2];
map<pair<int, int>, int> rev;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		t[i] = ((y[i] & 1) << 1) | !((y[i] + x[i]) & 1);
		rev[{x[i], y[i]}] = i;
		if (t[i] == 0) {
			id[i][1] = ++tot;
		} else if (t[i] == 3) {
			id[i][0] = ++tot;			
		} else {
			id[i][0] = ++tot;			
			id[i][1] = ++tot;			
		}
	}
	flow::t = tot + 1;
	for (int i = 1; i <= n; ++i) {
		if (t[i] == 0) 
			flow::add(flow::s, id[i][1], w[i]); 	
		else if (t[i] == 3) 
			flow::add(id[i][0], flow::t, w[i]);
		else 
			flow::add(id[i][0], id[i][1], w[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < 4; ++k) {
			int x1 = x[i] + dx[k], y1 = y[i] + dy[k];
			if (!rev.count({x1, y1})) continue;
			int j = rev[{x1, y1}];
			if (t[j] == t[i] + 1) flow::add(id[i][1], id[j][0], inf);
		}
	}
	printf("%lld\n", accumulate(w + 1, w + n + 1, 0ll) - flow::solve());
	return 0;
}