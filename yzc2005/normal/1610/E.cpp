#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[200005];
void solve() {
	int m, n = 0;
	cin >> m;
	int last = 0, cnt = 0;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
 		if (x != last) {
			if (last) {
				a[++n] = {last, cnt};
			}
			cnt = 0;
		}
		last = x;
		++cnt;
	}
	a[++n] = {last, cnt};
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int mn = a[i].first;
		int cur = a[i].second;
		int diff = 1;
		while (true) {
			if (diff > a[n].first) {
				break;
			}
			int pos = lower_bound(a + 1, a + n + 1, make_pair(mn + diff, 0)) - a;
			if (pos == n + 1) {
				break;
			}
			diff = (a[pos].first - mn) * 2;
			++cur;
		}
		ans = max(ans, cur);
	}
	cout << m - ans << "\n";	
} 
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}