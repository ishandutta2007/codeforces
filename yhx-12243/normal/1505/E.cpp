#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 8;

int R, C;
char s[N][N];

int main() {
	int i, j, r, c, D, ni, nj, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> R >> C;
	for (i = 0; i < R; ++i) cin >> s[i];
	for (r = c = 0; r < R - 1 || c < C - 1; r = ni, c = nj) {
		ans += s[r][c] == '*',
		s[r][c] = '.', D = INT_MAX, ni = R - 1, nj = C - 1;
		for (i = r; i < R; ++i)
			for (j = c; j < C; ++j)
				if (s[i][j] == '*' && i - r + j - c < D)
					D = i - r + j - c, ni = i, nj = j;
	}
	cout << ans + (s[r][c] == '*') << '\n';
	return 0;
}