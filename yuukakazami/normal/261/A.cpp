#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m;
	int q = INT_MAX;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		q = min(q, x);
	}
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	while (n - q >= 0) {
		ans += accumulate(a.begin() + n - q, a.begin() + n, 0);
		n -= q;
		n -= 2;
	}
	while (n > 0)
		ans += a[--n];
	cout << ans << endl;
	return 0;
}