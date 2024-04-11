#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if (n == 3) {
		if (a[2] & 1) puts("-1");
		else printf("%d\n", (a[2] + 1) / 2);
		return;
	}
	long long ans = 0;
	bool f = false;
	for (int i = 2; i < n; ++i) {
		ans += (a[i] + 1) / 2;
		f |= (a[i] > 1);
	}
	if (!f) puts("-1");
	else printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}