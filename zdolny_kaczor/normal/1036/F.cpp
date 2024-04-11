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
		a << '[';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << ']';
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
vector <long long> powers;
vector <long long> cubes;
vector <long long> all;
bool is_square(long long x) {
	long long r = sqrt((long double)x);
	for (long long i = r - 3; i <= r + 3; ++i)
		if (i * i == x) return true;
	return false;
}
bool is_cube(long long x) {
	long long r = cbrt(x);
	for (long long i = r - 3; i <= r + 3; ++i)
		if (i * i * i == x) return true;
	return false;
}
const int nax = 70;
bool primes[nax];
const long long b = 1e18;
int squares(long long a) {
	long long r = sqrt(a);
	while (r * r > a)
		r--;
	while ((r + 1) * (r + 1) <= a)
		r++;
	debug << imie(a) imie(r);
	return r;
}
int main() {
	for (int i = 2; i < nax; ++i)
		primes[i] = true;
	for (int i = 2; i < nax; ++i)
		if (primes[i])
			for (int k = i * i; k < nax; k += i)
				primes[k] = false;
	for (int i = 2; i <= 1000 * 1000; ++i) {
		if (is_square(i)) continue;
		long long p = i;
		int e = 1;
		while (true) {
			if (primes[e]) {
				if (e == 3)
					cubes.push_back(p);
				else if (e > 3)
					powers.push_back(p);
			}
			e++;
			if (b / i < p)
				break;
			p *= i;
		}
	}
	sort(powers.begin(), powers.end());
	powers.resize(unique(powers.begin(), powers.end()) - powers.begin());
	int pos = 0;
	for (long long x : cubes) {
		while (pos < (int) powers.size() && powers[pos] < x)
			all.push_back(powers[pos++]);
		all.push_back(x);
		while (pos < (int) powers.size() && powers[pos] == x)
			pos++;
	}
	while (pos < (int) powers.size())
		all.push_back(powers[pos++]);
	debug << range(all.begin(), all.begin() + 500);
	int t;
	scanf("%d", &t);
	while (t--) {
		long long x;
		scanf("%lld", &x);
		long long ans = x - squares(x) - (upper_bound(all.begin(), all.end(), x) - all.begin());
		//debug << imie(x) << range(all.begin(), upper_bound(all.begin(), all.end(), x));
		printf("%lld\n", ans);
	}
}