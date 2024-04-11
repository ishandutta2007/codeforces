#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int ans = n - 1;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int d = a[j] - a[i], k = j - i;
			int g = __gcd(abs(d), k);
			d /= g, k /= g;
			int res = n;
			for (int x = i, y = a[i]; x >= 0; x -= k, y -= d)
				if (a[x] == y) --res;
			for (int x = i + k, y = a[i] + d; x < n; x += k, y += d)
				if (a[x] == y) --res;
			ans = min(ans, res);
		}
	}
	cout << ans << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}