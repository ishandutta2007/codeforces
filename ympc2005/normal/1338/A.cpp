#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int T, n, m;

ll a[N], b[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		
		ll val = 0;
		
		for (int i = 2; i <= n; i++) {
			b[i] = max(0ll, a[i - 1] + b[i - 1] - a[i]);
			val = max(val, b[i]);
		}
		
		int ans = 0;
		
		while (val > 0) {
			val -= 1<<ans++; 
		}
		
		printf("%d\n", ans);
	}
}