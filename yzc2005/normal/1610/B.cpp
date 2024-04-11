#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	auto b = a;
	reverse(b.begin(), b.end());
	int pos = 0;
	while (pos < n && a[pos] == b[pos]) {
		++pos;
	}
	if (pos == n) {
		cout << "YES" << "\n";
		return;
	}
	bool f = false;
	auto check = [&](int x) {
		vector<int> v1, v2;
		for (int i = pos; i < n; ++i) {
			if (a[i] != x) {
				v1.emplace_back(a[i]);
			}
			if (b[i] != x) {
				v2.emplace_back(b[i]);
			}
		}
		if (v1 == v2) f = true;
	};
	check(a[pos]);
	check(b[pos]);
	cout << (f ? "YES" : "NO") << "\n";
} 
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}