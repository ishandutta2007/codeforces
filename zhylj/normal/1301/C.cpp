#include <bits/stdc++.h>

typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n, n1, m, ans;
		scanf("%lld%lld", &n, &m); n1 = m; m = n - m;
		ll per_p = m / (n1 + 1), lagz = per_p + 1, lagzn = m % (n1 + 1);
		ans = n * (n + 1) / 2 - per_p * (per_p + 1) / 2 * (n1 + 1 - lagzn) - lagz * (lagz + 1) / 2 * lagzn;
		printf("%lld\n", ans);
	}
	return 0;
}