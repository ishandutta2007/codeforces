#include <bits/stdc++.h>
using namespace std;

const int N = 500005, mod = 998244353;

int n, k, m, l[N], r[N], a[N], b[N], c[N], dp[N], ans = 1;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k >> m;
	for(int i = 1; i <= m; ++i) cin >> l[i] >> r[i] >> a[i];
	
	while(k--) {
		memset(b + 1, 0, sizeof(int) * n);
		memset(c + 1, 0, sizeof(int) * n);
		memset(dp + 1, 0, sizeof(int) * n);
		for(int i = 1; i <= m; ++i) {
			if(a[i] >> k & 1) ++c[l[i]], --c[r[i] + 1];
			else b[r[i]] = max(b[r[i]], l[i]);
		}
		for(int i = 1; i <= n + 1; ++i) c[i] += c[i - 1];
		for(int i = 1; i <= n; ++i) b[i] = max(b[i], b[i - 1]);
		
		dp[0] = 1;
		for(int i = 1; i <= n + 1; ++i) {
			if(!c[i]) dp[i] = (dp[i - 1] - (!b[i - 1] ? 0 : dp[b[i - 1] - 1]) + mod) % mod;
			if(i != n + 1) dp[i] = (dp[i] + dp[i - 1]) % mod;
		}
		ans = 1ll * ans * dp[n + 1] % mod;
	}
	
	cout << ans;
}