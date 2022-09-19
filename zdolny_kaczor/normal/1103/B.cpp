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
int a;
map <pair <int, int>, bool> cache;
void reset() {
	cache.clear();
}
bool query(int x, int y) {
	assert(x <= 2e9 && y <= 2e9 && x >= 0 && y >= 0);
	if (cache.count(make_pair(x, y)))
		return cache[make_pair(x, y)];
#ifdef LOCAL
	return cache[make_pair(x, y)] = (x % a >= y % a);
#else
	printf("\? %d %d\n", x, y);
	fflush(stdout);
	char ans;
	scanf(" %c", &ans);
	if (ans == 'x')
		return cache[make_pair(x, y)] = true;
	if (ans == 'y')
		return cache[make_pair(x, y)] = false;
	assert(false);
#endif
}
void answer(int k) {
	#ifdef LOCAL
	assert(k == a);
	#else
	printf("! %d\n", k);
	fflush(stdout);
	#endif
}
void play() {
#ifdef LOCAL
	scanf("%d", &a);
#else
	char curr[20];
	scanf("%s", curr);
	if (strcmp(curr, "mistake") == 0)
		assert(false);
	if (strcmp(curr, "end") == 0)
		exit(0);
#endif
	int bound = 1;
	while (!query(bound / 2, bound))
		bound *= 2;
	debug << imie(bound);
	int l = bound / 2 + 1, r = bound;
	while (r != l) {
		int m = (l + r) / 2;
		debug << imie(l) imie(m) imie(r);
		if (query(m / 2, m)) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	assert(l == r);
	answer(l);
}
int main() {
	while (true) {
		reset();
		play();
	}
}