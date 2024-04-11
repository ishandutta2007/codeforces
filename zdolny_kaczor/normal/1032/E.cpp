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
const int nax = 101;
using ll = long long;
const ll mod = 2019;//588518285577289787ll;
ll ways[nax][nax * nax];
int cou[nax];
void add(ll &a, ll b) {
	a += b;
	if (a > mod)
		a -= mod;
}
ll binom[nax][nax];
int main() {
	int diff = 0;
	for (int i = 0; i < nax; ++i)
		binom[i][i] = binom[i][0] = 1;
	for (int i = 1; i < nax; ++i)
		for (int j = 1; j < i; ++j)
			binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		cou[x]++;
	}
	for (int i = 0; i < nax; ++i)
		if (cou[i])
			diff++;
	ways[0][0] = 1;
	int seen_so_far = 0, sum_so_far = 0;
	for (int i = 1; i < nax; ++i) {
		for (int l = 0; l < cou[i]; ++l) {
			for (int c = seen_so_far; c >= 0; --c)
				for (int s = 0; s <= sum_so_far; ++s)
					add(ways[c + 1][s + i], ways[c][s]);
			seen_so_far++;
			sum_so_far += i;
		}
	}
	#ifdef LOCAL
	for (int i = 0; i < nax; ++i)
		for (int j = 0; j < nax * nax; ++j)
			if (ways[i][j])
				debug << arr2(ways, i, j);
	#endif
	int ans = 1;
	bool whole = false;
	for (int i = 1; i < nax; ++i) {
		for (int l = ans + 1; l <= cou[i]; ++l) {
			debug << imie(i) imie(l) arr2(ways, l, i * l) arr2(binom, cou[i], l);
			if (ways[l][i * l] == binom[cou[i]][l]) {
				debug << "match";
				ans = l;
				if (l == cou[i])
					whole = true;
			}
		}
	}
	if (whole && diff <= 2)
		ans = n;
	printf("%d\n", ans);
}