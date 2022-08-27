#include <bits/stdc++.h>
#define N 200005

typedef long long ll;

int n;
int a[N];
ll ans;

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n * 2; ++i) scanf("%d", a + i);
	std::sort(a, a + (n * 2));
	ans = (ll)(a[n - 1] - a[0]) * (a[n * 2 - 1] - a[n]);
	for (i = 1; i < n; ++i)
		down(ans, (ll)(a[i + n - 1] - a[i]) * (a[n * 2 - 1] - a[0]));
	printf("%lld\n", ans);
	return 0;
}