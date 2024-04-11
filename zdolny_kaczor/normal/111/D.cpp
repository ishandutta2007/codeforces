//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c h, n;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << '{';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << '}';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.n; ++s)
			u.f(*this << ", " + 2 * (s == u.h), *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
	muu & operator()() {ris;}
};
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int nax = 1e6 + 44, mod = 1e9 + 7;
int fac[nax], fin[nax];
int powe(int b, int e) {
	int r = 1;
	while (e) {
		if (e & 1) r = r * 1ll * b % mod;
		b = b * 1ll * b % mod;
		e >>= 1;
	}
	return r;
}
long long binom(int a, int b) {
	if (a < b || b < 0)
		return 0;
	return fac[a] * 1ll * fin[b] % mod * fin[a - b] % mod;
}
int sur[nax];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (m == 1)
		return 0 * printf("%d\n", powe(k, n));
	fac[0] = 1;
	for (int i = 1; i < nax; ++i)
		fac[i] = fac[i - 1] * 1ll * i % mod;
	fin[nax - 1] = powe(fac[nax - 1], mod - 2);
	for (int i = nax - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1ll) % mod;
	for (int i = 1; i <= n; ++i) {
		sur[i] = powe(i, n);
		for (int j = 0; j < i; ++j)
			sur[i] = (sur[i] - sur[j] * binom(i, j)) % mod;
		if (sur[i] < 0)
			sur[i] += mod;
	}
	debug << range(sur, sur + n + 1);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int c = 0; c <= i; ++c) {
			ans += sur[i] * 1ll * sur[i] % mod *
				binom(k, i) % mod *
				binom(i, c) % mod *
				binom(k - i, i - c) % mod * 
				powe(c, n * (m - 2)) % mod;
		}
	ans %= mod;
	if (ans < 0)
		ans += mod;
	printf("%lld\n", ans);
}