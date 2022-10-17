#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 2e5 + 5;

ll x[kMaxN];

int main() {
	int n; ll a, b, k, dt, ans = 0;
	scanf("%d%lld%lld%lld", &n, &a, &b, &k);
	//printf("%lld");
	for(int i = 1; i <= n; ++i) {
		ll h, w;
		scanf("%lld", &h);
		w = (h - 1) % (a + b) + 1;
		if(w <= a) x[i] = 0;
		else x[i] = (w - a - 1) / a + 1;
	}
	std::sort(x + 1, x + n + 1);
	ll sumk = 0;
	for(ans = 0; ans < n; ++ans) {
		if(sumk + x[ans + 1] > k) break;
		sumk += x[ans + 1];
	}
	printf("%lld", ans);
	return 0;
}