#include <bits/stdc++.h>

typedef long long ll;

const ll kMod = 1e9 + 7;
const int kN = 1e5 + 5;
const int kL = 2e3 + 5;

int ap[kN], cnt; ll f[kL][kL], fac[kN];
std::map<int, int> idx;

bool IsLucky(int x) {
	while(x) {
		if(x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

ll QPow(ll a, ll b) {
	a %= kMod;
	ll ans = 1, bas = a;
	while(b) {
		if(b & 1) ans = ans * bas % kMod;
		bas = bas * bas % kMod;
		b >>= 1;
	}
	return ans;
}
ll C(int n, int m) {
	if(m > n) return 0;
	return fac[n] * QPow(fac[m] * fac[n - m], kMod - 2) % kMod;
}

int main() {
	int n, k, rn; scanf("%d%d", &n, &k); rn = n;
	fac[0] = 1;
	for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % kMod;
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		if(IsLucky(x)) {
			if(idx.count(x)) ++ap[idx[x]];
			else idx[x] = ++cnt, ap[cnt] = 1;
			--rn;
		}
	}
	f[0][0] = 1;
	for(int i = 1; i <= cnt; ++i) {
		f[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			f[i][j] = (f[i - 1][j] + ap[i] * f[i - 1][j - 1]) % kMod;
		}
	}
	ll ans = 0;
	for(int i = 0; i <= std::min(cnt, k); ++i) {
		ans = (ans + f[cnt][i] * C(rn, k - i)) % kMod;
	}
	printf("%lld", ans);
	return 0;
}