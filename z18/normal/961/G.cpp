#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, mod = 1e9 + 7;
int n, k, sum, num;

int func(int x) {
	return x < mod ? x : x - mod;
}

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) c = 1ll * a * c % mod;
	}
	return c;
}

int S(int n, int m) {
	int ret = 0, cur = 1;
	for (int i = 1; i <= m; i++) {
		cur = 1ll * cur * qpow(i, mod - 2) % mod;
	}
	for (int i = 0; i <= m; i++) {
		ret = (ret + 1ll * (i & 1 ? mod - 1 : 1) * cur % mod * qpow(m - i, n)) % mod;
		cur = 1ll * cur * (m - i) % mod * qpow(i + 1, mod - 2) % mod;
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		sum = func(sum + x);
	}
	num = (S(n, k) + 1ll * S(n - 1, k) * (n - 1)) % mod;
	printf("%lld\n", 1ll * sum * num % mod);
	return 0;
}