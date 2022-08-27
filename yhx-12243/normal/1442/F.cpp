#include <bits/stdc++.h>
#define popc __builtin_popcount
using std::cin;
using std::cout;
using std::endl;

typedef std::pair <int, int> pr;
typedef std::tuple <char, int, int> tuple;
const int N = 1054, M = 100054, Z2 = 1050000;

struct edge {
	int u, v;
	edge (int u0 = 0, int v0 = 0) : u(u0), v(v0) {}
} e[M];

bool loop[N];
int V, E, R, O, ALL;
int to[M], first[N], next[M];
int deg[N], topo[N];
int id[N], G[20], H[N];
int used[Z2];
pr o[Z2];
tuple op[5000];

inline int min(const int x, const int y) {return x < y ? x : y;}
inline void addedge(int u, int v, int id) {e[id] = edge(u, v), next[id] = first[u], first[u] = id, ++deg[v];}

void work() {
	int i, g; static char result[30];
	cout << "? 0" << endl, cin >> result;
	for (i = 1; i < R; ++i) cout << "? 1 " << topo[i] << endl, cin >> (result + i);
	i = std::find(result, result + R, 'L') - result;
	if (i == R) {
		for (g = i = 0; i < R; ++i) g |= (result[i] == 'W') << i;
		g = used[g];
	} else g = topo[i];
	cout << "! " << g << endl,
	cin >> result, assert(*result == 'C');
}

int main() {
	int i, j, u, v, h, t = 0, T; char ch;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E >> T;
	for (i = 1; i <= E; ++i) cin >> u >> v, addedge(v, u, i);
	for (i = 1; i <= V; ++i) if (!deg[i]) topo[t++] = i;
	for (h = 0; h < t; ++h)
		for (i = first[u = topo[h]]; i; i = next[i])
			if (!--deg[v = e[i].v]) topo[t++] = v;
	assert(t == V);

	R = min(V, 20), ALL = ~(-1 << R), memset(id, -1, (V + 1) << 2);
	for (i = 0; i < R; ++i) id[topo[i]] = i;
	for (i = 1; i <= E; ++i)
		if (~id[e[i].u]) {
			if (~id[e[i].v]) G[id[e[i].v]] |= 1 << id[e[i].u];
			else H[e[i].v] |= 1 << id[e[i].u];
		} else assert(!~id[e[i].v]);

	for (i = 0; i < R; ++i)
		for (j = 0; j < i; ++j)
			if (!(G[i] >> j & 1)) op[O++] = tuple('+', topo[i], topo[j]);

	for (i = 0; i <= ALL; ++i) o[i] = pr(popc(i), i);
	std::sort(o, o + (ALL + 1));
	for (i = 1; i <= V; ++i) if (!~id[i]) {
		op[O++] = tuple('+', i, i);
		for (j = 0; j < Z2 && used[H[i] ^ o[j].second]; ++j);
		assert(j != Z2), u = o[j].second;
		for (j = 0; j < R; ++j)
			if (u >> j & 1) op[O++] = tuple(H[i] >> j & 1 ? '-' : '+', i, topo[j]);
		used[H[i] ^= u] = i;
	}

	std::sort(op, op + O), cout << O << '\n';
	for (i = 0; i < O; ++i) std::tie(ch, u, v) = op[i], cout << ch << ' ' << u << ' ' << v << '\n';

	for (cout.flush(); T; --T) work();
	return 0;
}