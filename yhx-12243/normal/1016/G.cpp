#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, int> pr;
typedef std::map <ll, int> map;
const int N = 16, N2 = 65554;

int n, w = 0, ALL;
int inf[N], sup[N];
ll p[N], L[N2], R[N2];

namespace NT {
	const int N = 1000054;

	int pn = 0, c[N], p[78540];
	map result;

	inline ll MulMod(ll a, ll b, ll m) {return (__int128)a * b % m;}

	ll PowerMod(ll a, ll n, ll m) {
		if (!n || a == 1) return 1ll;
		ll s = PowerMod(a, n >> 1, m);
		s = MulMod(s, s, m);
		return n & 1 ? MulMod(s, a, m) : s;
	}

	void sieve(int n) {
		int i, j, v;
		memset(c, -1, sizeof c);
		for (i = 2; i <= n; ++i) {
			if (!~c[i]) p[pn] = i, c[i] = pn++;
			for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
		}
	}

	bool Miller_Rabin(ll n) {
		static const int test[8] = {2, 3, 5, 7, 11, 13, 82, 373};
		if (n < N) return n > 1 && p[c[n]] == n;
		int c, i, j; ll s = n - 1, u, v;
		for (c = 0; !(s & 1); ++c, s >>= 1);
		for (i = 0; i < 8; ++i) {
			if (!(n % test[i])) return false;
			u = PowerMod(test[i], s, n);
			for (j = 0; j < c; ++j, u = v)
				if (v = MulMod(u, u, n), u != 1 && u != n - 1 && v == 1) return false;
			if (u != 1) return false;
		}
		return true;
	}

	ll Pollard_Rho(ll n, int c) {
		ll i = 1, k = 2, x = rand() % (n - 1) + 1, y = x, p;
		for (; k <= 131072; ) {
			x = (MulMod(x, x, n) + c) % n;
			p = std::__gcd((y - x + n) % n, n);
			if (p != 1 && p != n) return p;
			if (++i == k) y = x, k <<= 1;
		}
		return 0;
	}

	inline void push(ll prime, int alpha) {result[prime] += alpha;}

	void __builtin_factor(ll n) {
		int i, j, k; ll d;
		for (i = 0; n != 1; )
			if (n >= N) {
				if (Miller_Rabin(n)) return push(n, 1);
				for (k = 97; !(d = Pollard_Rho(n, k)); --k);
				__builtin_factor(d), n /= d;
			} else {
				for (i = p[c[n]], j = 0; !(n % i); n /= i, ++j);
				push(i, j);
			}
	}

	inline void factor(ll n) {result.clear(), __builtin_factor(n);}

	inline void init() {sieve(N - 1);}
}

#define mobius(name, op) void name(ll *a) {							\
		int i, j, k, len = 1;										\
		for (i = 0; i < w; ++i, len <<= 1)							\
			for (j = 0; j <= ALL; j += len << 1)					\
				for (k = j; k < j + len; ++k) a[k + len] op a[k];	\
	}

mobius(FMT, +=);
mobius(IFMT, -=);

int main() {
	int i, j, S, cur[56]; ll t, X, Y; bool le, ri;
	scanf("%d%lld%lld", &n, &X, &Y);
	if (Y % X) return putchar(48), putchar(10), 0;
	NT::init(), NT::factor(Y), t = X;
	for (const pr &e : NT::result) {
		for (std::tie(p[w], sup[w]) = e; !(t % p[w]); t /= p[w], ++inf[w]);
		++w;
	}
	assert(t == 1 && w <= N), ALL = ~(-1 << w);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &t), le = !(t % X), ri = !(Y % t);
		for (j = 0; j < w; ++j)
			for (cur[j] = 0; !(t % p[j]); t /= p[j], ++cur[j]);
		if (le) {
			for (S = j = 0; j < w; ++j) S |= int(cur[j] == inf[j]) << j;
			++L[S];
		}
		if (ri) {
			for (S = j = 0; j < w; ++j) S |= int(cur[j] == sup[j]) << j;
			++R[S];
		}
	}
	for (S = i = 0; i < w; ++i) S |= int(inf[i] != sup[i]) << i;
	FMT(L), FMT(R);
	for (i = 0; i <= ALL; ++i) L[i] *= R[i];
	IFMT(L);
	for (t = 0, i = S; i <= ALL; i = (i + 1) | S) t += L[i];
	printf("%lld\n", t);
	return 0;
}