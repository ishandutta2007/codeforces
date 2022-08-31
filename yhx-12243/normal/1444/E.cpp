#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;
using std::endl;

typedef unsigned long long u64;
typedef unsigned __int128 u128;
typedef std::pair <u128, int> pUi;
const int N = 108, M = N * 2;
constexpr u128 one = 1;

int n, m, E = 0, C;
int to[M], first[N], next[M];
int p[N], col[N];
int cnt = 0, id[N], eid[N];
bool alive[N];
u128 f[N];
pUi b[N];
std::priority_queue <pUi> pq;

inline int lg2_128(const u128 x) {
	union a {u128 b; u64 c[2];} d;
	return d.b = x, d.c[1] ? lg2(d.c[1]) + 64 : *d.c ? lg2(*d.c) : -1;
}

inline bool in_subtree(int x, int y) {return id[y] <= id[x] && id[x] <= eid[y];}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

inline bool check(u128 w) {
	int i, j, x; u128 r;
	for (; !pq.empty(); pq.pop());
	for (i = 0; i < m; ++i) pq.emplace(b[i]);
	for (; w; ) {
		i = lg2_128(w), w ^= one << i;
		std::tie(r, x) = pq.top(), pq.pop();
		j = lg2_128(r);
		if (i < j) return false;
		else if (i == j) pq.emplace(r ^ one << j, x);
		else col[x] = i;
		if (pq.empty()) return true;
	}
	return false;
}

void dfs(int x) {
	int i, y; u128 L, R, M; id[x] = ++cnt;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) p[y] = x, dfs(y);
	for (m = 0, i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) b[m++] = pUi(f[y], y);
	if (m) {
		for (L = 0, R = ~(-one << n); L < R; ) check(M = (L + R) / 2) ? R = M : L = M + 1;
		check(f[x] = L);
	}
	eid[x] = cnt;
}

int main() {
	int i, u, v, remain;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1), memset(alive, true, n + 1), col[1] = -1;
	for (remain = n; remain > 1; ) {
		for (v = 1, i = 2; i <= n; ++i) if (alive[i] && alive[p[i]] && col[i] > col[v]) v = i;
		assert(v != 1), cout << '?' << ' ' << v << ' ' << p[v] << endl, cin >> u;
		for (remain = 0, i = 1; i <= n; ++i) remain += alive[i] = alive[i] && ((u != v) ^ in_subtree(i, v));
	}
	cout << '!' << ' ' << std::find(alive + 1, alive + (n + 1), true) - alive << endl;
	return 0;
}