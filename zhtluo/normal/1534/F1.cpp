#include <bits/stdc++.h>

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int N, M;
char map[4001000];
int deg[4001000];

template <int MAXN = 4000000, int MAXM = 4000000>
struct edge_list {
	int size, begin[MAXN], dest[MAXM], next[MAXM];
	void clear (int n) { size = 0; std::fill (begin, begin + n, -1); }
	edge_list (int n = MAXN) { clear (n); }
	void add_edge (int u, int v) { dest[size] = v; next[size] = begin[u]; begin[u] = size++; } };
template <int MAXN = 4000000, int MAXM = 4000000>
struct tarjan {
	int comp[MAXN], size;
	int dfn[MAXN], ind, low[MAXN], ins[MAXN], stk[MAXN], stks;
	void dfs (const edge_list <MAXN, MAXM> &e, int i) {
		dfn[i] = low[i] = ind++;
		ins[i] = 1; stk[stks++] = i;
		for (int x = e.begin[i]; ~x; x = e.next[x]) {
			int j = e.dest[x]; if (!~dfn[j]) {
				dfs (e, j);
				if (low[i] > low[j]) low[i] = low[j];
			} else if (ins[j] && low[i] > dfn[j])
				low[i] = dfn[j]; }
		if (dfn[i] == low[i]) {
			for (int j = -1; j != i; j = stk[--stks], ins[j] = 0, comp[j] = size);
			++size; } }
	void solve (const edge_list <MAXN, MAXM> &e, int n) {
		size = ind = stks = 0;
		std::fill (dfn, dfn + n, -1);
		for (int i = 0; i < n; ++i) if (!~dfn[i])
			dfs (e, i); } };

edge_list <> edge;
tarjan <> _tarjan;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf(" %c", &map[i * M + j]);
    edge.clear(N * M);
    for (int j = 0; j < M; ++j) {
        int lst = -1;
        for (int i = 0; i < N; ++i) {
            if (map[i * M + j] == '#') {
                if (lst >= 0) {
                    edge.add_edge(lst * M + j, i * M + j);
                }
                lst = i;
            }
            if (j - 1 >= 0 && map[i * M + (j - 1)] == '#' && lst >= 0) {
                    edge.add_edge(lst * M + j, i * M + (j - 1));
            }
            if (j + 1 < M && map[i * M + (j + 1)] == '#' && lst >= 0) {
                    edge.add_edge(lst * M + j, i * M + (j + 1));
            }
        }
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (map[i * M + j] == '#') {
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && nj >= 0 && ni < N && nj < M && map[ni * M + nj] == '#') {
                edge.add_edge(i * M + j, ni * M + j);
            }
        }
    }
    _tarjan.solve(edge, N * M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (map[i * M + j] == '#') {
        for (int x = edge.begin[i * M + j]; ~x; x = edge.next[x]) {
            if (_tarjan.comp[i * M + j] != _tarjan.comp[edge.dest[x]])
                ++deg[_tarjan.comp[edge.dest[x]]];
        }
    }
    // for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) printf("%d%c", _tarjan.comp[i * M + j], " \n"[j + 1 == M]);
    int ans = 0;
    for (int i = 0; i < _tarjan.size; ++i) if (deg[i] == 0) ++ans;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) if (map[i * M + j] == '.') --ans;
    printf("%d\n", ans);
}