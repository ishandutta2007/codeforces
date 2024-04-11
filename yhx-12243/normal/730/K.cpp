#include <bits/stdc++.h>
#define ad(x) ((((x) - 1) ^ 1) + 1)
#define EB emplace_back

enum direction {U, D, undefined};
typedef std::pair <int, direction> pid;
typedef std::pair <int, int> pii;
typedef std::vector <pii> vector;
const int N = 400054, M = 2000054;

int V, E, Es, si, ti;
int to[M], first[N], next[M];
int p[N], pe[N], dep[N];
direction dir[M];
pid que[M];
vector backwards[N];

inline direction operator - (const direction &x) {return x == U ? D : U;} 

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es;
	to[++Es] = u, next[Es] = first[v], first[v] = Es;
}

int __cs[N];
void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if (!~p[y = to[i]])
			__cs[x] = y, p[y] = x, dep[y] = dep[x] + 1, pe[y] = i, dfs(y);
		else if (y != p[x] && dep[y] < dep[x])
			backwards[ __cs[y] ].EB(x, i);
}

void work() {
	int i, u, v, h, t = 1; direction du;
	scanf("%d%d%d%d", &V, &E, &si, &ti), Es = 0;
	memset(first, 0, (V + 1) << 2);
	memset(p, -1, (V + 1) << 2);
	for (i = 1; i <= V; ++i) backwards[i].clear();
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	p[si] = pe[si] = dep[si] = 0, dfs(si);
	dfs(si);
	for (i = 1; i <= Es; ++i) dir[i] = undefined;
	*que = pid(ti, D);
	for (h = 0; h < t; ++h) {
		std::tie(u, du) = que[h];
		for (; u != si && dir[ pe[u] ] == undefined; u = p[u]) {
			dir[ad(pe[u])] = dir[ pe[u] ] = du;
			for (const pii &e : backwards[u])
				std::tie(v, i) = e, dir[ad(i)] = dir[i] = du, que[t++] = pid(v, -du);
		}
	}
	if (std::count(dir + 1, dir + (Es + 1), undefined)) puts("No");
	else for (puts("Yes"), i = 1; i <= Es; i += 2)
		u = to[i + 1], v = to[i], ((dir[i] == D) ^ (dep[u] < dep[v])) && (std::swap(u, v), 0),
		printf("%d %d\n", u, v); 
}

int main(){
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}