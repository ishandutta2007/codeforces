#include <bits/stdc++.h>
using namespace std;
long long query(int l, int r) {
	if (l > r) {
		return 0;
	}
	printf("? %d %d\n", l, r);
	fflush(stdout);
	long long x;
	scanf("%lld", &x);
	return x;
}
int get(long long x) {
	int l = 1, r = 1e9, ans;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (1ll * mid * (mid - 1) / 2 <= x) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
void solve() {
	int n;
	scanf("%d", &n);
	long long all = query(1, n);
	int l = 2, r = n, k = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (query(1, mid) == all) {
			k = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	int len2 = all - query(1, k - 1) + 1;
	all -= 1ll * len2 * (len2 - 1) / 2;
	int len1 = get(all);
	int j = k - len2 + 1;
	int i = j - len1;
	printf("! %d %d %d\n", i, j, k);
	fflush(stdout);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}