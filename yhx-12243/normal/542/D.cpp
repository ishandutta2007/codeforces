#include <bits/stdc++.h>
#define N 1000054
#define H 7000

typedef long long ll;
typedef long double ld;
typedef std::pair <ll, int> pr;
typedef std::map <ll, int> map;

const int bestfy[1001] = {0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 2, 0, 1, 0, 0, 1, 2, 0,
						  2, 0, 0, 0, 3, 0, 1, 0, 1, 0, 3, 0, 2, 1, 0, 0, 2, 0, 1, 0,
						  1, 0, 2, 0, 1, 0, 0, 0, 3, 0, 2, 0, 0, 0, 3, 0, 1, 0, 0, 0,
						  4, 0, 1, 0, 0, 1, 0, 0, 2, 0, 1, 0, 6, 0, 1, 0, 0, 0, 1, 0,
						  3, 0, 1, 0, 3, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4, 0, 1, 0,
						  1, 0, 2, 0, 2, 0, 0, 0, 3, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0,
						  5, 0, 1, 0, 0, 0, 3, 0, 2, 1, 1, 0, 3, 0, 0, 0, 1, 0, 1, 0,
						  3, 0, 0, 0, 5, 0, 0, 0, 0, 0, 3, 0, 2, 0, 0, 0, 0, 0, 1, 0,
						  3, 0, 2, 0, 1, 0, 0, 0, 5, 0, 2, 0, 0, 0, 1, 0, 1, 0, 0, 0,
						  6, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 5, 0, 1, 0, 0, 0, 2, 0,
						  3, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 7, 0, 0, 0,
						  1, 0, 1, 0, 2, 0, 0, 0, 2, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0,
						  11, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 6, 0, 0, 0, 1, 1, 1, 0,
						  2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0, 0, 0, 1, 0,
						  2, 0, 1, 0, 1, 0, 0, 0, 8, 0, 1, 0, 0, 0, 2, 0, 1, 0, 0, 0,
						  4, 0, 0, 0, 1, 0, 2, 0, 1, 0, 1, 0, 4, 0, 1, 0, 0, 0, 1, 0,
						  2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 6, 0, 1, 0,
						  2, 0, 2, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0,
						  11, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 2, 0,
						  2, 0, 0, 0, 6, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 3, 0, 1, 0,
						  3, 0, 1, 0, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0, 1, 0, 1, 0, 0, 0,
						  7, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 1, 0, 0, 0, 0, 0,
						  3, 0, 1, 0, 2, 0, 0, 0, 2, 0, 4, 0, 0, 0, 0, 0, 4, 0, 1, 0,
						  0, 0, 2, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
						  10, 0, 0, 0, 0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 0, 0, 1, 0, 0, 0,
						  2, 0, 0, 0, 10, 0, 0, 0, 0, 0, 4, 0, 1, 1, 0, 0, 1, 0, 0, 0,
						  4, 0, 2, 0, 1, 0, 0, 0, 3, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
						  10, 0, 1, 0, 3, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 2, 0,
						  3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 11, 0, 1, 0,
						  0, 0, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0,
						  11, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0,
						  2, 0, 0, 0, 3, 0, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 0,
						  5, 0, 1, 0, 1, 0, 1, 0, 8, 0, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0,
						  4, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 8, 0, 1, 0, 0, 0, 1, 0,
						  2, 0, 0, 0, 5, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 1, 0, 0, 0,
						  3, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
						  18, 0, 0, 0, 0, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 0, 0, 1, 0,
						  2, 0, 0, 0, 3, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 7, 0, 1, 0,
						  3, 0, 1, 0, 0, 0, 0, 0, 6, 0, 1, 0, 0, 0, 3, 0, 1, 0, 0, 0,
						  3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 7, 0, 0, 0, 0, 0, 1, 0,
						  3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 7, 0, 0, 0,
						  1, 0, 1, 0, 1, 0, 0, 0, 2, 0, 1, 0, 3, 0, 1, 0, 0, 0, 0, 0,
						  12, 0, 1, 0, 0, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 0, 0, 0, 2, 0,
						  1, 0, 0, 0, 12, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0,
						  3, 0, 3, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
						  8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 7, 0, 0, 0, 0, 0, 2, 0,
						  2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 0, 1, 0,
						  0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0,
						  15, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 0, 5, 0, 0, 0, 1, 0, 1, 0,
						  1, 0, 0, 0, 3, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 1, 0, 1, 0, 4
};

namespace NT {
	int pn = 0, c[N], p[80000];
	int cnt = 0;
	pr fac[50];

