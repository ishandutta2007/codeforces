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
const int nax = 1555;
int per[nax];
int n, k;
int queries = 0;
bool query(int a, int b, int c) {
	queries++;
	assert(queries <= 70 * n + 10);
#ifdef LOCAL
	int a1 = per[a], b1 = per[b], c1 = per[c];
	while (a1 != c1) {
		if (a1 == b1 || b1 == c1)
			return true;
		if (a1 > c1)
			a1 = (a1 - 1) / k;
		else
			c1 = (c1 - 1) / k;
	}
	return false;
#else
	printf("\? %d %d %d\n", a, b, c);
	fflush(stdout);
	static char ans[5];
	scanf("%s", ans);
	return strlen(ans) == 3;
#endif
}
void answer(int x) {
	debug << imie(queries);
#ifdef LOCAL
	assert(per[x] == 0);
#else
	printf("! %d\n", x);
#endif
	exit(0);
}
int powers[nax];
int main() {
	scanf("%d%d", &n, &k);
#ifdef LOCAL
	for (int i = 1; i <= n; ++i)
		per[i] = i - 1;
	random_shuffle(per + 1, per + n + 1);
#endif
	int dep = 0;
	powers[0] = 1;
	int so_far = 1;
	for (int i = 1; i < nax; ++i) {
		powers[i] = powers[i - 1] * k;
		so_far += powers[i];
		if (so_far == n) {
			dep = i;
			break;
		}
		else if (so_far > n)
			assert(false);
	}
	debug << imie(dep);
	while (true) {
		int a = 1 + rand() % n, b = 1 + rand() % n;
		if (a == b) continue;
		vector <int> on;
		for (int i = 1; i <= n; ++i)
			if (a != i && b != i && query(a, i, b))
				on.push_back(i);
		debug << imie(a) imie(b) imie(on);
		if ((int)on.size() == 2 * dep - 1) {
			sort(on.begin(), on.end(), [&](int x, int y) {
				return x != y && query(a, x, y);
			});
			answer(on[dep - 1]);
		}
	}
}