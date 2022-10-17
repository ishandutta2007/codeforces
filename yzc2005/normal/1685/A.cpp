#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	vector<int> b;
	int i = 0, j = (n + 1) / 2;
	for (int t = 0; t < n; ++t) {
		if (t & 1) {
			b.emplace_back(a[j++]);
		} else {
			b.emplace_back(a[i++]);
		}
	}
	for (int i = 0; i < n; ++i) {
		int x = b[(i - 1 + n) % n], y = b[(i + 1) % n];
		if ((x < b[i] && y < b[i]) || (x > b[i] && y > b[i])) {
			continue;
		}
		puts("NO");
		return;
	}
	puts("YES");
	for (auto x : b) {
		printf("%d ", x);
	}
	puts("");
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}