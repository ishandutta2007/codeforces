#include <bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') {
			++a;
		} else {
			++b;
		}
		if (a < b) {
			cout << "NO\n";
			return;
		}
	}
	cout << ((s[0] == 'A' && s[n - 1] == 'B') ? "YES\n" : "NO\n");
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