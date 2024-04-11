#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, ans;
	for(cin >> t; t; --t) {
		cin >> n;
		ans = 180 / __gcd(180, n);
		if(180 * (ans - 2) / ans < n) cout << ans * 2 << endl;
		else cout << ans << endl;
	}
}