#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 1e5 + 5;

ll a[kMaxN];
ll LogCal(ll x) {
	if(x == 1) return 0;
	else return LogCal(x / 2) + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n, m, ans = 0, s = 0;
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= m; ++i) scanf("%lld", a + i), s += a[i];
		if(s < n) { printf("-1\n"); continue; }
		std::sort(a + 1, a + m + 1);
		ll cur_s = 0;
		for(int i = 1; i <= m; ++i) {
			if(!n) break;
			if(a[i] > (n & -n)) {
				ans += LogCal(a[i]) - LogCal(n & -n);
			}
			cur_s += a[i];
			while(n && cur_s >= (n & -n)) {
				cur_s -= n & -n;
				n -= n & -n;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}