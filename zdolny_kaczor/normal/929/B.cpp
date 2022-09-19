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
char row[100][20];
bool occ(char c) {
	return c == 'S' || c == 'P' || c == 'x';
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%s", row[i]);
	vector <pair <int, int> > nei[3];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 12; ++j)
			if (row[i][j] == '.')
				nei[(j > 0 && row[i][j - 1] == 'S') + (row[i][j + 1] == 'S')].emplace_back(i, j);
	for (int i = 0; i <= 2; ++i) {
		for (pair <int, int> x : nei[i]) {
			if (k > 0) {
				k--;
				row[x.first][x.second] = 'x';
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 11; ++j) {
			if (row[i][j] == 'S' && occ(row[i][j + 1]))
				ans++;
			if (row[i][j + 1] == 'S' && occ(row[i][j]))
				ans++;
		}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%s\n", row[i]);
}