	ll Power(ll a, int n, ll c = 1) {for (; n; n >>= 1, a *= a) if (n & 1) c *= a; return c;}

	inline ll MulMod(ll a, ll b, ll m) {
		ll t = (a * b - (ll)((ld)a * b / m) * m) % m;
		return t + (t >> 63 & m);
	}

	ll PowerMod(ll a, ll n, ll m) {
		if (!n) return 1ll;
		ll s = PowerMod(a, n >> 1, m);
		s = MulMod(s, s, m);
		return n & 1 ? MulMod(s, a, m) : s;
	}

	void sieve(int n) {
		int i, j, v;
		for (i = 2; i <= n; ++i) {
			if (!c[i]) p[pn++] = i;
			for (j = 0; j < pn && (v = i * p[j]) <= n; ++j)
				if (c[v] = p[j], !(i % p[j])) break;
		}
	}

	inline void push(ll prime, int alpha) {fac[cnt++] = pr(prime, alpha);}

	void Factor(ll n) {
		int i, j; cnt = 0;
		for (i = 0; n > 1; )
			if (n >= N) {
				for (j = 0; i < pn && (ll)p[i] * p[i] <= n; ++i)
					if (!(n % p[i])) {
						for (; !(n % p[i]); n /= p[i], ++j);
						push(p[i], j); break;
					}
				if (!j) {push(n, 1); return;}
			} else {
				i = c[n] ? c[n] : n;
				for (j = 0; !(n % i); n /= i, ++j);
				push(i, j);
			}
	}

	const int test[8] = {2, 3, 5, 7, 11, 13, 82, 373};
	bool Miller_Rabin(ll n) {
		if (n < N) return !c[n] && n > 1;
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

	ll property(ll n) {
		if (n <= 1) return 0;
		int i; ll x;
		if (n < N) {
			for (i = c[n] ? c[n] : n; !(n % i); n /= i);
			return n == 1 ? i : 0;
		}
		for (i = 0; i < 25; ++i) if (!(n % p[i])) {
			for (; !(n % p[i]); n /= p[i]);
			return n == 1 ? p[i] : 0;
		}
		for (i = 1; i <= 6; ++i) {
			for (x = powl(n, 1.0L / (ld)i) - 1; Power(x, i) < n; ++x);
			if (Power(x, i) != n) continue;
			if (Miller_Rabin(x)) return x;
		}
		return 0;
	}
}

using NT::fac;

ll n;
ll dv[H], pcp[H], dp[H][1 << 12];
int m, Pcp, ppt[H], pcp_ppt[H], fy_pos[H];
map PS;

void dfs(int dep, ll cur) {
	if (dep == NT::cnt) {dv[m++] = cur; return;}
	for (int i = 0; i <= fac[dep].second; ++i, cur *= fac[dep].first) dfs(dep + 1, cur);
}

void work() {
	int i, j, k, l, g; ll r; map::iterator it;
	scanf("%lld", &n); Pcp = m = 0;
	if (n <= 1000) {printf("%d\n", bestfy[n]); return;}
	NT::Factor(n); dfs(0, 1); std::sort(dv, dv + m); PS.clear();
	for (i = 0; i < m; ++i)
		if (ppt[i] = NT::property(dv[i] - 1)) {
			if (it = PS.find(ppt[i]), it == PS.end()) PS.insert(pr(ppt[i], -1));
			else if (it->second == -1) pcp[Pcp] = ppt[i], it->second = Pcp++;
		}
	assert(Pcp <= 12);
	for (i = 0; i < m; ++i) pcp_ppt[i] = (ppt[i] ? PS[ppt[i]] : -1);
	memset(dp, 0, m << 15);
	dp[0][0] = 1;
	for (i = 1; i < m; ++i) if (ppt[i]) {
		r = n / dv[i]; g = pcp_ppt[i];
		for (k = 0; k < m - i; ++k)
			fy_pos[k] = (r % dv[k] ? -1 : std::lower_bound(dv, dv + m, dv[i] * dv[k]) - dv);
		for (k = m - i - 1; k >= 0; --k) if (~(l = fy_pos[k]))
			for (j = ~(-1 << Pcp); j >= 0; --j)
				if (dp[k][j]) {
					if (~g) j >> g & 1 ? 0 : dp[l][j | 1 << g] += dp[k][j];
					else dp[l][j] += dp[k][j];
				}
	}
	for (r = j = 0; j < 1 << Pcp; ++j) r += dp[m - 1][j];
	printf("%lld\n", r);
}

int main() {
	NT::sieve(N - 1); work();
	return 0;
}