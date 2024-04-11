#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

const int N = 1054, M = N * 2;

int n, E = 0, ret;
bool banned[N];
int to[M], first[N], next[M];
int p[N], dep[N];

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

inline int LCA(int x, int y) {return cout << '?' << ' ' << x << ' ' << y << endl, cin >> x, x;}
inline int quit(int x) {return cout << '!' << ' ' << x << endl, 0; }

void __builtin_dfs(int x) {
	int i, y, deg = 0;
	if (dep[x] > dep[ret]) ret = x;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x] && !banned[y])
			p[y] = x, dep[y] = dep[x] + 1, ++deg, __builtin_dfs(y);
}

inline void dfs(int x, int parent) {dep[x] = 0, p[x] = parent, __builtin_dfs(x);}

int main() {
	int i, u, v, w;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	for (i = 0; i < n / 2; ++i) {
		for (v = 1; banned[v]; ++v);
		dfs(ret = v, 0), u = ret;
		dfs(ret = u, 0), v = ret;
		w = LCA(u, v);
		if (w == u || w == v) return quit(w);
		banned[u] = banned[v] = true;
	}
	for (i = 1; banned[i]; ++i);
	return quit(i);
}