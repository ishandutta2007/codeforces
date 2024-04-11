#include <bits/stdc++.h>
#define lg2(x) (31 - __builtin_clz(x))

typedef long long ll;
const int N = 1054, SN = 25;
typedef int vec[N], *pvec;

int mod, n, B;
vec a, b, ia, C1, ans;
vec fact, inv, finv;
vec all[SN];
int q, qry[N];

inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(int n) {
	int i;
	for (inv[1] = 1, i = 2; i <= n; ++i) inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
	for (*finv = *fact = i = 1; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % mod, finv[i] = (ll)finv[i - 1] * inv[i] % mod;
}

void conv(int n, int *a, int *b, int *ret) {
	int i, j;
	if (n < 16) {
		static unsigned long long Ret[33];
		memset(Ret, 0, (n * 2 + 1) << 3);
		for (i = 0; i <= n; ++i)
			for (j = 0; j <= n; ++j)
				Ret[i + j] += (ll)a[i] * b[j];
		for (i = 0; i <= n * 2; ++i) ret[i] = Ret[i] % mod;
	} else {
		memset(ret, 0, (n * 2 + 1) << 2);
		int h = n / 2 + 1, u[h], v[h], w[2 * h - 1];
		conv(h - 1, a, b, ret); conv(n - h, a + h, b + h, ret + h * 2);
		for (i = 0; i < h; ++i) u[i] = a[i], v[i] = -b[i];
		for (i = 0; i <= n - h; ++i) u[i] -= a[i + h], v[i] += b[i + h];
		for (i = 0; i < h; ++i) u[i] += u[i] >> 31 & mod, v[i] += v[i] >> 31 & mod;
		conv(h - 1, u, v, w);
		for (i = 2 * (n - h); i >= 0; --i) add(w[i], ret[i + h * 2]);
		for (i = 2 * (h - 1); i >= 0; --i) add(ret[i + h], w[i]), add(ret[i + h], ret[i]);
	}
}

int main() {
	int i, j, k, d; ll ret;
	scanf("%d%d", &q, &mod);
	for (i = 0; i < q; ++i) scanf("%d", qry + i);
	n = *std::max_element(qry, qry + q), init(n + 1);
	for (i = 0; i <= n; ++i) a[i] = fact[i + 1];
	for (*ia = i = 1; i <= n; reduce(ia[i++]))
		for (j = 0; j < i; ++j) ia[i] = (ia[i] - (ll)ia[j] * a[i - j]) % mod;	
	B = sqrt(n), **all = *b = 1;
	for (j = 1; j <= B; ++j) conv(n, all[j - 1], ia, all[j]), memset(all[j] + n, 0, n << 2);
	for (d = 1, j = 0; j < n; j += B) {
		for (k = 1; k <= B && d <= n; ++k, ++d) {
			for (ret = i = 0; i < d; ++i) ret = (ret + (ll)all[k][i] * b[d - i - 1]) % mod;
			ans[d] = ret * inv[d] % mod;
		}
		conv(n, b, all[B], C1), memcpy(b, C1, n << 2);
	}
	std::iota(ans, ans + 3, 0);
	for (i = 3; i <= n; ++i) reduce(ans[i] = (i & 1 ? 2 : -2) - ans[i]);
	for (i = 0; i < q; ++i) printf("%d\n", ans[qry[i]]);
	return 0;
}