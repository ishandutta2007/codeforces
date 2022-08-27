#include <bits/stdc++.h>

typedef long long ll;
const int N = 10000054, mod = 1000000007;

int n, M = 0;
int a[N], pw2[N];
int pn = 0, c[N], p[666666], *end;
signed char mu[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void sieve(int n) {
	int i, j, v; mu[1] = 1;
	memset(c, -1, (n + 1) << 2);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, mu[i] = -1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, mu[v] = -mu[i];
		if (v <= n) c[v] = j;
	}
	end = p + pn;
}

void RDS(int n, int *a) {
	int *pr, i, j;
	for (pr = p; pr != end; ++pr)
		for (i = n / *pr, j = i * *pr; i; --i, j -= *pr)
			a[i] += a[j];
}

int main() {
	int i, x, ans = 0;
	scanf("%d", &n);
	for (*pw2 = i = 1; i <= n; ++i)
		scanf("%d", &x), up(M, x), ++a[x], pw2[i] = pw2[i - 1] * 2 % mod;
	sieve(M), RDS(M, a);
	for (i = 1; i <= M; ++i) if (mu[i]) ans = (ans + ((ll)pw2[ a[i] ] * (a[i] - n) + n) * mu[i]) % mod;
	printf("%d\n", ans + (ans >> 31 & mod));
	return 0;
}