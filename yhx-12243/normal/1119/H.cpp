#include <bits/stdc++.h>

typedef long long ll;
const int N = 132540, mod = 998244353;
typedef int vec[N];

int n, K; ll X, Y, Z;
vec A, B, C, AB, BC, CA, ABC;
ll Fy[8], final[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

template <typename T>
void FWT(int len, T *f) {
	int i, j; T r;
	for (i = 0; i < len; ++i)
		for (j = 0; j < 1 << len; ++j)
			if (!(j >> i & 1))
				r = f[j | 1 << i], f[j | 1 << i] = f[j] - r, f[j] += r;
}

int main() {
	int i, j, k, fy[8], a, b, c; ll r, iv;
	scanf("%d%d%lld%lld%lld", &n, &K, &X, &Y, &Z);
	Fy[0] = (-X - Y - Z) % mod,
	Fy[1] = (X - Y - Z) % mod,
	Fy[2] = (-X + Y - Z) % mod,
	Fy[3] = (X + Y - Z) % mod,
	Fy[4] = (-X - Y + Z) % mod,
	Fy[5] = (X - Y + Z) % mod,
	Fy[6] = (-X + Y + Z) % mod,
	Fy[7] = (X + Y + Z) % mod;
	for (i = 0; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		++A[a], ++B[b], ++C[c],
		++AB[a ^ b], ++BC[b ^ c], ++CA[c ^ a],
		++ABC[a ^ b ^ c];
	}
	FWT(K, A), FWT(K, B), FWT(K, C), FWT(K, AB), FWT(K, BC), FWT(K, CA), FWT(K, ABC);
	for (i = 0; i < 1 << K; ++i) {
		*fy = n;
		fy[1] = A[i];
		fy[2] = B[i];
		fy[4] = C[i];
		fy[3] = AB[i];
		fy[6] = BC[i];
		fy[5] = CA[i];
		fy[7] = ABC[i];
		FWT(3, fy), std::reverse(fy, fy + 8);
		for (r = 1, j = 0; j < 8; ++j)
			r = r * PowerMod(Fy[j], fy[j] / 8) % mod, assert(fy[j] % 8 == 0);
		final[i] = r;
	}
	FWT(K, final), iv = PowerMod(2, mod - 1 - K);
	for (i = 0; i < 1 << K; ++i) {
		r = final[i] % mod * iv % mod;
		printf("%lld%c", r + (r >> 63 & mod), i == (1 << K) - 1 ? 10 : 32);
	}
	return 0;
}