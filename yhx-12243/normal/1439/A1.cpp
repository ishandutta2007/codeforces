#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 108;

int R, C, ans;
char s[N][N];
char op[N * N][54];

inline void Do(int r1, int c1, int r2, int c2, int r3, int c3) {
	sprintf(op[ans++], "%d %d %d %d %d %d\n", r1, c1, r2, c2, r3, c3);
	s[r1][c1] ^= 1, s[r2][c2] ^= 1, s[r3][c3] ^= 1;
}

void work() {
	int i, j;
	cin >> R >> C, ans = 0;
	for (i = 1; i <= R; ++i) cin >> s[i] + 1;
	for (i = 2; i < R; ++i) {
		for (j = 1; j < C; ++j)
			if (s[i - 1][j] & 1) Do(i - 1, j, i, j, i, j + 1);
		if (s[i - 1][C] & 1) Do(i - 1, C, i, C - 1, i, C);
	}
	for (j = 2; j <= C; ++j)
		switch ((s[R - 1][j - 1] & 1) | (s[R][j - 1] & 1) << 1) {
			case 0: break;
			case 1: Do(R - 1, j - 1, R - 1, j, R, j); break;
			case 2: Do(R - 1, j, R, j - 1, R, j); break;
			case 3: Do(R - 1, j - 1, R, j - 1, R, j); break;
		}
	switch ((s[R - 1][C] & 1) | (s[R][C] & 1) << 1) {
		case 0: break;
		case 1:
			Do(R - 1, C - 1, R - 1, C, R, C - 1);
			Do(R - 1, C - 1, R - 1, C, R, C);
			Do(R - 1, C, R, C - 1, R, C); break;
		case 2:
			Do(R - 1, C - 1, R, C - 1, R, C);
			Do(R - 1, C - 1, R - 1, C, R, C);
			Do(R - 1, C, R, C - 1, R, C); break;
		case 3:
			Do(R - 1, C - 1, R - 1, C, R, C - 1);
			Do(R - 1, C - 1, R, C - 1, R, C); break;
	}
	assert(ans <= R * C);
	cout << ans << '\n';
	for (i = 0; i < ans; ++i) cout << op[i];
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}