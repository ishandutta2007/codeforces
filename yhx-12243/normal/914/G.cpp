#include <bits/stdc++.h>
#define lg2 std::__lg
#define popc __builtin_popcount
using std::cin;
using std::cout;

typedef long long ll;
typedef unsigned long long u64;
const int N = 18, N2 = 131100, mod = 1000000007;
typedef int vec[N2], *pvec, mat[N2][N], (*pmat)[N];

int n, ALL;
vec A, B, C, f;
mat Cs;

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}
inline void addVec(int *a, int *b) {for (int i = 0; i <= n; ++i) add(a[i], b[i]);}
inline void subVec(int *a, int *b) {for (int i = 0; i <= n; ++i) sub(a[i], b[i]);}

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

#define mobius(f, type, g) void f(type a) { \
		int i, j, k, len = 1; \
		for (i = 0; i < n; ++i, len <<= 1) \
			for (j = 0; j <= ALL; j += len << 1) \
				for (k = j; k < j + len; ++k) g; \
	}

mobius(FMT, pvec, add(a[k], a[k + len]))
mobius(IFMT, pvec, sub(a[k], a[k + len]))
mobius(FWT, pvec, ({int r = a[k + len]; reduce(a[k + len] = a[k] - r), add(a[k], r);}))
mobius(setFMT, pmat, addVec(a[k + len], a[k]))
mobius(setIFMT, pmat, subVec(a[k + len], a[k]))

void poly_sqr(pvec a) {
	int i, j; u64 R;
	for (i = n; i >= 0; a[i--] = R % mod)
		for (R = j = 0; j <= i; ++j) R += (u64)a[j] * a[i - j];
}


int main() {
	int i, x; ll iv, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> i; i; --i) cin >> x, ++A[x], up(n, x);
	n = lg2(2 * n + 1), ALL = ~(-1 << n), iv = PowerMod(2, mod - 1 - n);
	for (f[1] = f[2] = 1, i = 3; i <= ALL; ++i) add(f[i] = f[i - 1], f[i - 2]);

	memcpy(B, A, 4 << n), FWT(B);
	for (i = 0; i <= ALL; ++i) B[i] = (ll)B[i] * B[i] % mod;
	FWT(B);
	for (i = 0; i <= ALL; ++i) B[i] = B[i] * iv % mod;

	for (i = 0; i <= ALL; ++i) Cs[i][popc(i)] = A[i];
	setFMT(Cs);
	for (i = 0; i <= ALL; ++i) poly_sqr(Cs[i]);
	setIFMT(Cs);
	for (i = 0; i <= ALL; ++i) C[i] = Cs[i][popc(i)];

	for (i = 0; i <= ALL; ++i) A[i] = (ll)A[i] * f[i] % mod, B[i] = (ll)B[i] * f[i] % mod, C[i] = (ll)C[i] * f[i] % mod;

	FMT(A), FMT(B), FMT(C);
	for (i = 0; i <= ALL; ++i) A[i] = (ll)A[i] * B[i] % mod * C[i] % mod;
	IFMT(A);

	for (i = 1; i <= ALL; i <<= 1) ans += A[i];
	cout << int(ans % mod) << '\n';
	return 0;
}