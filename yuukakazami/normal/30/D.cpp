#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;
const int MAX_N = int(1e5) + 10;
double x[MAX_N];
double X, Y;
int n, k;

double dist(int i) {
	return hypot(x[i] - X, Y);
}

double solve(int l, int r) {
	if (l > r)
		return 0;
	return min(dist(l), dist(r)) + x[r] - x[l];
}

int main() {
	cin >> n >> k;
	--k;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	cin >> X >> Y;
	double ans = 1e9;
	if (k == n) {
		sort(x, x + n);
		ans = solve(0, n - 1);
	} else {
		k = x[k];
		sort(x, x + n);
		k = lower_bound(x, x + n, k) - x;
		for (int l = 0; l < n; ++l) {
			for (int r = l ? n - 1 : 0; r < n; ++r) {
				if (l <= k && k <= r) {
					int rl = l ? 0 : r + 1, rr = l ? l - 1 : n - 1;
					double a = x[k] - x[l], b = x[r] - x[k], t;
					//stop at l
					t = 2 * b + a + dist(l) + solve(rl, rr);
					ans = min(ans, t);
					//stop at r
					t = 2 * a + b + dist(r) + solve(rl, rr);
					ans = min(ans, t);
				}
			}
		}
	}
	printf("%.9f\n", ans);
	return 0;
}