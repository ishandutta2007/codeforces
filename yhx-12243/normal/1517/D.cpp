#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 540;

int R, C, n;
int h[N][N], v[N][N];
int f[11][N][N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main() {
	int i, j, k;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> R >> C >> n;
	if (n & 1) {
		for (i = 1; i <= R; ++i) for (j = 1; j <= C; ++j) cout << -1 << (j == C ? '\n' : ' ');
		return 0;
	}
	n /= 2;
	for (i = 1; i <= R; ++i) for (j = 1; j < C; ++j) cin >> h[i][j];
	for (i = 1; i < R; ++i) for (j = 1; j <= C; ++j) cin >> v[i][j];
	for (k = 1; k <= n; ++k) {
		memset(f[k], 63, sizeof *f);
		for (i = 1; i <= R; ++i)
			for (j = 1; j < C; ++j)
				down(f[k][i][j], f[k - 1][i][j + 1] + h[i][j]),
				down(f[k][i][j + 1], f[k - 1][i][j] + h[i][j]);
		for (i = 1; i < R; ++i)
			for (j = 1; j <= C; ++j)
				down(f[k][i][j], f[k - 1][i + 1][j] + v[i][j]),
				down(f[k][i + 1][j], f[k - 1][i][j] + v[i][j]);
	}
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			cout << f[n][i][j] * 2 << (j == C ? '\n' : ' ');
	return 0;
}