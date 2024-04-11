#include <bits/stdc++.h>

const int N = 20054, M = N * 2;

struct edge {
	int u, v; char w;
	edge (int u0 = 0, int v0 = 0, char w0 = 0) : u(u0), v(v0), w(w0) {}
} e[M];

int n, q, E = 0;
int first[N], next[M];
int p[N], dep[N], status[N];
int cnt = 0, o[N];
int stamp = 0, tag[N], L[N];
char s[M], pst[N];

inline int cmp(const char x, const char y) {return x < y ? -1 : x > y;}

inline void addedge(int u, int v, char w) {
	e[++E] = edge(u, v, w), next[E] = first[u], first[u] = E;
	e[++E] = edge(v, u, w), next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y; o[++cnt] = x;
	for (i = first[x]; i; i = next[i])
		if ((y = e[i].v) != p[x])
			p[y] = x, pst[y] = e[i].w,
			dep[y] = dep[x] + 1, dfs(y);
}

int genstr(int x, int y) {
	char *_beg = s, *_end = s + M;
	for (; x != y; dep[x] < dep[y] ? (*--_end = pst[y], y = p[y]) : (*_beg++ = pst[x], x = p[x]));
	return memcpy(_beg, _end, s + M - _end), M - (_end - _beg);
}

int main() {
	int i, u, v, x, l; char w[3];
	scanf("%d%d", &n, &q);
	for (i = 1; i < n; ++i) scanf("%d%d%s", &u, &v, w), addedge(u, v, *w);
	for (dfs(1); q; --q) {
		scanf("%d%d", &u, &v), l = genstr(u, v), --s[l - 1], s[l] = 127;
		status[u] = L[u] = 0, tag[u] = ++stamp;
		for (x = u; p[x]; x = p[x])
			tag[ p[x] ] = stamp, L[ p[x] ] = L[x] + 1,
			status[ p[x] ] = (status[x] ? status[x] : cmp(pst[x], s[ L[x] ]));
		for (i = 2; i <= n; ++i)
			if (tag[ x = o[i] ] != stamp)
				L[x] = L[ p[x] ] + 1,
				status[x] = (status[ p[x] ] ? status[ p[x] ] : cmp(pst[x], s[ L[p[x]] ]));
		printf("%d\n", int(n - 1 - std::count(status + 1, status + (n + 1), 1)));
	}
	return 0;
}