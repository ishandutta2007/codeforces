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
#define div __div__ejJ46
#define exp __exP__QkL47
const int nax = 2e6 + 44, mod = 1e9 + 7;
int div[nax];
pair <int, int> exp[nax];
int primes[nax];
void add(int p, int e) {
	if (exp[p].first < e)
		exp[p] = make_pair(e, 1);
	else if (exp[p].first == e)
		exp[p].second++;
}
int main() {
	for (int p = 2; p < nax; ++p)
		if (div[p] == 0)
			for (int k = p; k < nax; k += p)
				div[k] = p;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", primes + i);
	sort(primes, primes + n, greater<int>());
	vector <int> used;
	for (int i = 0; i < n; ++i) {
		debug << arr(primes, i);
		if (exp[primes[i]].first == 0) {
			used.push_back(primes[i]);
			add(primes[i], 1);
		}
		else {
			int fac = primes[i] - 1;
			used.push_back(fac);
			while (fac > 1) {
				int p = div[fac];
				int e = 0;
				while (fac % p == 0) {
					fac /= p;
					e++;
				}
				add(p, e);
			}
		}
	}
	debug << imie(used);
	bool add = false;
	for (int x : used) {
		bool full = true;
		int xx = x;
		while (xx > 1) {
			int p = div[xx];
			int e = 0;
			while (xx % p == 0) {
				xx /= p;
				e++;
			}
			if (exp[p].first == e && exp[p].second < 2) {
				debug << imie(x) " failed on " arr(exp, p) imie(e);
				full = false;
			}
		}
		if (full) {
			debug << imie(x) << "is full";
			add = true;
		}
	}
	long long ans = 1;
	for (int i = 1; i < nax; ++i)
		for (int k = 0; k < exp[i].first; ++k)
			ans = ans * i % mod;
	if (add)
		ans++;
	ans %= mod;
	printf("%lld\n", ans);
}