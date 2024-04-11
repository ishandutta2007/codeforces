#include <bits/stdc++.h>
#define clr(x) memset(x, 0, sizeof(mat))
#define copy(x, y) memcpy(y, x, sizeof(mat))
#define ad(x) (((x - 1) ^ 1) + 1)
#define EB emplace_back

typedef long long ll;
typedef int mat[2][2], (*pmat)[2];
typedef std::vector <int> vector;
const int N = 100054, M = N * 2, mod = 1000000007;

struct edge {
	int u, v; bool fu, fv;
	edge (int u0 = 0, int v0 = 0, bool neg_u = false, bool neg_v = false) : u(u0), v(v0), fu(neg_u), fv(neg_v) {}
} e[M];

int V, E, Es = 0;
int single[N], deg[N];
vector G[N];
bool need_clear = true;
mat f;

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

inline void addedge(int u, int v, bool fu, bool fv) {
	e[++Es] = edge(u, v, fu, fv), G[u].EB(Es);
	e[++Es] = edge(v, u, fv, fu), G[v].EB(Es);
}

#define trans(x, y, z) add(f[x][ tr[x][y] ^ z ], g[y][z])

void dfs(int x, int px, bool g0, bool g1) {
	int i = -1, y; mat tr, g;
	for (int _ : G[x]) if (e[_].v != px) {i = _; break;}
	if (~i) {
		dfs(y = e[i].v, x, g0, g1);
		tr[0][0] = tr[0][1] = tr[1][0] = tr[1][1] = 1, tr[e[i].fu][e[i].fv] = 0;
		if (~single[x]) tr[!single[x]][0] ^= 1, tr[!single[x]][1] ^= 1;
		copy(f, g), clr(f),
		trans(0, 0, 0), trans(0, 0, 1), trans(0, 1, 0), trans(0, 1, 1),
		trans(1, 0, 0), trans(1, 0, 1), trans(1, 1, 0), trans(1, 1, 1);
	} else
		clr(f), f[0][single[x] == 1] = g0, f[1][!single[x]] = g1;
	if (need_clear) G[x].clear();
}

namespace final_manager {
	int A0 = 1, A1 = 0;
	inline void push(int C0, int C1) {int t = ((ll)A0 * C0 + (ll)A1 * C1) % mod; A1 = ((ll)A0 * C1 + (ll)A1 * C0) % mod, A0 = t;}
}

int main() {
	int i, j, u, v, C0, C1; bool fu, fv;
	scanf("%d%d", &E, &V);
	memset(single, -1, sizeof single);
	for (i = 0; i < E; ++i)
		if (scanf("%d", &j), j == 1) {
			if (scanf("%d", &v), v >= 0)
				switch (single[v]) {
					case -1: single[v] = 0; break;
					case 0: single[v] = -1; break;
					case 1: single[v] = -1, final_manager::push(0, 1); break;
				}
			else
				switch (single[-v]) {
					case -1: single[-v] = 1; break;
					case 0: single[-v] = -1, final_manager::push(0, 1); break;
					case 1: single[-v] = -1; break;
				}
		} else {
			scanf("%d%d", &u, &v), (fu = u < 0) && (u = -u), (fv = v < 0) && (v = -v);
			if (u == v) single[u] = (fu == fv ? 1 : 2);
			else addedge(u, v, fu, fv);
		}
	for (v = 1; v <= V; ++v) if (G[v].empty())
		switch (single[v]) {
			case -1: final_manager::push(2, 0); break;
			case 0:
			case 1: final_manager::push(1, 1); break;
			case 2: final_manager::push(0, 2); break;
		}
	for (v = 1; v <= V; ++v) if (G[v].size() == 1)
		dfs(v, 0, 1, 1), final_manager::push(f[0][0] + f[1][0], f[0][1] + f[1][1]);
	for (v = 1; v <= V; ++v) if (G[v].size() == 2) {
		u = e[ i = G[v].back() ].v, e[ad(i)].u = e[i].v = V + 1;
		G[u].erase(std::find(G[u].begin(), G[u].end(), ad(i)));
		G[V + 1].EB(ad(i));
		need_clear = false, dfs(u, 0, 1, 0), C0 = f[0][0], C1 = f[0][1];
		need_clear = true, dfs(u, 0, 0, 1), C0 += f[1][0], C1 += f[1][1];
		final_manager::push(C0, C1);
	}
	printf("%d\n", final_manager::A1);
	return 0;
}