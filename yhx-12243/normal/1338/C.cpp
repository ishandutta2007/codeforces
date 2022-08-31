#include <bits/stdc++.h>

typedef long long ll;
const ll dak[4] = {0, 2, 3, 1};

void kth(ll k, ll &a, ll &b, ll &c) {
	if (!k--) {a = 1, b = 2, c = 3; return;}
	int w = 0; ll z = 4;
	for (; k >= z; k -= z, z <<= 2);
	for (a = z + k, b = 0; k; k >>= 2, w += 2) b |= dak[k & 3] << w;
	b += z << 1, c = a ^ b;
}

void work() {
	ll n, a[3];
	scanf("%lld", &n), kth(--n / 3, a[0], a[1], a[2]);
	printf("%lld\n", a[n % 3]);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}