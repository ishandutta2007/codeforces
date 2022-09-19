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
sim> struct rge {c h, n;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim, class F> struct umm {c m; F f; bool r;};
sim, class F> umm<c, F> mask_iter(c a, F f, bool r = false) {return umm<c, F>{a, f, r};}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
using ll = long long; using ld = long double; using ull = unsigned long long;
using pii = pair <int, int>; using vpii = vector <pii>; using unt = unsigned int;
#define hur(f, g) int f(unt a) {return g(a);} int f(int a) {return g(a);} \
int f(ll a) {return g##ll(a);} int f(ull a) {return g##ll(a);}
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)
struct muu {
#ifdef LOCAL
	stringstream a;
	muu & operator<<(string c) {ris << '\"' << c.c_str() << '\"';}
	~muu() {cerr << a.str() << "\033[0m" << endl;}
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
		a << "[";
		for (c s = u.h; s != u.n; ++s)
			u.f(*this << ", " + 2 * (s == u.h), *s);
		ris << "]";
	}
	sim, class F mor umm<c, F> u) {
		a << "[";
		int q = 0;
		if (!u.r) {
			forbits(i, u.m)
				u.f(*this << ", " + 2 * !q++, i);
		} else {
			fordbits(i, u.m)
				u.f(*this << ", " + 2 * !q++, i);
		}
		ris << "]";
	}
#else
	sim mor const c&) {ris;}
#endif
	muu & operator()() {ris;}
};
sim> void mini(c &a, c b) { if (a > b) a = b; }
sim> void maxi(c &a, c b) { if (a < b) a = b; }
#ifdef LOCAL
muu & operator<<(muu &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
muu & operator<<(muu &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
#endif
#define debug (muu() << "\033[1;"<<30+__LINE__%8<<"m"<< __FUNCTION__ << "#" << __LINE__ << ": \033[" << 30+(int)(__LINE__*3.125)%8<<"m")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << mask_iter(r, [](muu &d, int x){d << x;}) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
#define f first
#define s second
#define vsv sim, class d, class e
#define nop(o,c,r,l...) auto operator o(c a, r b)-> decltype(make_pair(l)) {return {l};}
#define pcg(o) vsv, class f> nop(o, pair <c u d>, pair <e u f>, a.f o b.f, a.s o b.s) \
vsv,class = typename enable_if<!is_same<c, muu>::value>::type> nop(o, c, pair<d u e>, a o b.f, a o b.s) \
vsv> nop(o, pair<c u d>, e, a.f o b, a.s o b)
#define clp(o) pcg(o) \
vsv> void operator o##= (pair <c,d> & a, e b) {a.f o##= b; a.s o##= b;} \
vsv, class f> void operator o##= (pair <c,d> & a, pair <e,f> b) {a.f o##= b.f; a.s o##= b.s;}
#define syd(o) sim, class d> auto operator o(pair<c, d> e) -> decltype(make_pair(o e.f, o e.s)) {return {o e.f, o e.s};}
#define u ,
clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)
#undef u
#define rans return ans
const int nax = 1e5 + 44;
pii painters[nax];
int covered[nax];
int ones_sum[nax];
int two_sum[nax];
int sum(int s[], pii x) {
	return s[x.second] - s[x.first - 1];
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	int ans = 0;
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		painters[i] = pii(l, r);
		for (int x = l; x <= r; ++x)
			covered[x]++;
	}
	for (int i = 1; i <= n; ++i)
		ones_sum[i] = ones_sum[i - 1] + (covered[i] == 1);
	for (int i = 1; i <= n; ++i)
		two_sum[i] = two_sum[i - 1] + (covered[i] == 2);
	int total = 0;
	for (int i = 0; i <= n; ++i)
		if (covered[i])
			total++;
	for (int i = 0; i < q; ++i)
		for (int j = i + 1; j < q; ++j) {
			int curr = total;
			curr -= sum(ones_sum, painters[i]);
			curr -= sum(ones_sum, painters[j]);
			pii inte = pii(max(painters[i].first, painters[j].first), min(painters[i].second, painters[j].second));
			if (inte.first <= inte.second)
				curr -= sum(two_sum, inte);
			maxi(ans, curr);
			debug << arr(painters, i) arr(painters, j) imie(curr);
		}
	printf("%d\n", ans);
}