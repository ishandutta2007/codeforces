#include <bits/stdc++.h>
#define Z(r, c) ((r) - (-(((r) ^ (c)) & 1) | 1))
using std::cin;
using std::cout;

const int N = 540;

int n, t = 0, C = 0;
int que[N * N], size[N * N];
int id[N][2 * N];
bool fill[N][2 * N], origin[N][2 * N];

inline int neighbor(int r, int c) {return fill[r][c - 1] + fill[r][c + 1] + fill[Z(r, c)][c];}
inline void check(int r, int c) {if (!fill[r][c] && neighbor(r, c) > 1) que[t++] = r | c << 16;}

bool dfs(int r, int c, int lr = 0, int lc = 0) {
	int r____ = Z(r, c); ++size[ id[r][c] = C ];
	return (!fill[r][c - 1] || (id[r][c - 1] ? lr == r && c - 1 == lc : dfs(r, c - 1, r, c)))
		&& (!fill[r][c + 1] || (id[r][c + 1] ? lr == r && c + 1 == lc : dfs(r, c + 1, r, c)))
		&& (!fill[r____][c] || (id[r____][c] ? lr == r____ && c == lc : dfs(r____, c, r, c)));
}

int main() {
	int i, j, h, r, c, D = 0, E = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> c >> r, c += ++r, origin[r][c] = fill[r][c] = true;
	for (i = 0; i < 505; ++i)
		for (j = 0; j < 1005; ++j) E += fill[i][j] ^ fill[i][j + 1];
	for (i = 0; i < 505; ++i)
		for (j = !(i & 1); j < 1005; j += 2) E += fill[i][j] ^ fill[i + 1][j];
	for (i = 1; i < 505; ++i) for (j = 1; j < 1005; ++j) check(i, j);
	for (h = 0; h < t; ++h)
		r = que[h] & 65535, c = que[h] >> 16,
		fill[r][c] = true, check(r, c - 1), check(r, c + 1), check(Z(r, c), c);
	for (i = 0; i < 505; ++i)
		for (j = 0; j < 1005; ++j) if (fill[i][j] && !id[i][j])
			if (++C, !dfs(i, j)) return cout << "SICK\n", 0;
	for (i = 1; i < 505; ++i)
		for (j = 1; j < 1005; ++j)
			D += fill[i][j] && !origin[i][j] && size[ id[i][j] ] == 4 && neighbor(i, j) == 3;
	cout << "RECOVERED\n" << E - 2 * (C + D) << '\n';
	return 0;
}