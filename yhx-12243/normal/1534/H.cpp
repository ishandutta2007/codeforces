#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::endl;

typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 100054, M = N * 2, INF = 0x3f3f3f3f;

int n, root;
int p[N], prf[N];
int f[N], fp[N], F[N];
int response[N];
vector G[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline int query(int x) {
	if (!response[x]) cout << '?' << ' ' << x << endl, cin >> response[x];
	return response[x];
}

void dfs(int x, bool sort_child = false) {
	int i, c = 0;
	static int buf[N];
	for (int y : G[x]) if (y != p[x]) p[y] = x, dfs(y, sort_child);
	fprintf(stderr, "dfs %d p = %d\n", x, p[x]);
	G[x].erase(std::remove(G[x].begin(), G[x].end(), p[x]), G[x].end());
	for (int y : G[x]) buf[c++] = f[y];
	std::sort(buf, buf + c, std::greater <int> ());
	for (f[x] = 1, i = 0; i < c; ++i) up(f[x], buf[i] + i);
	if (sort_child)
		std::sort(G[x].begin(), G[x].end(), [] (const int x, const int y) {return f[x] > f[y];}),
		prf[x] = G[x].empty() ? x : prf[G[x].front()];
}

void dfs2(int x) {
	int i, y, c = 0, pre = 1;
	static pr buf[N]; buf[c++] = pr(fp[x], -1);
	static int suf[N];
	for (int y : G[x]) buf[c++] = pr(f[y], y);
	std::sort(buf, buf + c, std::greater <pr> ());
	for (i = 1; i < c; ++i) up(F[x], buf[i].first + i - 1);
	F[x] += buf->first, suf[c] = -INF;
	for (i = c - 1; i >= 0; --i) suf[i] = max(suf[i + 1], buf[i].first + i);
	for (i = 0; i < c; ++i) {
		if (~(y = buf[i].second)) fp[y] = max(pre, suf[i + 1] - 1);
		up(pre, buf[i].first + i);
	}
	for (int y : G[x]) dfs2(y);
}

int solve_in_subtree(int x) {
	if (x == root) return root;
	for (int y : G[x]) if (query(prf[y]) != x) return solve_in_subtree(y);
	return x;
}

int main() {
	int i, u, v, c = 0, Q[2];
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	if (n == 1) return cout << "0\n! 1 1\n", 0;
	for (i = 1; i < n; ++i) cin >> u >> v, G[u].EB(v), G[v].EB(u);
	fp[1] = -INF, dfs(1), dfs2(1),
	cout << *std::max_element(F + 1, F + (n + 1)) << endl;
	for (i = 2; i <= n; ++i) G[i].EB(p[i]);
	cin >> root, p[root] = 0, dfs(root, true);
	for (int z : G[root])
		if (query(prf[z]) != root)
			if (Q[c++] = z, c == 2) break;
	for (; c < 2; ++c) Q[c] = root;
	u = solve_in_subtree(Q[0]), v = solve_in_subtree(Q[1]);
	if (u > v) std::swap(u, v);
	cout << '!' << ' ' << u << ' ' << v << '\n';
	return 0;
}