#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5005;

int n, a[N];

ll ans = 1e18, b[N];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; i++) {
		ll res = 0;
		b[i] = 0;

		for (int j = i - 1; j; j--) {
			b[j] = (b[j + 1] + a[j])/a[j]*a[j];
			res += b[j]/a[j];
		}

		for (int j = i + 1; j <= n; j++) {
			b[j] = (b[j - 1] + a[j])/a[j]*a[j];
			res += b[j]/a[j];
		}

		ans = min(ans, res);
	}

	printf("%lld\n", ans);
}