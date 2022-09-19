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
sim> void mini(c &a, c b) { if (a > b) a = b; }
sim> void maxi(c &a, c b) { if (a < b) a = b; }
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int mod = 1e9 + 7;
long long inv(long long b) {
	assert(b);
	int e = mod - 2;
	long long r = 1;
	while (e) {
		if (e & 1)
			r = r * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return r;
}
#ifdef LOCAL 
#define loc(r...) r
#else
#define loc(...)
#endif
struct zet_p {
	int v;
	loc(long double w;)
	sim = int> zet_p(c r = 0) : v(r % mod) loc(, w(r)) {}
	loc(sim> zet_p(c a, long double b) : v(a % mod), w(b) {})
	#define rer(o, f) zet_p operator o (zet_p y) {return zet_p(v f loc(, w o y.w));} \
		zet_p & operator o##=(zet_p y) {ris = *this o y;}
	rer(+, +y.v) rer(-, -y.v) rer(*, * 1ll * y.v) rer(/, * inv(y.v))
	int get() {return ((unsigned int)v + mod) % mod;} //Rzutowanie jest potrzebne tylko, jeli 2*mod nie mieci si w incie
	zet_p operator-(){return zet_p(-v loc(, -w));}
	bool operator==(zet_p y) {return (v - y.v) % mod == 0;}
};
#define ccy(o) sim> zet_p operator o(c a, zet_p b) {return zet_p(a) o b;}
ccy(+) ccy(-) ccy(*) ccy(/)
sim> bool operator == (c a, zet_p b) {return zet_p(a) == b;}
loc(muu & operator<<(muu & d, zet_p y) {return d << "<" << y.get() << "=" << y.w << ">";})
const int nax = 55, kax = 1e4 + 44;
zet_p dp[nax][kax];
#define inv inviii
zet_p inv[kax];
int k;
zet_p get(long long p, int e) {
	for (int i = 0; i < nax; ++i)
		for (int j = 0; j < kax; ++j)
			dp[i][j] = 0;
	dp[e][0] = 1;
	for (int i = 1; i <= k; ++i)
		for (int x = 0; x <= e; ++x) {
			zet_p di = dp[x][i - 1] * inv[x + 1];
			for (int be = 0; be <= x; ++be)
				dp[be][i] += di;
		}	
	zet_p ans = 0;
	zet_p powe = 1;
	for (int i = 0; i <= e; ++i) {
		ans += powe * dp[i][k];
		if (i != e)
			powe *= p;
	}
	return ans;
}
int main() {
	long long n;
	scanf("%lld%d", &n, &k);
	zet_p ans = 1;
	for (int i = 1; i < kax; ++i)
		inv[i] = zet_p(1) / i;
	for (long long p = 2; p * p <= n; ++p) {
		int e = 0;
		while (n % p == 0) {
			e++;
			n /= p;
		}
		if (e > 0)
			ans *= get(p, e);
	}
	if (n > 1)
		ans *= get(n, 1);
	debug << imie(ans);
	printf("%d\n", ans.get());
}