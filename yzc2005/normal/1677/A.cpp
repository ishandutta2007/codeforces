#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N], pre[N][N], suf[N][N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		memcpy(pre[i], pre[i - 1], sizeof pre[i]);
		for (int j = a[i]; j <= n; ++j) {
			++pre[i][j];
		}
	}
	memset(suf[n + 1], 0, sizeof suf[n + 1]);
	for (int i = n; i; --i) {
		memcpy(suf[i], suf[i + 1], sizeof suf[i]);
		for (int j = a[i]; j <= n; ++j) {
			++suf[i][j];
		}
	}
	long long ans = 0;
	for (int b = 1; b <= n; ++b) {
		for (int c = b + 1; c <= n; ++c) {
			ans += pre[b - 1][a[c] - 1] * suf[c + 1][a[b] - 1];
		}
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