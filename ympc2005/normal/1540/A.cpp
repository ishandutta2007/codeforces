#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, d[N], T;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &d[i]);
		}

		sort(d + 1, d + n + 1);
		ll ans = d[n], sum = 0;

		for (int i = n; i; i--) {
			ans -= sum - 1ll*(n - i)*d[i];
			sum += d[i];
		}

		printf("%lld\n", ans);
	}
}