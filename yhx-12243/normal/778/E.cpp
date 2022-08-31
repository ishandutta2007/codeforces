#include <bits/stdc++.h>

const int N = 1054;

int n, sL, L, w[10];
char s[N], dig[N][N];
int f[N][N], len[N], o[N];
int next[N], nocarry[N], carry[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, k, nk, d, l, r, W; char *p;
	for (scanf("%s%d", p = s, &n); *p; ++p) *p &= 15;
	std::reverse(s, p), L = sL = p - s;
	for (i = 0; i < n; ++i) {
		for (scanf("%s", p = dig[i]); *p; ++p) *p &= 15;
		std::reverse(dig[i], p), up(L, len[i] = p - dig[i]);
	}
	for (i = 0; i < 10; ++i) scanf("%d", w + i);
	std::iota(o, o + n, 0), ++L,
	memset(f, -1, sizeof f), **f = 0;
	for (i = 0; i < L; ++i) {
		s[i] == 15 ? (l = i == sL - 1, r = 9) : (l = r = s[i]);
		for (d = l; d <= r; ++d) {
			for (W = nk = j = 0; j < n; ++j) {
				next[j] = dig[j][i] + d,
				carry[j] = w[(next[j] + 1) % 10],
				nocarry[j] = w[next[j] % 10];
				if (!next[j] && i >= sL && i >= len[j]) nocarry[j] = 0;
				W += nocarry[j], nk += next[j] > 9;
			}
			for (k = 0; k <= n; ++k) {
				if (j = o[k], ~f[i][k]) up(f[i + 1][nk], f[i][k] + W);
				W += carry[j] - nocarry[j], nk += next[j] == 9;
			}
		}
		std::stable_sort(o, o + n, [i] (const int x, const int y) {return dig[x][i] > dig[y][i];});
	}
	printf("%d\n", f[L][0]);
	return 0;
}