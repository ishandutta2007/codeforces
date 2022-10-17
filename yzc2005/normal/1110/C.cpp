#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll q, n, m;
	for(cin >> q; q; --q) {
		cin >> n;
		for(m = 1; m < n; (m <<= 1) |= 1);
		if(m != n) {
			cout << m << endl;
		} else {
			ll ans = 1;
			for(ll i = 3; i * i <= n; ++i) 
				if(n % i == 0) {
					ans = n / i;
					break;
				}
			cout << ans << endl;
		}
	} 
}