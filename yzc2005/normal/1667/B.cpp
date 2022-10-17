#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, c[N], dp[N], m;
long long a[N], b[N];
int v[N];
void modify(int p, int x) {
	for (; p <= m; p += p & -p)
		v[p] = max(v[p], x);
}
inline int query(int p) {
	int res = -1e9;
	for (; p; p -= p & -p)
		res = max(res, v[p]);
	return res;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], a[i] += a[i - 1];
	m = 0;
	for (int i = 0; i <= n; ++i)
		b[++m] = a[i];
	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - b - 1;
	for (int i = 0; i <= n; ++i)
		a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
	memset(c + 1, 0xcf, m * 4);
	memset(v + 1, 0xcf, m * 4);	
	for (int i = 0; i <= n; ++i) {
		if (i) dp[i] = dp[i - 1] - 1;
		dp[i] = max(dp[i], c[a[i]]);
		dp[i] = max(dp[i], i + query(a[i] - 1));
		modify(a[i], dp[i] - i);
		c[a[i]] = max(c[a[i]], dp[i]);
	}
	cout << dp[n] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}