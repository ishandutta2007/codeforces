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
sim>void factor(muu &d,c x){if(x<=1&&x+1>=0){d<<x;return;}d<<x<<"=";if(x<0){d<<"-";x=-x;}int q=0;for(c p=2;p*p<x;++p){int e=0;while(x%p==0){e++;x/=p;}if(e)d<<"*"+!q++<<p;if (e > 1)d<<"^"<<e;}if(x>1)d<<"*"+!q++<<x;}
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
const int nax = 8;
bool seen[nax][nax];
vpii ans;
bool bt(int x, int y, int dep) {
	if (dep == 0) {
		if (x == 7 && y == 7) {
			ans.emplace_back(x, y);
			return true;
		}
		return false;
	}
	seen[x][y] = true;
	vector <pii> to;
	for (int i = 0; i < nax; ++i) {
		if (i != x)
			to.emplace_back(i, y);
		if (i != y)
			to.emplace_back(x, i);
	}
	random_shuffle(to.begin(), to.end());
	for (pii c : to) {
		if (seen[c.first][c.second]) continue;
		if (bt(c.first, c.second, dep - 1)) {
			ans.emplace_back(x, y);
			return true;
		}
	}
	seen[x][y] = false;
	return false;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n == 2) printf("a1 h1 h8 \n");
if (n == 3) printf("a1 g1 g8 h8 \n");
if (n == 4) printf("a1 g1 e1 h1 h8 \n");
if (n == 5) printf("a1 g1 e1 e5 e8 h8 \n");
if (n == 6) printf("a1 g1 e1 e5 g5 g8 h8 \n");
if (n == 7) printf("a1 g1 e1 e5 g5 g8 a8 h8 \n");
if (n == 8) printf("a1 g1 e1 e5 g5 g8 a8 c8 h8 \n");
if (n == 9) printf("a1 g1 e1 e5 g5 g8 a8 a7 h7 h8 \n");
if (n == 10) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 h2 h8 \n");
if (n == 11) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 h2 h8 \n");
if (n == 12) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h8 \n");
if (n == 13) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 h8 \n");
if (n == 14) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 h7 h8 \n");
if (n == 15) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 c4 c8 h8 \n");
if (n == 16) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 c8 h8 \n");
if (n == 17) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 c5 h5 h8 \n");
if (n == 18) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 h8 \n");
if (n == 19) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 h5 h8 \n");
if (n == 20) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 b8 h8 \n");
if (n == 21) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e8 h8 \n");
if (n == 22) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 h6 h8 \n");
if (n == 23) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 h8 \n");
if (n == 24) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 h8 \n");
if (n == 25) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 c8 h8 \n");
if (n == 26) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 h5 h8 \n");
if (n == 27) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 h8 \n");
if (n == 28) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 h1 h8 \n");
if (n == 29) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c8 h8 \n");
if (n == 30) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 h6 h8 \n");
if (n == 31) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 h6 h8 \n");
if (n == 32) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 h6 h8 \n");
if (n == 33) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 h8 \n");
if (n == 34) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 h3 h8 \n");
if (n == 35) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d8 h8 \n");
if (n == 36) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 h8 \n");
if (n == 37) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 h3 h8 \n");
if (n == 38) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 h8 \n");
if (n == 39) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 d8 h8 \n");
if (n == 40) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c3 h3 h8 \n");
if (n == 41) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 d8 h8 \n");
if (n == 42) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 d4 d8 h8 \n");
if (n == 43) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f3 h3 h8 \n");
if (n == 44) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f3 h3 h8 \n");
if (n == 45) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 b8 h8 \n");
if (n == 46) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d8 h8 \n");
if (n == 47) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d8 h8 \n");
if (n == 48) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 h3 h8 \n");
if (n == 49) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 h3 h8 \n");
if (n == 50) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 h3 h8 \n");
if (n == 51) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 b3 h3 h8 \n");
if (n == 52) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 h3 b3 b8 h8 \n");
if (n == 53) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 f3 h3 h8 \n");
if (n == 54) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 h3 h8 \n");
if (n == 55) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 h3 h8 \n");
if (n == 56) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 b3 b8 h8 \n");
if (n == 57) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 b3 b5 b8 h8 \n");
if (n == 58) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 b3 b5 b6 b8 h8 \n");
if (n == 59) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 b3 b5 b6 b8 d8 h8 \n");
if (n == 60) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 b3 b5 b6 b1 b8 d8 h8 \n");
if (n == 61) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 a3 b3 b1 b5 b6 b8 d8 h8 \n");
if (n == 62) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 g2 g3 f3 a3 h3 b3 b1 b6 b5 b8 d8 h8 \n");
if (n == 63) printf("a1 g1 e1 e5 g5 g8 a8 a7 a2 d2 b2 h2 h4 a4 c4 g4 g7 h7 b7 e7 e6 e4 e8 f8 f5 a5 h5 c5 c6 f6 a6 g6 h6 d6 d1 h1 c1 c8 c7 d7 f7 f1 f4 b4 d4 d5 d3 c3 e3 e2 f2 c2 g2 g3 h3 a3 f3 b3 b1 b5 b6 b8 d8 h8 \n");

}