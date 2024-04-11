#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 1054;

int n;
int a[N];

void work() {
	int i;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	cout << 3 * n << '\n';
	for (i = 1; i <= n; i += 2)
		for (int j : {2, 1, 2, 2, 1, 2})
			cout << j << ' ' << i << ' ' << i + 1 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}