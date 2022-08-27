#include <bits/stdc++.h>

typedef long long ll;
const int mod = 1000000007;

struct linear {
	int k, b;
	linear (int k_ = 1, int b_ = 0) : k(k_), b(b_) {}
	inline linear operator + (const linear &B) const {return linear((k + B.k) % mod, (b + B.b) % mod);}
	inline linear operator * (const linear &B) const {return linear((ll)k * B.k % mod, ((ll)k * B.b + b) % mod);}
	inline linear operator << (const int x) const {return linear(k, (ll)b * x % mod);}
	inline int operator () (const int x) const {return ((ll)k * x + b) % mod;}
};

int n, k, p, q;
linear F;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void pow(linear a, int n, linear &c, linear &s) {
	c = linear(1, 0), s = linear(0, 0);
	if (!n) return;
	pow(a, n >> 1, c, s);
	s = s + s * c, c = c * c;
	if (n & 1) s = s + c, c = a * c;
}

void luclid(int n, int k, const linear &baby, const linear &giant, const linear &Baby, const linear &Giant, linear &ret, linear &sum) {
	if (!k) pow(baby, n, ret, sum), sum = (Baby << n) * sum;
	else if (k == n) pow(giant, n, ret, sum), sum = (Giant << n) * sum;
	else {
		int q = n / k, r = n - q * k;
		linear baby_, giant_, Baby_, Giant_;
		pow(baby, q - 1, baby_, Baby_);
		Giant_ = (Baby << q) * (Baby_ + baby_) * giant + Giant;
		Baby_ = (Baby << (q - 1)) * Baby_ * giant + Giant;
		baby_ = baby_ * giant, giant_ = baby * baby_;
		luclid(k, r, baby_, giant_, Baby_, Giant_, ret, sum);
	}
}

void work() {
	int x; linear r, s;
	scanf("%d%d", &n, &k), luclid(n, k, linear(1, 1), F, linear(), linear(), r, s);
	x = PowerMod(mod + 1 - r.k, mod - 2, r.b);
	printf("%d\n", (int)PowerMod(n, mod - 2, s(x)));
}

int main() {
//	int T; scanf("%d%d", &T, &p), F = linear(q = mod + 1 - p, 1);
	int T; scanf("%d", &T), p = q = (mod + 1) / 2, F = linear(q, 1);
	for (; T; --T) work();
	return 0;
}