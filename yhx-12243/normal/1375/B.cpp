#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 324;

int R, C;
int a[N][N], b[N][N];

void work() {
	int i, j; bool ok = true;
	cin >> R >> C;
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			cin >> a[i][j], b[i][j] = 4 - (i == 1 || i == R) - (j == 1 || j == C),
			ok &= a[i][j] <= b[i][j];
	if (!ok) {cout << "NO\n"; return;}
	cout << "YES\n";
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			cout << b[i][j] << (j == C ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}