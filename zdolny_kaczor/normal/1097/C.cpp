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
const int nax = 5e5 + 44;
char in[nax];
map <int, int> cou;
int main() {
	int n;
	scanf("%d", &n);
	for (int _ = 0; _ < n; ++_) {
		scanf("%s", in);
		bool fit = false;
		int del = 0;
		int l = strlen(in);
		int bil = 0;
		for (int j = 0; j < l; ++j) {
			if (in[j] == '(')
				bil++;
			else
				bil--;
			if (bil < 0)
				break;
		}
		if (bil >= 0) {
			fit = true;
			del = bil;
		}
		else {
			bil = 0;
			for (int j = l - 1; j >= 0; --j) {
				if (in[j] == ')')
					bil++;
				else
					bil--;
				if (bil < 0)
					break;
			}
			if (bil >= 0) {
				fit = true;
				del = -bil;
			}
		}
		if (fit) {
			debug << imie(in) imie(del);
			cou[del]++;
		}
	}
	debug << imie(cou);
	int a = 0;
	for (auto & x : cou) {
		if (x.first < 0)
			continue;
		if (x.first) {
			if (cou.count(-x.first))
				a += min(cou[-x.first], x.second);
		}
		else
			a += x.second / 2;
	}
	printf("%d\n", a);
}