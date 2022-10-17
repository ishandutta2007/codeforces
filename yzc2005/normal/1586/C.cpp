#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, q, r[N];
int main() {
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	auto check = [&](int y, int x1, int x2) {
		if (x2 < 0 || x2 >= n) return false;
		if (x1 == n - 1 && x2 == n - 1) return false;
		return s[x1][y] == 'X' && s[x2][y + 1] == 'X';
	};
	for (int j = 0; j < m; ++j) {
		r[j] = m;
		for (int i = 0; i < n; ++i) {
			if (check(j, i, i - 1)) {
				r[j] = j + 1;
				break;
			}
		}
	}
	for (int i = m - 2; i >= 0; --i)
		r[i] = min(r[i], r[i + 1]);
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		puts(::r[l] <= r ? "No" : "Yes");
	}
	return 0;
}