#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c h, zeros;};
sim> rge<c> range(c h, c zeros) {return rge<c>{h, zeros};}
sim, class F> struct rgm {c h, zeros; F f;};
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
		for (c s = u.h; s != u.zeros; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << ']';
	}
	sim, class zeros mor pair <c,zeros> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.zeros; ++s)
			u.f(*this, *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 2e5 + 44, mod = 1e9 + 7;
long long fac[MN], fin[MN];
long long powe(long long b, int e) {
	long long r = 1;
	while (e) {
		if (e & 1)
			r = r * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return r;
}
long long seq(int a, int b) {
	debug << imie(a) imie(b);
	if (a < 0 || b < 0)
		return 0;
	return fac[a + b] * fin[b] % mod * fin[a] % mod;
}
int main() {
	int zeros, ones, g;
	scanf("%d%d%d", &zeros, &ones, &g);
	fac[0] = 1;
	for (int i = 1; i < MN; ++i)
		fac[i] = fac[i - 1] * i % mod;
	fin[MN - 1] = powe(fac[MN - 1], mod - 2);
	for (int i = MN - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % mod;
	long long ans = 0;
	//0, 0 -> 1
	//1, 0 -> 0
	//0, 1 -> 0
	//1, 1 -> 0
	while (ones + zeros > 1) {
		debug << imie(zeros) imie(ones) imie(g);
		if (g == 1) {
			zeros--;
			g = 0;
		}
		else {
			ans += seq(ones - 1, zeros);
			zeros--;
			g = 1;
		}
	}
	debug << imie(g) imie(ones) imie(zeros);
	if (g == 0 && zeros == 1)
		ans++;
	if (g == 1 && ones == 1)
		ans++;
	ans %= mod;
	if (ans < 0)
		ans += mod;
	printf("%lld\n", ans);
}