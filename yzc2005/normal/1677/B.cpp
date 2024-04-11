#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, sum[N], pot[N];
char s[N];
bool vis[N];
void solve() {
	cin >> n >> m >> (s + 1);
	memset(vis, false, m);
	memset(pot, 0, m * 4);
	int c = 0;
	for (int i = 1; i <= n * m; ++i) {
		if (s[i] == '1') {
			if (!vis[i % m]) {
				vis[i % m] = true;
				++c;
			}
			sum[i] = sum[i - 1] + 1;
		} else {
			sum[i] = sum[i - 1];
		}
		if (sum[i] - sum[max(0, i - m)] > 0) {
			++pot[i % m];
		}
		cout << pot[i % m] + c << " \n"[i == n * m];
	}
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