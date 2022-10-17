#include <bits/stdc++.h>
using namespace std;
int n, a[50005], x, dp[50005];
int mx[200005];
void modify(int p, int l, int r, int pos, int val) {
	mx[p] = max(mx[p], val);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (mid >= pos) modify(p << 1, l, mid, pos, val);
	else modify(p << 1 | 1, mid + 1, r, pos, val);
}
int query(int p, int l, int r, int ll, int rr) {
	if (l >= ll && r <= rr) return mx[p];
	int mid = (l + r) >> 1, res = -1e9;
	if (mid >= ll) res = max(res, query(p << 1, l, mid, ll, rr));
	if (mid < rr) res = max(res, query(p << 1 | 1, mid + 1, r, ll, rr));
	return res;
}
void solve() {
	memset(mx, 0xcf, sizeof mx);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> x;
	int lp = 1, ans = 0, prv = 0;
	modify(1, 0, n, 0, 0);
	for (int i = 1; i <= n; ++i) {
		a[i] -= x;
		int pre = max(lp - 1, 0);
		if (i > 1 && a[i] + a[i - 1] < 0) lp = i;
		else if (i > 2 && a[i] + a[i - 1] + a[i - 2] < 0) lp = i - 1;
		while (pre < lp - 1) 
			prv = max(prv, dp[pre++]);
		dp[i] = prv + i - lp + 1;
		dp[i] = max(dp[i], query(1, 0, n, lp - 1, i - 1) + i - 1);
		modify(1, 0, n, i, dp[i] - i);
		ans = max(ans, dp[i]); 
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