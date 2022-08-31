#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 200054, M = N * 2, INF = 0x3f3f3f3f;

int n, q, E = 0;
int to[M], first[N], next[M];
int p[N], dep[N], size[N];
int cnt = 0, o[N], id[N], eid[N], prf[N], top[N];
int count[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int max(const int x, const int y) {return x < y ? y : x;}

namespace BIT {
	int x[N];

	int sum(int h) {int s = 0; for (; h > 0; h &= h - 1) s += x[h]; return s;}
	void add(int h, int v) {for (; h <= n; h |= h - 1, ++h) x[h] += v;}
	int range(int l, int r) {return sum(r) - sum(l - 1);}
};

struct heap {
	std::priority_queue <pr> A, B;

	inline void emplace(const pr &x) {A.emplace(x);}
	inline void erase(const pr &x) {B.emplace(x);}
	inline void normalize() {for (; !B.empty() && A.top() == B.top(); A.pop(), B.pop());}
	inline pr top() {return normalize(), assert(!A.empty()), A.top();}
	inline bool pop() {return normalize(), !A.empty() && (A.pop(), true);}
	inline void clear() {for (; !A.empty(); A.pop()); for (; !B.empty(); B.pop());}
} H;

struct ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	int x[530000];

	void reset() {memset(x, 192, sizeof x);}

	void adj(int id, int L, int R, int h, int v) {
		if (L == R) {x[id] = v; return;}
		segc; h <= M ? adj(lc, L, M, h, v) : adj(rc, M + 1, R, h, v),
		x[id] = max(x[lc], x[rc]);
	}

	int range(int id, int L, int R, int ql, int qr) {
		if (ql <= L && R <= qr) return x[id];
		segc, s = -INF;
		if (ql <= M) up(s, range(lc, L, M, ql, qr));
		if (qr > M) up(s, range(rc, M + 1, R, ql, qr));
		return s;
	}
} A, B;

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y, &z = prf[x]; size[x] = !next[first[x]];
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dep[y] = dep[x] + 1,
			dfs(y), size[x] += size[y],
			size[y] > size[z] ? z = y : 0;
}

void dfs_hld(int x, int r) {
	int i, y; o[++cnt] = x, id[x] = cnt, top[x] = r;
	if (prf[x]) dfs_hld(prf[x], r);
	for (i = first[x]; i; i = next[i])
		if (!top[y = to[i]]) dfs_hld(y, y);
	eid[x] = cnt;
}

int LCA(int x, int y) {
	if (id[x] > id[y]) std::swap(x, y);
	if (id[y] <= eid[x]) return x;
	for (; id[x] < id[y]; y = p[top[y]]);
	return y;
}

int ancestor(int x, int D) {
	for (; dep[top[x]] > D; x = p[top[x]]);
	return o[id[x] - (dep[x] - D)];
}

void update(int x) {
	for (; x; x = p[top[x]])
		if (prf[x] && eid[prf[x]] != eid[x])
			B.adj(1, 1, n, id[x], A.range(1, 1, n, eid[prf[x]] + 1, eid[x]) - 2 * dep[x]);
}

inline void insert(int x) {++*count, ++count[x], A.adj(1, 1, n, id[x], dep[x]), H.emplace(pr(dep[x], x)), update(x);}
inline void erase(int x) {--*count, A.adj(1, 1, n, id[x], --count[x] ? dep[x] : -INF), H.erase(pr(dep[x], x)), update(x);}

int main() {
	int i, u, v, w, d, e, t, op; bool flag;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> q;
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1), dfs_hld(1, 1), A.reset(), B.reset();
	for (; q; --q)
		switch (cin >> op, op) {
			case 1:
				cin >> u >> v, insert(w = LCA(u, v)),
				BIT::add(id[u], 1), BIT::add(id[v], 1), BIT::add(id[w], -1);
				break;
			case 2:
				cin >> u >> v, erase(w = LCA(u, v)),
				BIT::add(id[u], -1), BIT::add(id[v], -1), BIT::add(id[w], 1);
				break;
			case 3:
				cin >> d, w = H.top().second;
				if (dep[w] <= d) {cout << "Yes\n"; break;}
				v = ancestor(w, dep[w] - d);
				if (dep[v] > d) {
					t = ancestor(v, dep[v] - d);
					if (BIT::range(id[t], eid[t]) != *count) {cout << "No\n"; break;}
				}
				flag = true, e = d - dep[v], t = v;
				for (; ; ) {
					u = top[t];
					if (u != t && B.range(1, 1, n, id[u], id[t] - 1) > e) {flag = false; break;}
					if (!(t = p[u])) break;
					if (A.range(1, 1, n, id[t] + 1, id[u] - 1) > e + 2 * dep[t]
					|| (eid[u] != eid[t] && A.range(1, 1, n, eid[u] + 1, eid[t]) > e + 2 * dep[t])) {flag = false; break;}
				}
				cout << (flag ? "Yes\n" : "No\n");
				break;
		}
	return 0;
}