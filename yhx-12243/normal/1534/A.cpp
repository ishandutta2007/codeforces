#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 54;

int R, C;
char a[N][N], A[2];

bool set(int id, char v) {
	if (v == '.') return true;
	if (A[id] && A[id] != v) return false;
	A[id] = v;
	return true;
}

void work() {
	int i, j;
	cin >> R >> C, A[0] = A[1] = 0;
	for (i = 0; i < R; ++i) cin >> a[i];
	for (i = 0; i < R; ++i)
		for (j = 0; j < C; ++j)
			if (!set((i ^ j) & 1, a[i][j])) {
				cout << "NO\n"; return;
			}
	if (A[0] && A[1] && A[0] == A[1]) {cout << "NO\n"; return;}
	if (!(A[0] || A[1])) A[0] = 'R', A[1] = 'W';
	else if (!A[0]) A[0] = A[1] ^ 'R' ^ 'W';
	else if (!A[1]) A[1] = A[0] ^ 'R' ^ 'W';
	cout << "YES\n";
	for (i = 0; i < R; ++i) {
		for (j = 0; j < C; ++j)
			cout << A[(i ^ j) & 1];
		cout << '\n';
	}
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}