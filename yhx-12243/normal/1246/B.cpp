#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;

int n, K, B;
int a[N];
int pn = 0, c[N], p[78540];
ll ans = 0;

void sieve(int n) {
	int i, j, v;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++;
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
	}
}

int factor(int n) {
	int i, j, r = 1;
	for (; n > 1; ) {
		for (i = c[n], j = 0; !(n % p[i]); n /= p[i], ++j);
		for (j %= K; j; --j) r *= p[i];
	}
	return r;
}

int complement(int n) {
	int i, j; ll r = 1;
	for (; n > 1 && r <= 100000; ) {
		for (i = c[n], j = 0; !(n % p[i]); n /= p[i], ++j);
		j %= K, j = (!j - 1) & (K - j);
		for (; j && r <= 100000; --j) r *= p[i];
	}
	return std::min(r, 100001ll);
}

int main() {
	int i, j, x; sieve(N - 1);
	scanf("%d%d", &n, &K);
	for (i = 0; i < n; ++i) scanf("%d", &x), ++a[ factor(x) ];
	ans = a[1] * (a[1] - 1ll) / 2;
	for (i = 2; i <= 100000; ++i) {
		j = complement(i);
		if (i == j)
			ans += a[i] * (a[i] - 1ll) / 2;
		else if (i > j)
			ans += (ll)a[i] * a[j];
	}
	printf("%lld\n", ans);
	return 0;
}