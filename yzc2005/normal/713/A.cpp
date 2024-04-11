#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
void add(long long x, int v) {
	string s;
	while (x) {
		s = char(48 + (x & 1)) + s;
		x /= 10;
	}
	while (s.length() < 20)
		s = '0' + s;
	cnt[s] += v;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		char c;
		cin >> c;
		if (c == '+') {
			long long x;
			cin >> x;
			add(x, 1);
		} else if (c == '-') {
			long long x;
			cin >> x;
			add(x, -1);
		} else {
			string s;
			cin >> s;
			int ans = 0;
			while (s.length() < 20)
				s = '0' + s;
			cout << cnt[s] << "\n";
		}
	}
	return 0;
}