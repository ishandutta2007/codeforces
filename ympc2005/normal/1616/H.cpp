#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

const int N = 2e5 + 10, mod = 998244353;

int n, x, f[N];

int solve2_(vi a, vi b, int k) {
	if (!a.size() || !b.size()) {
		return 0;
	}

	if (k == -1) {
		return 1ll*(f[a.size()] - 1)*(f[b.size()] - 1)%mod;
	}

	int res = 0;

	vi c[2], d[2];

	for (int v : a) {
		c[(v>>k)&1].push_back(v);
	}

	for (int v : b) {
		d[(v>>k)&1].push_back(v);
	}

	if (x&(1<<k)) {
		int F = solve2_(c[0], d[1], k - 1), G = solve2_(c[1], d[0], k - 1);
		res = (res + 1ll*F*G)%mod;
		res = (res + 1ll*F*(f[c[1].size()] - 1 + f[d[0].size()] - 1))%mod;
		res = (res + 1ll*G*(f[c[0].size()] - 1 + f[d[1].size()] - 1))%mod;
		res = (res + F)%mod;
		res = (res + G)%mod;
		res = (res + 1ll*(f[c[0].size()] - 1)*(f[d[0].size()] - 1))%mod;
		res = (res + 1ll*(f[c[1].size()] - 1)*(f[d[1].size()] - 1))%mod;
	} else {
		res = (solve2_(c[0], d[0], k - 1) + solve2_(c[1], d[1], k - 1))%mod;
	}

	return res;
}

int solve1_(vi p, int k) {
	if (!p.size()) {
		return 0;
	}

	if (k == -1) {
		return (f[p.size()] - 1)%mod;
	}

	vi a, b;

	for (int v : p) {
		if (v&(1<<k)) {
			b.push_back(v);
		} else {
			a.push_back(v);
		}
	}

	if (x&(1<<k)) {
		int res = (f[a.size()] - 1 + f[b.size()] - 1)%mod;
		return (res + solve2_(a, b, k - 1))%mod;
	} else {
		return (solve1_(a, k - 1) + solve1_(b, k - 1))%mod;
	}
}
 
int main() {
	scanf("%d%d", &n, &x);

	f[0] = 1;

	for (int i = 1; i <= n; i++) {
		f[i] = 2ll*f[i - 1]%mod;
	}

	vi p;

	for (int v, i = 1; i <= n; i++) {
		scanf("%d", &v);
		p.push_back(v);
	}

	printf("%d\n", (solve1_(p, 29)%mod + mod)%mod);
}