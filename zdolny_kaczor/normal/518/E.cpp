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
bool unk[nax];
char curr[20];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", curr);
		if (*curr == '\?')
			unk[i] = true;
		else
			a[i] = atoi(curr);
	}
	for (int i = 0; i < k; ++i)
		a[n + i] = 1e9 + nax;
	for (int s = 0; s < k; ++s) {
		int last = -1, val = -(1e9 + nax);
		for (int i = 0; i * k + s < n + k; ++i) {
			if (!unk[i * k + s]) {
				int start = -(i - last - 1) / 2;
				int shift = 0;
				debug << imie(start);
				if (start < val + 1) {
					start = val + 1;
					debug << "shift start to " << imie(start);
					shift++;
				}
				if (start > a[i * k + s] + last + 1 - i) {
					start = a[i * k + s] + last + 1 - i;
					debug << "shift start to " << imie(start);
					shift++;
				}
				if (start < val + 1) {
					start = val + 1;
					debug << "shift start to " << imie(start);
					shift++;
				}
				if (shift >= 2)
					return 0 * printf("Incorrect sequence\n");
				for (int j = last + 1; j < i; ++j)
					a[j * k + s] = start++;
				last = i;
				val = a[i * k + s];
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}