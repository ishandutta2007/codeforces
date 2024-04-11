#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 50054, K = 5;

int n;
int r[N][K];

inline bool better(int x, int y) {
	int i, s = 0;
	for (i = 0; i < 5; ++i) s += r[x][i] < r[y][i];
	return s > 2;
}

void work() {
	int i, j, w = 0;
	cin >> n;
	for (i = 0; i < n; ++i)
		for (j = 0; j < 5; ++j) cin >> r[i][j];
	for (i = 1; i < n; ++i) if (better(i, w)) w = i;
	for (i = 0; i < n; ++i) if (i != w && !better(w, i)) {cout << -1 << '\n'; return;}
	cout << w + 1 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}