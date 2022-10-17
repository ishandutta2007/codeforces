#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int j = 0; j < n; ++j) {
		auto b = a;
		for (int i = 0; i < n; ++i) {
			if (i == j) {
				continue;
			}
			while (b[i] % 2 == 0) {
				b[i] /= 2;
				b[j] *= 2;
			}
		}
		ans = max(ans, accumulate(b.begin(), b.end(), 0ll));
	}
	cout << ans << "\n";
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}