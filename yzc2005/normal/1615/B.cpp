#include <bits/stdc++.h>
using namespace std;
int sum[20][200005];
void init(int n) {
	for (int k = 0; k < 20; ++k)
		for (int i = 1; i <= n; ++i)
			sum[k][i] = sum[k][i - 1] + (i >> k & 1);
}
void solve() {
	int l, r;
	cin >> l >> r;
	int mx = 0;
	for (int k = 0; k < 20; ++k)
		mx = max(mx, sum[k][r] - sum[k][l - 1]);
	cout << r - l + 1 - mx << "\n";
}
int main() {
	init(200000);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}