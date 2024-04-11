#include <bits/stdc++.h>

typedef long long ll;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ll n, g, b;
		scanf("%lld%lld%lld", &n, &g, &b);
		ll lst = (n + 1) / 2;
		ll g_ned;
		g_ned = (lst - 1) / g;
		ll ans = lst + g_ned * b;
		printf("%lld\n", std::max(n, ans));
	}
	return 0;
}