#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int l, r, p;
const int MAX_N = int(4e6) + 10, INF = ~0U >> 2;

int a[MAX_N], n;
int ps[100], nPs;

void rec(int cur, int i) {
	a[n++] = cur;
	for (; i < nPs; ++i) {
		if (1LL * cur * ps[i] > r)
			break;
		rec(cur * ps[i], i);
	}
}
int dp[MAX_N];
bool can[MAX_N];

int main() {
	for (int i = 2; i < 100; ++i) {
		bool ok = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0)
				ok = false;
		}
		if (ok)
			ps[nPs++] = i;
	}
	cin >> l >> r >> p;
	rec(1, 0);
	sort(a, a + n);
	fill(dp, dp + n, INF);
	dp[0] = 0, can[0] = true;
	for (int i = 2; i <= p; ++i) {
		int k = 0;
		for (int j = 0; j < n; ++j) {
			while (k < n && a[k] < a[j] * i)
				++k;
			if (k == n)
				break;
			if (a[k] == a[j] * i) {
				dp[k] = min(dp[k], dp[j] + 1);
				if (dp[k] + i <= p)
					can[k] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= l && can[i])
			++ans;
	}

	cout << ans << endl;
	return 0;
}