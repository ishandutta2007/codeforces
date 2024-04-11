#include <bits/stdc++.h>
using namespace std;
// is it hacked or not?
int n, k, T, q, pass[26], fine[26];
vector<pair<int, int>> g[200005];
char s[200005];
const int M = 20060223;
int tot, root[200005], ls[M], rs[M];
bool flag[M];
void modify(int &p, int q, int l, int r, int pos) {
	p = ++tot;
	flag[p] = true;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos) {
		rs[p] = rs[q];
		modify(ls[p], ls[q], l, mid, pos);
	} else {
		ls[p] = ls[q];
		modify(rs[p], rs[q], mid + 1, r, pos);
	}
}
bool query(int p, int l, int r, int ll, int rr) {
	if (!p || !flag[p]) {
		return false;
	}
	if (l >= ll && r <= rr) {
		return true;
	}
	int mid = (l + r) >> 1;
	bool res = false;
	if (mid >= ll) {
		res |= query(ls[p], l, mid, ll, rr);
	}
	if (mid < rr) {
		res |= query(rs[p], mid + 1, r, ll, rr);
	}
	return res;
}
inline int new_node(int p) {
	int q = ++tot;
	ls[q] = ls[p], rs[q] = rs[p];
	flag[q] = flag[p];
	return q;
}
void merge(int &p, int q) {
	if (!p && !q) {
		return;
	}
	if (!p || !q) {
		p = new_node(p | q);
		return;
	}
	p = new_node(p);
	merge(ls[p], ls[q]);
	merge(rs[p], rs[q]);
	flag[p] |= flag[ls[p]] || flag[rs[p]];
}
struct node {
	long long l[26], r[26];
	node() {
		memset(r, -1, sizeof r);
	}
	inline void push(int x, int y) {
		r[x] += y;
		for (int i = 0; i < x; ++i) {
			if (~r[i]) {
				l[i] += y;
				r[i] += y;
			}
		}
	}
} t[200005];
void dfs(int u, int fa) {
	modify(root[u], root[u], 0, T - 1, (t[u].r[s[u]] + 1) % T);
	for (auto p : g[u]) {
		int v = p.first, w = p.second;
		if (v == fa) {
			continue;
		}
		t[v] = t[u];
		t[v].push(s[v], w);
		dfs(v, u);
		if (s[v] == s[u]) {
			merge(root[u], root[v]);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		g[u].emplace_back(v, t);
		g[v].emplace_back(u, t);
	}
	scanf("%d", &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		s[i] -= 'A';
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &pass[i]);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d", &fine[i]);
	}
	scanf("%d", &T);
	dfs(1, 0);
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d ", &op);
		if (op <= 2) {
			char x;
			int y;
			scanf("%c %d", &x, &y);
			x -= 'A';
			if (op == 1) {
				pass[x] = y;
			} else {
				fine[x] = y;
			}
		} else {
			int u;
			scanf("%d", &u);
			int z = s[u];
			long long ans = 0;
			vector<pair<int, int>> events;
			auto add = [&](int l, int r, int x) {
				if (l <= r) {
					events.emplace_back(l, x);
					events.emplace_back(r + 1, -x);
				}
			};
			long long offset = t[u].r[z] + 1;
			for (int i = 0; i < z; ++i) {
				long long L = t[u].l[i], R = t[u].r[i];
				if (R == -1) {
					continue;
				}
				L -= offset;
				R -= offset;
				long long cnt = (R - L + T) / T;
				int pos = pass[i] / fine[i];
				if (cnt - 1 > pos) {
					ans += pass[i];
				} else {
					ans += fine[i] * (cnt - 1);
					int ed = (T - L % T) % T;
					int st = (ed - (R - L) % T + T) % T;
					int x = (cnt - 1 == pos) ? (pass[i] % fine[i]) : fine[i];
					if (st <= ed) {
						add(st, ed, x);
					} else {
						add(0, T - 1, x);
						add(ed + 1, st - 1, -x);
					}
				}
			}
			events.emplace_back(T, 0);
			sort(events.begin(), events.end());
			long long sum = 0;
			long long res = 1e18;
			int last = 0;
			for (auto it : events) {
				if (it.first > last) {
					if (query(root[u], 0, T - 1, last, it.first - 1)) {
						res = min(res, sum);
					}
					last = it.first;
				}
				sum += it.second;
			}
			ans += res;
			printf("%lld\n", ans);
		}
	}
	return 0;
}