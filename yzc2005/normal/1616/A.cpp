#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> buc(101);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++buc[abs(a[i])];
	}
	int ans = min(buc[0], 1);
	for (int i = 1; i <= 100; ++i)
		ans += min(buc[i], 2);
	cout << ans << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}