#include <bits/stdc++.h>
using namespace std;

int t, n, a;
long long s[2], mx[2], ans;

int main() {
	for(cin >> t; t; --t) {
		mx[1] = 0, mx[0] = ans = -1e18;
		s[0] = s[1] = 0;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a;
			s[i & 1] += a;
			mx[i & 1] = max(mx[i & 1], s[0] - s[1]);
			ans = max(ans, s[1] - s[0] + mx[i & 1]);
		}
		cout << ans + s[0] << endl;
	}
	return 0;
}