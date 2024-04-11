#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
string s;
void solve() {
	cin >> a >> b >> c >> d;
	cin >> s;
	if (count(s.begin(), s.end(), 'A') != (a + c + d)) {
		cout << "NO\n";
		return;
	}
	int n = s.length();
	int sum = 0;
	vector<int> va, vb;
	for (int i = 0, j; i < n; i = j) {
		for (j = i + 1; j < n && s[j] != s[j - 1]; ++j);
		if ((j - i) & 1) {
			int k = (j - i - 1) / 2;
			sum += k;
		} else {
			int k = (j - i) / 2;
			if (s[i] == 'A') {
				va.emplace_back(k);
				sum += k - 1;
			} else {
				vb.emplace_back(k);
				sum += k - 1;
			}
		}
	}
	if (sum >= c + d) {
		cout << "YES\n";
	} else {
		int k = c + d - sum;
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		int cnt = 0;
		for (auto x : va) {
			if (c >= x) {
				++cnt;
				c -= x;
			} else {
				break;
			}
		}
		for (auto x : vb) {
			if (d >= x) {
				++cnt;
				d -= x;
			} else {
				break;
			}
		}
		if (cnt >= k) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}