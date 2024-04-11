#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, int> pr;
typedef std::map <ll, int> map;
const int N = 10000054;

ll n, x, ans;
int omega;
int pn = 0, c[N], p[666666];
pr ft[54], fg[54][54];
map D;

ll Power(ll a, ll n, ll c = 1) {for (; n; n >>= 1, a *= a) if (n & 1) c *= a; return c;}

ll MulMod(ll a, ll b, ll m) {return (__int128)a * b % m;}

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

void factor(ll n) {
	int i = 0, j;
	for (omega = 0; n != 1; ) {
		if (n >= N) {
			for (; (ll)p[i] * p[i] <= n && n % p[i]; ++i);
			if (n % p[i]) {ft[omega++] = pr(n, 1); return;}
		} else i = c[n];
		for (j = 0; !(n % p[i]); n /= p[i], ++j);
		ft[omega++] = pr(p[i], j);
	}
}

void refactor(ll n, pr *out) {
	int i = 0, j;
	for (; n != 1; ) {
		if (n >= N) {
			for (; (ll)p[i] * p[i] <= n && n % p[i]; ++i);
			if (n % p[i]) {*out++ = pr(n, 1); return;}
		} else i = c[n];
		for (j = 0; !(n % p[i]); n /= p[i], ++j);
		*out++ = pr(p[i], j);	
	}
}

inline void push(ll p, int a) {if (!(D[p] += a)) D.erase(p);}

inline void modify(pr *seq, int coef) {for (; seq->first; ++seq) push(seq->first, seq->second * coef);}

// Assume : (x, n) = 1.
ll MultiplicativeOrder(ll x, ll n, ll phi_n) {
	if (n == 1) return 1;
	ll partial, R, ret = 1; x %= n;
	for (const pr &d : D) {
		partial = phi_n / Power(d.first, d.second);
		for (R = PowerMod(x, partial, n); R != 1; ret *= d.first) R = PowerMod(R, d.first, n);
	}
	return ret;
}

void dfs(int dep, ll v, ll phi) {
	if (dep >= omega) {ans += phi / MultiplicativeOrder(x, v, phi); return;}
	for (int i = 0; i <= ft[dep].second; ++i)
		dfs(dep + 1, v, phi), v *= ft[dep].first, phi *= ft[dep].first - !i,
		i ? push(ft[dep].first, 1) : modify(fg[dep], 1);
	push(ft[dep].first, -ft[dep].second), modify(fg[dep], -1);
}

int main() {
	sieve(N - 1);	
	scanf("%lld%lld", &n, &x), factor(n);
	for (int i = 0; i < omega; ++i) refactor(ft[i].first - 1, fg[i]);
	dfs(0, 1, 1), printf("%lld\n", ans);
	return 0;
}