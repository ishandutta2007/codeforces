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
int med(int a, int b, int c) {
	int m = min(a, min(b, c));
	int M = max(a, max(b, c));
	return a ^ b ^ c ^ m ^ M;
}
vector <pair <int, int> > ans;
void go(int x1, int y1, int x2, int y2) {
	while (x1 != x2 || y1 != y2) {
		if (x1 > x2)
			x1--;
		else if (x1 < x2)
			x1++;
		else if (y1 > y2)
			y1--;
		else
			y1++;
		ans.emplace_back(x1, y1);
	}
}
int main() {
	int xa, xb, ya, yb, xc, yc;
	scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
	int xx = med(xa, xb, xc);
	int yy = med(ya, yb, yc);
	ans.emplace_back(xx, yy);
	go(xx, yy, xa, ya);
	go(xx, yy, xb, yb);
	go(xx, yy, xc, yc);
	printf("%d\n", (int)ans.size());
	for (auto a : ans)
		printf("%d %d\n", a.first, a.second);
}