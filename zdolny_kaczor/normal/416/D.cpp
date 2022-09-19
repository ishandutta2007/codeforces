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
const int nax = 2e5 + 44;
int a[nax];
#define ran(i, j) "[" << i << ", " << j << ") = " << range(a + i, a + j) << ""
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int ans = 0, pos = 0;
	while (pos < n) {
		ans++;
		int first = -1, second = -1, i = pos;
		while (i < n && second == -1) {
			if (a[i] != -1) {
				if (first == -1)
					first = i;
				else {
					second = i;
				}
			}
			i++;
		}
		debug << imie(pos) imie(first) imie(second);
		if (second == -1) {
			debug << "cover suffix" << ran(pos, n) << " with constant sequence";
			pos = n;
		}
		else if ((a[second] - a[first]) % (second - first)) {
			debug << "cover range " << ran(pos, second) << " with constant sequence due to not matching " arr(a, second);
			pos = second;
		}
		else {
			long long k = (a[second] - a[first]) / (second - first);
			long long l = a[first] - k * 1ll * first;
			assert(k * first + l == a[first]);
			assert(k * second + l == a[second]);
			bool any = false;
			while (pos < n) {
				if (pos * k + l > 0 && (a[pos] == -1 || a[pos] == pos * k + l)) {
					debug << arr(a, pos) " matches arithmetic sequence";
					pos++;
					any = true;
				}
				else
					break;
			}
			if (!any) {
				debug << "no match, so cover " << ran(pos, second) << " with constant sequenuce";
				pos = second;
			}
		}
	}
	printf("%d\n", ans);
}