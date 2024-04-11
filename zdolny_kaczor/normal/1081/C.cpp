#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int nax = 2e3 + 44;
int fac[nax], fin[nax];
int powe(int b, int e) {
	int r = 1;
	while (e) {
		if (e & 1)
			r = r * 1ll * b % mod;
		b = b * 1ll * b % mod;
		e >>= 1;
	}
	return r;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	fac[0] = 1;
	for (int i = 1; i < nax; ++i)
		fac[i] = fac[i - 1] * 1ll * i % mod;
	fin[nax - 1] = powe(fac[nax - 1], mod - 2);
	for (int i = nax - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1ll) % mod;
	printf("%lld\n", m * 1ll * powe(m - 1, k) % mod * 1ll * fac[n - 1] % mod * fin[k] % mod * fin[n - k - 1] % mod);
}