#include <bits/stdc++.h>
using std::cin;
using std::cout;

int main() {
	int i, n, r; long long q, s = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> q, s += q - i;
	q = s / n, r = s % n;
	for (i = 0; i < n; ++i) cout << q + i + (i < r) << (i == n - 1 ? '\n' : ' ');
	return 0;
}