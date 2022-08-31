#include <bits/stdc++.h>
#define EB emplace_back
#define ad(x) (((x - 1) ^ 1) + 1)

typedef std::pair <int, int> pr;
typedef std::vector <pr> vector;
const int N = 200054, M = N * 2;

int V, E, Es = 0;
int to[M], first[N], next[M];
int cnt = 0, id[N], low[N];
int top = 0, stack[N];
int bcc_cnt = 0, p[M], size[N];
vector es[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline bool bel(int x, int bcc) {return p[x] == bcc + V || p[bcc + V] == x;}

inline void addedge(int u, int v) {
	to[++Es] = v, next[Es] = first[u], first[u] = Es;
	to[++Es] = u, next[Es] = first[v], first[v] = Es;
}

void dfs(int x, int px = 0) {
	int i, y, z;
	id[x] = low[x] = ++cnt, stack[top++] = x;
	for (i = first[x]; i; i = next[i])
		if (!id[y = to[i]]) {
			dfs(y, x), down(low[x], low[y]);
			if (id[x] == low[y])
				for (p[++bcc_cnt + V] = x, size[bcc_cnt] = 1, z = 0; z != y; ++size[bcc_cnt])
					p[z = stack[--top]] = bcc_cnt + V;
			else if (id[x] < low[y])
				p[ stack[--top] ] = 0;
		} else if (y != px)
			down(low[x], id[y]);
}

bool banned[M];
int cyc[N], icyc[N];
int len = 0, ans[N];

inline void set(int id, int v) {cyc[id] = v, icyc[v] = id;}
inline void push(int x) {ans[len++] = x;}
inline void flush() {printf("%d", len); for (int i = 0; i < len; ++i) printf(" %d", ans[i]); len = 0, putchar(10);}

bool bcc_dfs(int x, int rt) {
	int i, y; stack[top++] = x;
	for (i = first[x]; i; i = next[i]) {
		if (y = to[i], !banned[i] && icyc[y] > 0 && y != rt) return stack[top++] = y, true;
		if (!icyc[y] && (icyc[y] = -1, bcc_dfs(y, rt))) return true;
	}
	return --top, false;
}

bool solve(int bcc) {
	int i, j, k, v, head, ecnt = es[bcc].size();
	if (assert(size[bcc] <= ecnt), size[bcc] == ecnt) return false;
	puts("YES");
	for (pr &e : es[bcc]) addedge(e.first, e.second);
	for (set(i = 1, p[bcc + V]); ; ) {
		if (j = first[cyc[i]], cyc[i - 1] == to[j]) j = next[j];
		assert(j), banned[j] = banned[ad(j)] = true, v = to[j];
		if (head = icyc[v]) break;
		else set(++i, v);
	}
	for (j = 0; j < head; ++j) icyc[ cyc[j] ] = 0;
	for (j = head; j <= i; ++j) if (top = 0, v = cyc[j], bcc_dfs(v, v)) break;
	k = icyc[ stack[top - 1] ];
	for (v = j; v != k; ++v > i ? v = head : 0) push(cyc[v]); push(cyc[k]), flush();
	for (v = j; v != k; --v < head ? v = i : 0) push(cyc[v]); push(cyc[k]), flush();
	for (i = 0; i < top; ++i) push(stack[i]); flush();
	return true;
}

int main() {
	int i, u, v, w;
	scanf("%d%d", &V, &E);
	for (i = 0; i < E; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
	for (i = 1; i <= Es; i += 2) {
		u = to[i + 1], v = to[i];
		if ((w = p[u] - V) > 0 && bel(u, w) && bel(v, w)) es[w].EB(u, v);
		else if ((w = p[v] - V) > 0 && bel(u, w) && bel(v, w)) es[w].EB(u, v);
	}
	Es = 0, memset(first, 0, sizeof first);
	for (i = 1; i <= bcc_cnt; ++i) if (solve(i)) return 0;
	return puts("NO"), 0;
}