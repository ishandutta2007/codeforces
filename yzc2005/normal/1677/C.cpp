#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, p[N], q[N], pos[N];
bool vis[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
		q[i] = pos[q[i]];
	}
	memset(vis + 1, false, sizeof vis);
	int c0 = 0, c1 = 0, c2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) {
			continue;
		}
		int j = i, len = 0;
		do {
			vis[j] = true;
			j = q[j];
			++len;
		} while (j != i);
		c0 += len / 2;
		c2 += len / 2;
		if (len & 1) {
			++c1;
		}
	}
	long long ans = 0;
	int cur = 0;
	while (c0--) {
		cur += 2;
		ans += cur;
	}
	while (c1--) {
		ans += cur;
	}
	while (c2--) {
		cur -= 2;
		ans += cur;
	}
	cout << ans << "\n";
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