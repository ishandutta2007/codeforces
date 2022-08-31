#include <bits/stdc++.h>
#define N 3100

typedef long long ll;
const ll mod = 998244353, inv2 = (mod + 1) / 2;

int n, p, q;
int P[N], fy[N], fi[N];
int con[N], E[N], C[N];

inline int & reduce(int &x) {return x += (x >> 31 & (int)mod);}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}
ll cut_sum(int a, int b) {return (ll)fy[a + b] * fi[a] % mod * fi[b] % mod;}

int main() {
	int i, j; ll c = 1, pq, pn, qn;
	scanf("%d%d%d", &n, &i, &j);
	pn = p = PowerMod(j, mod - 2, i), qn = reduce(q = 1 - p);
	if (p == q) for (i = 1; i <= n; ++i, c = c * inv2 % mod) P[i] = i * c % mod;
	else for (pq = PowerMod(p - q, mod - 2), i = 1; i <= n; ++i, pn = pn * p % mod, qn = qn * q % mod)
		reduce(P[i] = (pn - qn) * pq % mod);
	for (*fy = i = 1; i <= n; ++i) fy[i] = (ll)fy[i - 1] * P[i] % mod;
	fi[n] = PowerMod(fy[n], mod - 2);
	for (i = n; i; --i) fi[i - 1] = (ll)fi[i] * P[i] % mod;
	for (con[1] = 1, i = 3; i <= n; reduce(con[i++]))
		for (con[i] = j = 1; j < i; ++j) con[i] = (con[i] - con[j] * cut_sum(j, i - j)) % mod;
	for (E[2] = C[2] = 1, i = 3; i <= n; ++i) {
		for (c = C[i] = i * (i - 1ll) / 2 % mod, j = 1; j < i; ++j)
			c = (c + cut_sum(j, i - j) * con[j] % mod * (E[j] + E[i - j] - C[i - j])) % mod;
		reduce(E[i] = PowerMod(1 - con[i], mod - 2, c));
	}
	printf("%d\n", E[n]);
	return 0;
}