#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 27;

int R, C;
char s[N][N];

void work() {
	int i, j;
	cin >> R >> C;
	memset(s, 48, sizeof s);
	for (i = 0; i < R; ++i) s[i][C] = 0;
	for (j = 0; j < C; j += 2) s[0][j] = s[R - 1][j] = 49;
	for (i = 2; i < R - 2; i += 2) s[i][0] = s[i][C - 1] = 49;
	for (i = 0; i < R; ++i) cout << s[i] << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}