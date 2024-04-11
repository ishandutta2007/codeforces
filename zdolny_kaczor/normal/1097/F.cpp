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
#ifdef LOCAL
const int vax = 10;
#else
const int vax = 7e3 + 3;
#endif
const int nax = 1e5 + 44, qax = 1e6 + 44;
bitset<vax> sets[nax];
bitset<vax> divs[vax];
bitset<vax> over[vax];
bool sq_non_free[vax];
int ans[qax];
int main() {
	for (int i = 2; i * i < vax; ++i)
		for (int k = i * i; k < vax; k += i * i)
			sq_non_free[k] = true;
	for (int i = 1; i < vax; ++i)
		for (int k = i; k < vax; k += i)
			if (!sq_non_free[k / i])
				over[i][k] = true;
	for (int i = 1; i < vax; ++i)
		for (int j = i; j < vax; j += i)
			divs[j][i] = true;
	int q;
	scanf("%*d%d", &q);
	int anses = 0;
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int x, v;
			scanf("%d%d", &x, &v);
			sets[x] = divs[v];
			debug << "set " imie(x) imie(v) arr(sets, x);
		}
		else if (t == 2) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			sets[x] = sets[y] ^ sets[z];
			debug << "union " imie(x) imie(y) imie(z) arr(sets, x);
		}
		else if (t == 3) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			sets[x] = sets[y] & sets[z];
			debug << "product " imie(x) imie(y) imie(z) arr(sets, x);
		}
		else if (t == 4) {
			int x, v;
			scanf("%d%d", &x, &v);
			debug << arr(sets, x) arr(over, v);
			ans[anses++] = (over[v] & sets[x]).count() % 2;
		}
	}
	for (int i = 0; i < anses; ++i)
		printf("%d", ans[i]);
	printf("\n");
}