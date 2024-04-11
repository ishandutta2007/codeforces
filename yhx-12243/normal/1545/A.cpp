#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054;

int n;
int a[N], b[N];
int buf[2][N];

void work() {
	int i;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i], b[i] = a[i];
	std::sort(b, b + n);
	memset(buf, 0, sizeof buf);
	for (i = 0; i < n; ++i) ++buf[i & 1][a[i]], --buf[i & 1][b[i]];
	for (i = 0; i < N && !buf[0][i] && !buf[1][i]; ++i);
	cout << (i == N ? "YES\n" : "NO\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}