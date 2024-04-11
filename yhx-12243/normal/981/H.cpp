#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg

typedef long long ll;
const int N = 265000, mod = 998244353, iv2 = (mod + 1) / 2, root = 31;
typedef int vec[N], *pvec;
typedef std::vector <int> vector;

vec fact, finv;

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

inline ll A(int n, int r) {return (ll)fact[n] * finv[n - r] % mod;}

namespace Poly {
	int l, n;
	vec rev, x, y;

	void NTT_init(int len) {
		if (l == len) return; n = 1 << (l = len);
		ll g = PowerMod(root, 1 << (23 - l));
		*x = 1, *rev = 0;
		for (int i = 1; i < n; ++i)
			x[i] = x[i - 1] * g % mod, rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
	}

	void DNTT(int *d, int *t) {
		int i, *j, *k, len = 1, delta = n, R;
		for (i = 0; i < n; ++i) t[rev[i]] = d[i];
		for (i = 0; i < l; ++i) {
			delta >>= 1;
			for (k = x, j = y; j < y + len; k += delta, ++j) *j = *k;
			for (j = t; j < t + n; j += len << 1)
				for (k = j; k < j + len; ++k)
					R = (ll)y[k - j] * k[len] % mod,
					k[len] = (*k - R < 0 ? *k - R + mod : *k - R),
					*k = (*k + R >= mod ? *k + R - mod : *k + R);
			len <<= 1;
		}
	}

	vec B1, B2, B3;

	void Mul(vector &a, vector &b, vector &ret) {
		int degA = a.size() - 1, degB = b.size() - 1;
		if (!(degA || degB)) {ret.EB((ll)a[0] * b[0] % mod); return;}
		NTT_init(lg2(degA + degB) + 1);
		int i; ll iv = mod - (mod - 1) / n;
		memcpy(B1, a.data(), (degA + 1) << 2), memset(B1 + (degA + 1), 0, (n - degA - 1) << 2);
		memcpy(B2, b.data(), (degB + 1) << 2), memset(B2 + (degB + 1), 0, (n - degB - 1) << 2);
		DNTT(B1, B3), DNTT(B2, B1);
		for (i = 0; i < n; ++i) B1[i] = (ll)B1[i] * B3[i] % mod;
		DNTT(B1, B3), std::reverse(B3 + 1, B3 + n); ret.clear(), ret.reserve(degA + degB + 1);
		for (i = 0; i <= degA + degB; ++i) ret.EB(B3[i] * iv % mod);
	}
}

int n, K, E = 0;
int to[N], first[N], next[N];
int p[N], size[N], D[N], U[N];
int Ds[N], Us[N];
int result[N], tag[N];
vec f, g;

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

namespace DiConquer {
	int cnt = 0;
	vector g[N];

	int solve(int L, int R) {
		if (L + 1 == R) return L;
		int M = (L + R) / 2, id = cnt++, lp = solve(L, M), rp = solve(M, R);
		return Poly::Mul(g[lp], g[rp], g[id]), id;
	}
}

void dfs(int x) {
	int i, j, y, sy, deg = 0; ll c; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) p[y] = x, dfs(y), size[x] += size[y];
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) DiConquer::g[deg++] = {1, size[y]};
	if (deg) {
		DiConquer::cnt = deg;
		vector &t = DiConquer::g[DiConquer::solve(0, deg)];
		for (i = 0; i <= deg && i <= K; ++i) D[x] = (D[x] + A(K, i) * t[i]) % mod;
		memcpy(f, t.data(), (deg + 1) << 2);
	} else D[x] = *f = 1;
	c = n - size[x];
	for (f[i = deg + 1] = 0; i; --i) f[i] = (f[i] + f[i - 1] * c) % mod;
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) {
			if (tag[ sy = size[y] ] == x) {U[y] = result[sy]; continue;}
			c = mod - sy, *g = 1;
			for (j = 1; j <= deg; ++j) g[j] = (f[j] + g[j - 1] * c) % mod;
			for (j = 0; j <= deg && j <= K; ++j) U[y] = (U[y] + A(K, j) * g[j]) % mod;
			tag[sy] = x, result[sy] = U[y];
		}
	Ds[x] = D[x];
	for (i = first[x]; i; i = next[i]) if (p[y = to[i]] == x) add(Ds[x], Ds[y]);
}

int main() {
	int i, u, v, s = 0, ans = 0; init();
	if (scanf("%d%d", &n, &K), K == 1) return printf("%d\n", int(n * (n - 1ll) / 2 % mod)), 0;
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	dfs(1);
	for (i = 1; i <= n; ++i) add(s, D[i]), ans = (ans + (ll)s * D[i]) % mod;
	for (i = 1; i <= n; ++i) ans = (ans + ll(U[i] - D[i]) * Ds[i]) % mod;
	printf("%d\n", ans + (ans >> 31 & mod));
	return 0;
}