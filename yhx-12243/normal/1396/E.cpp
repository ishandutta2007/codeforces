#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
typedef std::pair <int, int> pr;
typedef std::tuple <int, int, int> tup;
const int N = 100054, M = N * 2;

int n, E = 0;
int to[M], first[N], next[M];
int p[N], size[N], w[N];
bool used[N];
ll W, min, max, adj;
vector<int> buc[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dfs(y), size[x] += size[y],
			min += size[y] & 1, max += w[y] = std::min(size[y], n - size[y]);
}

namespace construction {
	vector<int> send[N];
	vector<pr> ans;
	pr c[N];
	tup r[M * 2];

	int match(int n, pr *c, tup *ret) {
		int i, j, s = 0, ss = 0, L = 0, u;
		std::sort(c, c + n);
		for (i = 0; i < n; ++i) s += c[i].first;
		assert(c[n - 1].first * 2 <= s + 1 && (s & 1));
		ret[L++] = tup(0, c[n - 1].second, 1), --s;
		if (!--c[n - 1].first) --n;
		std::sort(c, c + n);
		if (!n) return L;
		for (i = 0; i < n; ++i)
			if ((ss += c[i].first) >= s / 2) {
				u = s / 2 - (ss - c[i].first);
				std::copy_backward(c + i, c + n, c + (n + 1));
				c[i].first = u, c[i + 1].first -= u;
				break;
			}
		assert(i != n);
		for (j = i + 1, i = 0; s > 0; ) {
			for (; !c[i].first; ++i);
			for (; !c[j].first; ++j);
			u = std::min(c[i].first, c[j].first);
			c[i].first -= u, c[j].first -= u, s -= 2 * u;
			ret[L++] = tup(c[i].second, c[j].second, u);
		}
		return L;
	}

	inline void join(vector<int> &A, vector<int> &B) {
		if (A.size() < B.size()) std::swap(A, B);
		A.insert(A.end(), B.begin(), B.end());
	}

	void dfs(int x) {
		int i, j, y, d = 0, len, u, v, wi;
		for (i = first[x]; i; i = next[i])
			if (p[y = to[i]] == x) dfs(y);
		for (i = first[x]; i; i = next[i])
			if (p[y = to[i]] == x) c[d++] = pr(w[y], y);
		if (x != 1) c[d++] = pr(w[x], p[x]);
		len = match(d, c, r);
//		fprintf(stderr, "match at %d:\n", x);
		for (i = 0; i < len; ++i) {
			std::tie(u, v, wi) = r[i];
//			fprintf(stderr, "(%d, %d), %d\n", u, v, wi);
			if (!u) {
				assert(wi == 1);
				if (v != p[x])
					ans.EB(send[v].back(), x), send[v].pop_back();
				else
					send[x].EB(x);
			} else {
				if (u != p[x] && v != p[x])  {
					for (j = 0; j < wi; ++j)
						ans.EB(send[u].back(), send[v].back()),
						send[u].pop_back(), send[v].pop_back();
				}
			}
		}
		for (i = 0; i < len; ++i) {
			std::tie(u, v, wi) = r[i];
			if (u) {
				if (u != p[x] && v != p[x]) continue;
				if (u == p[x]) std::swap(u, v);
//				fprintf(stderr, "u = %d, v = %d, wi = %d\n", u, v, wi);
				assert(u != p[x] && v == p[x] && (int)send[u].size() == wi);
				join(send[x], send[u]);
			}
		}
/*		fprintf(stderr, "send[%d] =", x);
		for (int a : send[x])
			fprintf(stderr, " %d", a);
		fputc(10, stderr);*/
		assert((int)send[x].size() == w[x]);
	}

	int main() {
		dfs(1);
		return 0;
	}
}

int main() {
	int i, j, u, v; ll S = 0, s[2] = {0};
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> W, assert(!(n & 1));
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1);
	if (W < min || max < W || ((min ^ W) & 1)) return cout << "NO\n", 0;
	for (i = 2; i <= n; ++i) buc[ w[i] ].EB(i);
	adj = (max - W) / 2;
	for (i = n / 2; i; --i) {
		s[i & 1] += (int)buc[i].size();
		S += s[i & 1];
		if (S >= adj) {
			u = adj - (S - s[i & 1]);
			for (j = n / 2; j > i; --j)
				for (int x : buc[j]) w[x] = (i ^ j) & 1 ? i - 1 : i;
			for (j = i; u > 0; j += 2)
				for (int x : buc[j])
					if (w[x] = i - 2, --u <= 0) break;
			break;
		}
	}
	assert(i);
	assert(std::accumulate(w + 2, w + (n + 1), 0ll) == W);
//	for (i = 2; i <= n; ++i) fprintf(stderr, "%d => %d\n", i, w[i]);
	construction::main();
	cout << "YES\n";
	for (const pr &e : construction::ans) cout << e.first << ' ' << e.second << '\n';
	return 0;
}