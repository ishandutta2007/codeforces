#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 530000, mod = 998244353, iv2 = (mod + 1) / 2, unity = 31;
typedef int vec[N], *pvec;
typedef std::vector <int> vector;

vec inv, fact, finv;

inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline int & neg(int &x) {return x = (!x - 1) & (mod - x);}
u64 PowerMod(u64 a, int n, u64 c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

namespace poly_base {
	int l, n; u64 iv; vec w2;

	void init(int n = N, bool dont_calc_factorials = true) {
		int i, t;
		for (inv[1] = 1, i = 2; i < n; ++i) inv[i] = u64(mod - mod / i) * inv[mod % i] % mod;
		if (!dont_calc_factorials) for (*finv = *fact = i = 1; i < n; ++i) fact[i] = (u64)fact[i - 1] * i % mod, finv[i] = (u64)finv[i - 1] * inv[i] % mod;
		t = min(n > 1 ? lg2(n - 1) : 0, 21),
		*w2 = 1, w2[1 << t] = PowerMod(unity, 1 << (21 - t));
		for (i = t; i; --i) w2[1 << (i - 1)] = (u64)w2[1 << i] * w2[1 << i] % mod;
		for (i = 1; i < n; ++i) w2[i] = (u64)w2[i & (i - 1)] * w2[i & -i] % mod;
	}

	inline void NTT_init(int len) {n = 1 << (l = len), iv = mod - (mod - 1) / n;}

	void DIF(int *a) {
		int i, *j, *k, len = n >> 1, R, *o;
		for (i = 0; i < l; ++i, len >>= 1)
			for (j = a, o = w2; j != a + n; j += len << 1, ++o)
				for (k = j; k != j + len; ++k)
					R = (u64)*o * k[len] % mod, reduce(k[len] = *k - R), reduce(*k += R - mod);
	}

	void DIT(int *a) {
		int i, *j, *k, len = 1, R, *o;
		for (i = 0; i < l; ++i, len <<= 1)
			for (j = a, o = w2; j != a + n; j += len << 1, ++o)
				for (k = j; k != j + len; ++k)
					reduce(R = *k + k[len] - mod), k[len] = u64(*k - k[len] + mod) * *o % mod, *k = R;
	}

	inline void DNTT(int *a) {DIF(a);}
	inline void IDNTT(int *a) {
		DIT(a), std::reverse(a + 1, a + n);
		for (int i = 0; i < n; ++i) a[i] = a[i] * iv % mod;
	}

	inline void DIF(int *a, int *b) {memcpy(b, a, n << 2), DIF(b);}
	inline void DIT(int *a, int *b) {memcpy(b, a, n << 2), DIT(b);}
	inline void DNTT(int *a, int *b) {memcpy(b, a, n << 2), DNTT(b);}
	inline void IDNTT(int *a, int *b) {memcpy(b, a, n << 2), IDNTT(b);}
}

int n, m, cnt = 0;
int w[N], pw2[N];
int ip2[N];
int a[N];

struct node {
	vector a00, a01, a10, a11;
	inline void init(int penalty) {
		a01 = a10 = {0, 0}, a00 = {1, 0}, a11 = {0, ip2[penalty]};
	}
} g[N];

vec L00, L01, L10, L11, R00, R01, R10, R11, F00, F01, F10, F11, final;

namespace pb = poly_base;

int solve(int L, int R) {
	int i, id = cnt++;
	if (L + 1 == R) {
		g[id].init((L == 0 && a[L] == 1) + (R == m - 1 && a[R] == 1));
		return id;
	}
	int M = (L + R) / 2, lp = solve(L, M), rp = solve(M, R);
	pb::NTT_init(lg2(R - L) + 1);
	memset(L00, 0, pb::n << 3), memcpy(L00, g[lp].a00.data(), (M - L + 1) << 2);
	memset(L01, 0, pb::n << 3), memcpy(L01, g[lp].a01.data(), (M - L + 1) << 2);
	memset(L10, 0, pb::n << 3), memcpy(L10, g[lp].a10.data(), (M - L + 1) << 2);
	memset(L11, 0, pb::n << 3), memcpy(L11, g[lp].a11.data(), (M - L + 1) << 2);
	memset(R00, 0, pb::n << 3), memcpy(R00, g[rp].a00.data(), (R - M + 1) << 2);
	memset(R01, 0, pb::n << 3), memcpy(R01, g[rp].a01.data(), (R - M + 1) << 2);
	memset(R10, 0, pb::n << 3), memcpy(R10, g[rp].a10.data(), (R - M + 1) << 2);
	memset(R11, 0, pb::n << 3), memcpy(R11, g[rp].a11.data(), (R - M + 1) << 2);
	memset(F00, 0, pb::n << 3);
	memset(F01, 0, pb::n << 3);
	memset(F10, 0, pb::n << 3);
	memset(F11, 0, pb::n << 3);
	pb::DIF(L00), pb::DIF(L01), pb::DIF(L10), pb::DIF(L11);
	pb::DIF(R00), pb::DIF(R01), pb::DIF(R10), pb::DIF(R11);
	if (a[M] != 1) {
		for (i = 0; i < pb::n; ++i) {
			F00[i] = ((u64)L00[i] * R00[i] + (u64)L00[i] * R10[i] + (u64)L01[i] * R00[i] + (u64)L01[i] * R10[i]) % mod;
			F01[i] = ((u64)L00[i] * R01[i] + (u64)L00[i] * R11[i] + (u64)L01[i] * R01[i] + (u64)L01[i] * R11[i]) % mod;
			F10[i] = ((u64)L10[i] * R00[i] + (u64)L10[i] * R10[i] + (u64)L11[i] * R00[i] + (u64)L11[i] * R10[i]) % mod;
			F11[i] = ((u64)L10[i] * R01[i] + (u64)L10[i] * R11[i] + (u64)L11[i] * R01[i] + (u64)L11[i] * R11[i]) % mod;
		}
	} else {
		for (i = 0; i < pb::n; ++i) {
			F00[i] = ((u64)L00[i] * R00[i] + (u64)L00[i] * R10[i] + (u64)L01[i] * R00[i] + (u64)L01[i] * R10[i] % mod * iv2) % mod;
			F01[i] = ((u64)L00[i] * R01[i] + (u64)L00[i] * R11[i] + (u64)L01[i] * R01[i] + (u64)L01[i] * R11[i] % mod * iv2) % mod;
			F10[i] = ((u64)L10[i] * R00[i] + (u64)L10[i] * R10[i] + (u64)L11[i] * R00[i] + (u64)L11[i] * R10[i] % mod * iv2) % mod;
			F11[i] = ((u64)L10[i] * R01[i] + (u64)L10[i] * R11[i] + (u64)L11[i] * R01[i] + (u64)L11[i] * R11[i] % mod * iv2) % mod;
		}
	}
	pb::IDNTT(F00), pb::IDNTT(F01), pb::IDNTT(F10), pb::IDNTT(F11);
	g[id].a00 = vector(F00, F00 + (R - L + 1));
	g[id].a01 = vector(F01, F01 + (R - L + 1));
	g[id].a10 = vector(F10, F10 + (R - L + 1));
	g[id].a11 = vector(F11, F11 + (R - L + 1));
	return id;
}

int main() {
	int i, l, r = 0, cur, ret; u64 ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> w[i];
	for (*ip2 = *pw2 = i = 1; i <= n; ++i)
		pw2[i] = pw2[i - 1] * 2 % mod,
		ip2[i] = (u64)ip2[i - 1] * iv2 % mod;
	for (i = 0; i < n; i = r) {
		l = r, r += w[i];
		if (r > n || std::count(w + l, w + r, w[i]) != r - l) return cout << "0\n", 0;
		a[m++] = r - l;
	}

	if (m == 1) return cout << (*a == 1 ? 1 : 2) << '\n', 0;

	pb::init(N, false);
	ret = solve(0, m - 1);

	for (i = 0; i < m; ++i) final[i] = ((u64)g[ret].a00[i] + g[ret].a01[i] + g[ret].a10[i] + g[ret].a11[i]) % mod;

	for (i = 0; i < m; ++i)
		cur = (u64)pw2[m - i] * fact[m - i] % mod * final[m - i - 1] % mod,
		i & 1 ? ans += mod - cur : ans += cur;
	cout << ans % mod << '\n';
	return 0;
}