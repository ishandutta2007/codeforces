#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int T, n, a[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		ll sum = 0;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		sort(a + 1, a + n + 1);
		
		if (sum + 1ll*(n - 2)*a[1] > 0 || sum + 1ll*(n - 2)*a[n] < 0) {
			puts("INF");
			continue;
		}
		
		ll ans = max(-1ll*a[1]*a[1]*(n - 1), -1ll*a[n]*a[n]*(n - 1));
		ll K = 1ll*(n - 2)*a[1] + sum, B = 1ll*a[1]*(sum - a[1]);
		
		for (int i = 2; i < n; i++) {
			ans = max(ans, -1ll*a[i]*K + B);
			K += a[n] - a[1];
			B += 1ll*a[i]*(a[n] - a[1]);
		}
		
		printf("%lld\n", ans);
	}
}