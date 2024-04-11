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
const int nax = 515;
pair <int, int> d[nax];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		d[i].second = i + 1;
		scanf("%d", &d[i].first);
	}
	sort(d, d + n, greater<pair<int,int> >());
	int last = -1;
	int out = 0;
	for (int i = 0; i < n - 2; ++i) {
		out += d[i].first;
		if (d[i].first == 1)
			break;
		if (out - 2 * i >= (n - i - 1))
			last = i;
	}
	if (last == -1)
		return 0*printf("NO\n");
	printf("YES %d\n%d\n", last + 2, n - 1);
	for (int i = 0; i < last; ++i) {
		d[i].first--;
		d[i + 1].first--;
		printf("%d %d\n", d[i].second, d[i + 1].second);
	}
	int free = 0;
	printf("%d %d\n", d[last].second, d[last + 1].second);
	d[last].first--;
	for (int i = last + 2; i < n; ++i) {
		debug << range(d, d + n);
		while (d[free].first == 0)
			free++;
		printf("%d %d\n", d[free].second, d[i].second);
		d[free].first--;
	}
}