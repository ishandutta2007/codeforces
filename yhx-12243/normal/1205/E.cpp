#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054, mod = 1000000007;

int n, K;
int pn = 0, c[N], p[9600], phi[N];
int sphi[N], coef[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void sieve(int n) {
	int i, j, v; phi[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, phi[i] = i - 1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, phi[v] = phi[i] * (p[j] - 1);
		if (v <= n) c[v] = j, phi[v] = phi[i] * p[j];
	}
}

int main() {
	int i, d, ans = 0;
	scanf("%d%d", &n, &K), sieve(n);
	for (i = 1; i < n; ++i) add(sphi[i] = sphi[i - 1], phi[i + 1]);
	for (i = 1; i < n - 1; ++i) coef[i] = n - i - 1;
	for (i = 1; i < n; ++i)
		d = (n - 1) / i, coef[i] += sphi[d],
		coef[i * (d + 1) - n] -= phi[d + 1];
	for (i = n - 1; i; --i) ans = ll(ans + coef[i]) * K % mod;
	printf("%d\n", (int)PowerMod(K, mod - 1 - n, ans));
	return 0;
}