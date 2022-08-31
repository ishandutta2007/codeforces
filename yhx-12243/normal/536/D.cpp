#include <bits/stdc++.h>

typedef long long ll;
const int N = 2010, M = 200010;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct edge {
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

struct node {
	int to; ll dist;
	node (int _to = 0, ll _dist = 0) : to(_to), dist(_dist) {}
	inline bool operator < (const node &B) const {return dist > B.dist;}
};

std::priority_queue <node> pq;

int V, E, Es = 0, I, s[2];
int first[N], next[M];
int w[N], used[N];
int o[2][N], c[2][N], gw[2][N][N];
ll d[2][N];
ll f[2][N][N], fy[2][N], Fy[2][N], fw[2][N][N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

inline bool cmp(const int x, const int y) {return d[I][x] < d[I][y] || (d[I][x] == d[I][y] && w[x] < w[y]);}

inline void addedge(int u, int v, int w) {
	e[++Es] = edge(u, v, w); next[Es] = first[u]; first[u] = Es;
	e[++Es] = edge(v, u, w); next[Es] = first[v]; first[v] = Es;
}

void Dijkstra(int s, ll *d) {
	int i, y; node t;
	for (i = 1; i <= V; i++) d[i] = (i == s ? 0 : INF);
	for (pq.push(node(s, 0)); !pq.empty(); ) {
		t = pq.top(); pq.pop();
		if (d[t.to] < t.dist) continue;
		for (i = first[t.to]; i; i = next[i])
			if (t.dist + e[i].w < d[y = e[i].v]) {
				d[y] = t.dist + e[i].w;
				pq.push(node(y, d[y]));
			}
	}
}

int main() {
	int i, j, u, v, w, cur; ll Cur;
	scanf("%d%d%d%d", &V, &E, s, s + 1);
	for (i = 1; i <= V; ++i) scanf("%d", ::w + i), o[0][i] = o[1][i] = i;
	for (i = 0; i < E; ++i) scanf("%d%d%d", &u, &v, &w), addedge(u, v, w);
	for (I = 0; I < 2; ++I) {
		*d[I] = -1; Dijkstra(s[I], d[I]); std::sort(o[I] + 1, o[I] + (V + 1), cmp);
		for (i = 1; i <= V; ++i) if (d[I][o[I][i]] != d[I][o[I][i + 1]]) c[I][++*c[I]] = i;
	}
	for (I = 0; I < 2; ++I) {
		memset(used, 0, sizeof used);
		for (j = 1, i = 0; i <= *c[I ^ 1]; ++i) {
			for (; i && j <= c[I ^ 1][i]; ++j) used[o[I ^ 1][j]] = 1;
			Cur = cur = 0;
			for (u = 1, v = 0; v <= *c[I]; ++v) {
				for (; v && u <= c[I][v]; ++u) if (!used[o[I][u]]) ++cur, Cur += ::w[o[I][u]];
				gw[I][i][v] = cur, fw[I][i][v] = Cur;
			}
		}
	}
	memset(fy, 192, sizeof fy);
	memset(Fy, 192, sizeof Fy);
	for (u = *c[0]; u >= 0; --u)
		for (v = *c[1]; v >= 0; --v) {
			if (gw[1][u][v + 1] > gw[1][u][v]) up(fy[1][u], Fy[1][u]);
			if (gw[0][v][u + 1] > gw[0][v][u]) up(fy[0][v], Fy[0][v]);
			f[0][u][v] = (gw[0][v][u] == gw[0][v][*c[0]] ? 0 : fy[0][v] - fw[0][v][u]);
			f[1][u][v] = (gw[1][u][v] == gw[1][u][*c[1]] ? 0 : fy[1][u] - fw[1][u][v]);
			up(Fy[0][v], -f[1][u][v] + fw[0][v][u]);
			up(Fy[1][u], -f[0][u][v] + fw[1][u][v]);
		}
	puts(f[0][0][0] ? (f[0][0][0] > 0 ? "Break a heart" : "Cry") : "Flowers");
	return 0;
}