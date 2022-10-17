#include <bits/stdc++.h>
using namespace std;
int n, a[200005], b[200005];
bool check(int mid) {
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < cur) {
			continue;
		}
		if (cur + 1 + b[i] >= mid) {
			++cur;
		}
	}
	return cur >= mid;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i] >> a[i];
	}
	int l = 0, r = n, ans;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
} 
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}