#include <bits/stdc++.h>
#define lg2 std::__lg

typedef long long ll;
typedef unsigned long long u64;

struct layer {
	ll B, G, Bc, Gc;
	layer (ll baby = 0, ll giant = 0, ll babyCount = 0, ll giantCount = 0) : B(baby), G(giant), Bc(babyCount), Gc(giantCount) {}
} a[100];

int D;
ll n, K, BD;

// number of n-bit binaries where x < a and bitrev(x) < b
inline ll pre(int w, u64 a, u64 b) {
	assert(a <= 1ull << w && b <= 1ull << w);
	return w ? (a <= 1ull << (w - 1) ? pre(w - 1, a, (b + 1) >> 1) : ((b + 1) >> 1) + pre(w - 1, a - (1ull << (w - 1)), b >> 1)) : (a & b);
}

inline ll upper_pos(int w, ll a, ll c, ll k) {
	ll left = k * (a + 1) - pre(w, c, k), right = (k + 1) * (a + 1) - pre(w, c, k + 1);
	return (left + right) / 2;
}

ll bin1(int w, ll c, ll k) {
	ll L = 0, R = ~(-1ll << w), M;
	for (; L < R; M = (L + R + 1) / 2, M - pre(w, c, M) <= k ? L = M : R = M - 1);
	return L;
}

ll bin0(int w, ll c, ll k) {
	ll L = 0, R = ~(-1ll << w), M;
	for (; L < R; M = (L + R + 1) / 2, pre(w, c, M) <= k ? L = M : R = M - 1);
	return L;
}

int main() {
	int i, d; ll o, L, R, M, ans;
	scanf("%lld%lld", &n, &K), assert(0 < K && K <= n);
	if (K == 1) return putchar(49), putchar(10), 0;
	if (K == 2) return printf("%lld\n", n), 0;
	if (n == 3) return putchar(50), putchar(10), 0;
	if (n == 4) return putchar(K + 47), putchar(10), 0;
	K -= 2, *a = layer(n - 1, n, 1, 0);
	for (i = 0; a[i].B != 1; ++i)
		a[i + 1] = (a[i].B & 1 ? layer(a[i].B / 2, a[i].B / 2 + 1, a[i].Bc, a[i].Bc + 2 * a[i].Gc) : layer(a[i].B / 2, a[i].B / 2 + 1, 2 * a[i].Bc + a[i].Gc, a[i].Gc));
	D = i - 1, ans = 0;
	if (a[D].B == 2) {
		if (K < 1ll << D) {
			d = lg2(K), o = K & ~(-1ll << d);
			if (a[d].B & 1) o = (o < a[d].Gc ? bin1(d, a[d].Bc, o) : bin0(d, a[d].Bc, o - a[d].Gc));
			ans = upper_pos(d, a[d].B, a[d].Bc, o);
		} else {
			K -= 1ll << D;
			for (L = 0, R = ~(-1ll << D); L < R; M = (L + R + 1) / 2, 2 * M - pre(D, a[D].Bc, M) <= K ? L = M : R = M - 1);
			ans = K + L + 1;
		}
	} else if (a[D].B == 3) {
		if (K < (1ll << D) + a[D].Gc) {
			d = lg2(K), o = K & ~(-1ll << d);
			if (a[d].B & 1) o = (o < a[d].Gc ? bin1(d, a[d].Bc, o) : bin0(d, a[d].Bc, o - a[d].Gc));
			ans = upper_pos(d, a[d].B, a[d].Bc, o);
		} else
			K -= (1ll << D) + a[D].Gc, ans = 2 * K + 1 - pre(D, a[D].Bc, (K + 1) / 2);
	} else throw "gg";
	printf("%lld\n", ++ans);
	return 0;
}