#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	long long int ans = 0;
	for (int i = 0; i < 1e7; ++i) {
		if (b < i || a < i)break;
		else {
			long long int nans = 32 * i;
			int nb = b - i;
			int na = a - i;
			int j = min(min(na, c), d);
			nans += 256 * j;
			ans = max(ans, nans);
		}
	}
	cout << ans << endl;
	return 0;
}