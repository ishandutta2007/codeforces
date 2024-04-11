#include <bits/stdc++.h>
#define N 2555

typedef long long ll;

ll ans[N];

ll get(int n, int d) {
	ll fy = n / d;
	return (fy * (fy - 1) / 2) * d + fy;
}

int main() {
	int i, n;
	scanf("%d", &n); ans[++*ans] = 1;
	for (i = 1; i * i <= n; ++i)
		if (!(n % i)) {
			ans[++*ans] = get(n, i);
			ans[++*ans] = get(n, n/i);
		}
	std::sort(ans + 1, ans + (*ans + 1));
	n = std::unique(ans + 1, ans + (*ans + 1)) - ans - 1;
	for (i = 1; i <= n; ++i)
		printf("%lld%c", ans[i], i == n ? 10 : 32);
	return 0;
}