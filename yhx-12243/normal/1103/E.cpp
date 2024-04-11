#include <bits/stdc++.h>
#define templated template <typename T>
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 100000;
const u64 iv3125 = 0x14e8fb00bcbe61dull, mask = 0x3ffffffffffffffull;

templated T Power(T a, int n, T c = 1) {for (; n; n >>= 1, a *= a) if (n & 1) c *= a; return c;}

// Cyclotomic Field of size 10
struct CF {
	u64 a0, a1, a2, a3;
	CF (u64 a0_ = 0, u64 a1_ = 0, u64 a2_ = 0, u64 a3_ = 0) : a0(a0_), a1(a1_), a2(a2_), a3(a3_) {}
	inline CF operator + (const CF &B) const {return CF(a0 + B.a0, a1 + B.a1, a2 + B.a2, a3 + B.a3);}
	inline CF operator - (const CF &B) const {return CF(a0 - B.a0, a1 - B.a1, a2 - B.a2, a3 - B.a3);}
	inline CF operator * (const CF &B) const {
		u64 c4 = a1 * B.a3 + a2 * B.a2 + a3 * B.a1;
		return CF(
			a0 * B.a0 - a2 * B.a3 - a3 * B.a2 - c4,
			a0 * B.a1 + a1 * B.a0 - a3 * B.a3 + c4,
			a0 * B.a2 + a1 * B.a1 + a2 * B.a0 - c4,
			a0 * B.a3 + a1 * B.a2 + a2 * B.a1 + a3 * B.a0 + c4
		);
	}
	inline CF & operator += (const CF &B) {return *this = *this + B;}
	inline CF & operator -= (const CF &B) {return *this = *this - B;}
	inline CF & operator *= (const CF &B) {return *this = *this * B;}
	inline CF operator ^ (int n) const {return Power<CF>(*this, n);}
} w[100];

int n;
CF c[N];

void FFT(CF **a, bool inv) {
	int i, j; CF b[10];
	for (i = 0; i < 10; ++i) for (j = 0; j < 10; ++j) b[i] += *a[j] * w[i * j];
	if (inv) std::reverse(b + 1, b + 10);
	for (i = 0; i < 10; ++i) *a[i] = b[i];
}

inline void FWT(CF *a, bool inv = false) {
	int i, j, k, l, len = 1; CF *buf[10];
	for (i = 0; i < 5; ++i, len *= 10)
		for (j = 0; j < N; j += len * 10)
			for (k = j; k < j + len; ++k) {
				for (l = 0; l < 10; ++l) buf[l] = a + (k + l * len);
				FFT(buf, inv);
			}
}

int main() {
	int i, x;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (*w = i = 1; i < 100; ++i) w[i] = w[i - 1] * CF(0, 1, 0, 0);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> x, ++c[x].a0;
	FWT(c);
	for (i = 0; i < N; ++i) c[i] = c[i] ^ n;
	FWT(c, true);
	for (i = 0; i < n; ++i) cout << ((c[i].a0 / 32 * iv3125) & mask) << '\n';
	return 0;
}