#include <bits/stdc++.h>

const int N = 2054, mod = 1000000007;

int n, m, ans = 0;
char map[4][N], *s = map[2], *S = map[3];
int f[2][N][N]; // r, c, pos

inline int & add(int &x, const int y) {return x += y - mod, x += x >> 31 & mod;}
inline int & sub(int &x, const int y) {return x -= y, x += x >> 31 & mod;}

struct lcp_manager {
	int lcp[N][N];

	void assign(int n, char *s, int m, char *t) {
		int i, j;
		for (i = 0; i <= n; ++i) lcp[i][m] = 0;
		memset(lcp[n], 0, m << 2);
		for (i = n - 1; ~i; --i)
			for (j = m - 1; ~j; --j)
				lcp[i][j] = (s[i] == t[j] ? lcp[i + 1][j + 1] + 1 : 0);
	}
} _[4], *l = _, *L = _ + 2;

#define fy(name, cond) inline bool name(int i, int j) {int d = abs(i - j) + 1; return d * 2 <= m && (cond);}
fy(turnLD, L->lcp[j][m - d] >= d && l[1].lcp[j][d] >= d)
fy(turnLU, L[1].lcp[j][m - d] >= d && l->lcp[j][d] >= d)
fy(turnRD, l->lcp[i][m - 2 * d] >= d && L[1].lcp[i][0] >= d)
fy(turnRU, l[1].lcp[i][m - 2 * d] >= d && L->lcp[i][0] >= d)
#undef fy

void DP() {
	int i, j, D;
	for (i = 0; i <= n; ++i) memset(f[0][i], 0, (m + 1) << 2), memset(f[1][i], 0, (m + 1) << 2);
	for (i = 0; i < n; ++i) {
		f[0][i][0] = f[1][i][0] = 1;
		for (j = i - 2, D = 4; j >= 0 && D <= m; --j, D += 2)
			add(f[0][i][D], turnLU(i - 1, j)), add(f[1][i][D], turnLD(i - 1, j));
		for (j = 0; j < m; ++j) {
			if (f[0][i][j] && s[j] == map[0][i]) {
				add(f[0][i + 1][j + 1], f[0][i][j]);
				if (s[j + 1] == map[1][i]) add(f[1][i + 1][j + 2], f[0][i][j]);
			}
			if (f[1][i][j] && s[j] == map[1][i]) {
				add(f[1][i + 1][j + 1], f[1][i][j]);
				if (s[j + 1] == map[0][i]) add(f[0][i + 1][j + 2], f[1][i][j]);
			}
		}
		for (j = i + 1, D = 4; j < n && D <= m; ++j, D += 2) {
			if (turnRD(i, j)) add(ans, f[0][i][m - D]);
			if (turnRU(i, j)) add(ans, f[1][i][m - D]);
		}
	}
	for (i = 1; i <= n; ++i) add(add(ans, f[0][i][m]), f[1][i][m]);
	if (!(m & 1) && m <= 2 * n) add(add(ans, turnLD(n - 1, n - m / 2)), turnLU(n - 1, n - m / 2));
}

int main() {
	int i;
	scanf("%s%s%s", *map, map[1], s), n = strlen(*map), m = strlen(s);
	if (m == 1) ans = std::count(*map, *map + n, *s) + std::count(map[1], map[1] + n, *s);
	else if (m == 2)
		for (i = 0; i < n; ++i)
			ans += (*s == map[0][i] && s[1] == map[1][i])
				+  (*s == map[1][i] && s[1] == map[0][i])
				+  (*s == map[0][i] && s[1] == map[0][i + 1])
				+  (*s == map[1][i] && s[1] == map[1][i + 1])
				+  (*s == map[0][i + 1] && s[1] == map[0][i])
				+  (*s == map[1][i + 1] && s[1] == map[1][i]);
	else {
		std::reverse_copy(s, s + m, S);
		l->assign(n, *map, m, s), l[1].assign(n, map[1], m, s);
		L->assign(n, *map, m, S), L[1].assign(n, map[1], m, S);
		DP(), std::swap(s, S), std::swap(l, L);
		DP(), std::swap(s, S), std::swap(l, L);
		if (!(m & 1)) {
			for (i = m / 2 - 1; i < n; ++i) sub(sub(ans, turnLD(i, i - m / 2 + 1)), turnLU(i, i - m / 2 + 1));
			for (i = 0; i <= n - m / 2; ++i) sub(sub(ans, turnRD(i, i + m / 2 - 1)), turnRU(i, i + m / 2 - 1));
		}
	}
	printf("%d\n", ans);
	return 0;
}