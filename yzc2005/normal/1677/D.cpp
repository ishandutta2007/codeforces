#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int N = 1e6 + 5;
int n, k, v[N];
bool vis[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(vis, false, n + 1);
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (v[i] == 0) {
				if (i + k <= n) {
					vis[i + k] = true;
					ans = 1ll * ans * (k + 1) % P;		
				}
			} else if (v[i] > 0) {
				if (i + k > n) {
					ans = 0;
				}
				vis[i + k] = true;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				ans = 1ll * ans * i % P;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}