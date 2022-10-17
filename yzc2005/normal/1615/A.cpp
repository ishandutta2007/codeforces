#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i], s += a[i]; 
	cout << ((s % n == 0) ? 0 : 1) << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}