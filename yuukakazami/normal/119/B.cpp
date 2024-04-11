#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int main() {
	int n, k, q;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> q;
	int mi = INT_MAX, mx = INT_MIN;
	int p = n / k;
	vector<bool> mark(n, false);
	for (int i = 0; i < q; ++i) {
		int s = 0;
		for (int j = 0; j < p; ++j) {
			int x;
			cin >> x;
			--x;
			s += a[x];
			mark[x] = true;
		}
		mi = min(mi, s);
		mx = max(mx, s);
	}
	vector<int> rem;
	for (int i = 0; i < n; ++i) {
		if (!mark[i])
			rem.push_back(a[i]);
	}
	if ((n - rem.size()) / p < k) {
		int s = 0;
		sort(rem.begin(), rem.end());
		mi = min(mi, accumulate(rem.begin(), rem.begin() + p, 0));
		sort(rem.rbegin(), rem.rend());
		mx = max(mx, accumulate(rem.begin(), rem.begin() + p, 0));
	}
	printf("%0.10lf %0.10lf\n", 1.0 * mi / p, 1.0 * mx / p);
	return 0;
}