#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
typedef long long ll;
int n, m, x;
ll a[N];

int main() {
	scanf("%d", &n), m = (n + 1) / 2;
	for(int i = 1; i <= m; ++i) scanf("%lld", &a[i]), a[i] += a[i - 1];
	scanf("%d", &x); for(int i = m + 1; i <= n; ++i) a[i] = a[i - 1] + x;
	if(x >= 0) {
		printf("%d", a[n] > 0 ? n : -1);
	} else {
		ll ans = N;
		for(int i = 1; i <= n; ++i) {
			ans = min(ans, m + (a[m] - a[i - 1] - 1) / (-x) - i + 1);
			if(i + ans - 1 >= n) printf("%lld", min(ans, 1ll * n)), exit(0);
		}
		puts("-1");
	}
	return 0;
}