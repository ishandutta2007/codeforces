#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef unsigned int u32;
typedef std::pair <int, int> pr;
typedef std::vector <int> vector;
const int N = 400054, INF = 0x3f3f3f3f,
		  dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};

int R, C, V;
int a[N], _[2 * N], *s[N], *S[N];
int col_min[N], tag[N];
bool ok[N];
vector G[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

void bfs(int si, int sj) {
	int h, t = 1, i, j, d, ni, nj;
	static int que[N];
	*que = si * C + sj, s[si][sj] = ++V;
	for (h = 0; h < t; ++h) {
		i = que[h] / C, j = que[h] % C;
		for (d = 0; d < 4; ++d) {
			ni = i + dr[d], nj = j + dc[d];
			if ((u32)ni < (u32)R && (u32)nj < (u32)C && !~s[ni][nj])
				que[t++] = ni * C + nj, s[ni][nj] = V;
		}
	}
}

namespace dak {
	int n;
	int rightmost[N];

	inline void init(int n_) {n = n_, memset(rightmost, -1, sizeof rightmost);}

	inline void insert(int l, int r) {up(rightmost[l], r);}

	int solve() {
		int i, last = -1, max = 0, ret = 0;
		for (i = 0; i < n; ++i) {
			up(max, rightmost[i]);
			if (i > last) last = max, ++ret;
		}
		return ret;
	}
}

namespace graph {
	vector Gs[N];
	int cnt = 0, id[N], low[N];
	int stc = 0, sta[N];
	int n_scc = 0, scc[N], bel[N];
	bool instack[N];

	int ee[N], vs[N], L[N], R[N];
	bool end[N];

	void dfs(int x) {
		int y;
		id[x] = low[x] = ++cnt, instack[x] = true, sta[stc++] = x;
		for (int y : G[x])
			if (!id[y])
				dfs(y), down(low[x], low[y]);
			else if (instack[y])
				down(low[x], id[y]);
		if (id[x] == low[x])
			for (y = 0, scc[++n_scc] = x; y != x; )
				y = sta[--stc], instack[y] = false, bel[y] = n_scc;
	}

	// Why the sand which touches ground need to disturb ???
	void main() {
		int i, u, m = 0;
		for (i = 1; i <= V; ++i) if (!id[i]) dfs(i);
		for (i = 1; i <= V; ++i) for (int j : G[i]) if (bel[i] != bel[j]) Gs[bel[i]].EB(bel[j]);

		for (i = 0; i < C; ++i) u = bel[col_min[i]], end[u] = true, ee[u] = i;
		for (i = n_scc; i; --i) if (end[i]) for (int j : Gs[i]) end[j] = true, ee[j] = -1;

		for (i = 1; i <= n_scc; ++i) if (end[i] && ~ee[i]) vs[m++] = i; 
		std::sort(vs, vs + m, [] (const int x, const int y) {return ee[x] < ee[y];}),
		m = std::unique(vs, vs + m) - vs;

		memset(L, 63, sizeof L), memset(R, 192, sizeof R);
		for (i = 0; i < m; ++i) L[ vs[i] ] = R[ vs[i] ] = i;

		for (i = 1; i <= n_scc; ++i) if (!end[i]) {
			for (int j : Gs[i]) down(L[i], L[j]), up(R[i], R[j]);
		}

		dak::init(m);
		for (i = 1; i <= n_scc; ++i) if (L[i] <= R[i]) dak::insert(L[i], R[i]);
	}
}

int main() {
	int i, j, u, la, fst, cc; static char row[N];
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> R >> C;
	for (i = 0; i < R; ++i) {
		cin >> row, s[i] = _ + i * C, S[i] = s[i] + N;
		for (j = 0; j < C; ++j)
			s[i][j] = -(row[j] & 1);
	}
	for (i = 0; i < C; ++i) cin >> a[i];
	for (i = 0; i < R; ++i)
		for (j = 0; j < C; ++j) if (!~s[i][j]) bfs(i, j);
#ifdef F
	for (i = 0; i < R; ++i) {
		for (j = 0; j < C; ++j)
			fprintf(stderr, "%d ", s[i][j]);
		fputc(10, stderr);
	}
#endif
	for (j = 0; j < C; ++j) {
		la = cc = 0, fst = -1;
		for (i = R - 1; i >= 0; --i)
			if ((u = s[i][j])) {
				if (++cc >= a[j] && !col_min[j]) col_min[j] = u;
				if (la && la != u) G[u].EB(la);
				S[i][j] = la = u;
			} else up(fst, i), S[i][j] = (i == R - 1 ? 0 : S[i + 1][j]); 
		if (!a[j]) col_min[j] = 0;
	}
	for (j = 0; j < C; ++j)
		for (i = 0; i < R; ++i)
			if (s[i][j] && tag[ u = s[i][j] ] != j + 1) {
				tag[u] = j + 1;
				if (j && S[i][j - 1] && S[i][j - 1] != u) G[u].EB(S[i][j - 1]);
				if (j + 1 < C && S[i][j + 1] && S[i][j + 1] != u) G[u].EB(S[i][j + 1]);
			}
#ifdef F
	for (i = 0; i < C; ++i) fprintf(stderr, "col[%d] = {ok : %d, least : %d}\n", i, ok[i], col_min[i]);
#endif
	graph::main();
	cout << dak::solve() << '\n';
	return 0;
}