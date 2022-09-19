//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define urs(r) typename remove_cv<typename remove_reference<decltype(r)>::type>::type
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
#define forbits(i, m) if (m) for (urs(m) i = ctz(m), quq = m; quq; quq ^= ((decltype(m))1 << i), i = ctz(quq)) 
#define fordbits(i, m) if (m) for (urs(m) i = 8 * sizeof(m) - clz(m) - 1, quq = m; quq; quq ^= ((decltype(m))1 << i), i = 8 * sizeof(m) - clz(quq) - 1)
sim> struct rge {c h, n;};sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim, class F> struct umm {c m; F f; bool r;};
sim, class F> umm<c, F> mask_iter(c a, F f, bool r = false) {return umm<c, F>{a, f, r};}
sim> auto dud(c *r) -> decltype(cerr << *r);sim> char dud(...);
using ll = long long; using ld = long double; using ull = unsigned long long;
using pii = pair <int, int>; using vpii = vector <pii>; using unt = unsigned int;
#define hur(f, g) int f(unt a) {return g(a);} int f(int a) {return g(a);} \
int f(ll a) {return g##ll(a);} int f(ull a) {return g##ll(a);}
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)struct muu {
#ifdef LOCAL
stringstream a;muu & operator<<(string c) {ris << '\"' << c.c_str() << '\"';}
~muu() {cerr << a.str() << "\033[0m" << endl;}R22(<) a << boolalpha << g; ris;}R22(==) ris << range(begin(g), end(g));}
sim mor rge<c> u) {int q = 0;a << '{';for (c s = u.h; s != u.n; ++s)*this << ", " + 2 * !q++ << *s;ris << "}_" << q;}
sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
sim, class F mor rgm<c, F> u) {int q = 0;a << "[";for (c s = u.h; s != u.n; ++s)u.f(*this << ", " + 2 * !q++, *s);ris << "]_" << q;}
sim, class F mor umm<c, F> u) {a << "[";int q = 0;if (!u.r) {forbits(i, u.m)u.f(*this << ", " + 2 * !q++, i);} else {fordbits(i, u.m)u.f(*this << ", " + 2 * !q++, i);}ris << "]";}
#else
sim mor const c&) {ris;}
#endif
};
sim>void factor(muu &d,c x){if(x<=1&&x+1>=0){d<<x;return;}d<<x<<"=";if(x<0){d<<"-";x=-x;}int q=0;for(c p=2;p*p<x;++p){int e=0;while(x%p==0){e++;x/=p;}if(e)d<<"*"+!q++<<p;if (e > 1)d<<"^"<<e;}if(x>1)d<<"*"+!q++<<x;}
sim> void mini(c &a, c b) { if (a > b) a = b; }sim> void maxi(c &a, c b) { if (a < b) a = b; }
#ifdef LOCAL
muu & operator<<(muu &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
muu & operator<<(muu &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
#endif
#define debug (muu() << "\033[1;"<<30+__LINE__%8<<"m"<< __FUNCTION__ << "#" << __LINE__ << ": \033[" << 30+(int)(__LINE__*3.125)%8<<"m")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << mask_iter(r, [](muu &d, int x){d << x;}) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
#define vsv sim, class d, class e
#define nop(o,c,r,l...) auto operator o(c a, r b)-> decltype(make_pair(l)) {return {l};}
#define pcg(o) vsv, class f> nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second) \
vsv,class = typename enable_if<!is_same<c, muu>::value>::type> nop(o, c, pair<d u e>, a o b.first, a o b.second) \
vsv> nop(o, pair<c u d>, e, a.first o b, a.second o b)
#define clp(o) pcg(o) \
vsv> void operator o##= (pair <c,d> & a, e b) {a.first o##= b; a.second o##= b;} \
vsv, class f> void operator o##= (pair <c,d> & a, pair <e,f> b) {a.first o##= b.first; a.second o##= b.second;}
#define syd(o) sim, class d> auto operator o(pair<c, d> e) -> decltype(make_pair(o e.first, o e.second)) {return {o e.first, o e.second};}
#define u ,
clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)
#undef u
#define rans return ans
const int mod = 1e9 + 7;
long long inv(long long b) {//To jest oczywicie dla mod pierwszego
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
	int get() {return (v + mod) % mod;}
	zet_p operator-(){return zet_p(-v loc(, -w));}
	bool operator==(zet_p y) {return (v - y.v) % mod == 0;}
};
#define ccy(o) sim> zet_p operator o(c a, zet_p b) {return zet_p(a) o b;}
ccy(+) ccy(-) ccy(*) ccy(/)
sim> bool operator == (c a, zet_p b) {return zet_p(a) == b;}
loc(muu & operator<<(muu & d, zet_p y) {return d << "<" << y.get() << "=" << y.w << ">";})
const int nax = 1e5 + 44;
#define div __div__
int div[nax];
zet_p dp[nax];
int m;
int sq_free(int x) {
	int ans = 1;
	while (x > 1) {
		int p = div[x];
		ans *= p;
		while (x % p == 0) x /= p;
	}
	rans;
}
vector <int> gen_primes(int x) {
	vector <int> primes;
	while (x > 1) {
		int p = div[x];
		primes.push_back(p);
		while (x % p == 0)
			x /= p;
	}
	return primes;
}
void go(int x) {
	int fr = sq_free(x);
	if (fr != x) {
		dp[x] = dp[fr];
		return;
	}
	vector <int> primes = gen_primes(x);
	debug << imie(primes);
	int l = primes.size();
	int cou[1 << l] = {};
	zet_p dp_taken[1 << l];
	for (int i = 0; i < (1 << l); ++i) {
		int p = 1;
		forbits(j, i) p *= primes[j];
		cou[i] = m / p;
		dp_taken[i] = dp[p];
	}
	for (int i = 0; i < l; ++i)
		for (int ma = 0; ma < (1 << l); ++ma)
			if (ma >> i & 1)
				cou[ma ^ (1 << i)] -= cou[ma];
	zet_p p_idle = cou[(1 << l) - 1] / zet_p(m), sum = 0;
	debug << imie(x) << range(cou, cou + (1 << l));
	int left = m - cou[(1 << l) - 1];
	for (int ma = 0; ma < (1 << l) - 1; ++ma)
		sum += dp_taken[ma] * cou[ma];
	debug << imie(x) imie(sum) imie(left) imie(p_idle);
	dp[x] = 1 / (1 - p_idle) + sum / left;
}
int main() {
	for (int i = 2; i < nax; ++i)
		if (div[i] == 0)
			for (int k = i; k < nax; k += i)
				div[k] = i;
	scanf("%d", &m);
	zet_p ans = 0;
	for (int i = 2; i <= m; ++i) {
		go(i);
		debug << arr(dp, i);
	}
	for (int i = 1; i <= m; ++i) ans += dp[i] + 1;
	ans /= m;
	printf("%d\n", ans.get());
}