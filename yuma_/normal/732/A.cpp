#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
	int k, r; cin >> k >> r;
	if (k % 10 == 0)cout << 1 << endl;
	else {
		int ans = 1;
		while (1) {
			if ((k*ans) % 10 == r || (k*ans) % 10 == 0)break;
			else ans++;
		}
		cout << ans << endl;
	}
	return 0;
}