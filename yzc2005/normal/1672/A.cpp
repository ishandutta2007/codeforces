#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int sum = 0;
	while (n--) {
		int x;
		cin >> x;
		sum += x - 1;
	}
	cout << ((sum & 1) ? "errorgorn" : "maomao90") << "\n";
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