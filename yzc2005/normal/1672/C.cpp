#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int x = -1, y = -1;
	for (int i = 1; i < n; ++i)
		if (a[i] == a[i + 1]) y = i;
	for (int i = n - 1; i; --i)
		if (a[i] == a[i + 1]) x = i;
	if (x == y) {
		cout << "0\n";
	} else {
		cout << max(1, y - x - 1) << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solve();	
	return 0;
}