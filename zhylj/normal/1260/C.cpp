#include <bits/stdc++.h>

typedef long long ll;

ll Gcd(ll a, ll b) { return b ? Gcd(b, a % b) : a; }

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll p1, p2, k, gd; scanf("%lld%lld%lld", &p1, &p2, &k); gd = Gcd(p1, p2);
		p1 /= gd; p2 /= gd;
		if(p2 > p1) std::swap(p1, p2);
		printf((p1 - 2) / p2 + 1 < k ? "OBEY\n" : "REBEL\n");
	}
	return 0;
}