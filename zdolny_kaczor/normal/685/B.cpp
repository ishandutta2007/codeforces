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
const int nax = 3e5 + 44;
vector <int> g[nax];
int s[nax];
int ans[nax];
int p[nax];
void dfs1(int x) {
	s[x] = 1;
	for (int y : g[x]) {
		dfs1(y);
		s[x] += s[y];
	}
	debug << arr(s, x);
}
void dfs2(int x) {
	pair <int, int> largest = {0, 0};
	for (int y : g[x]) {
		dfs2(y);
		largest = max(largest, {s[y], y});
	}
	if (largest.first <= s[x] / 2)
		ans[x] = x;
	else {
		int w = ans[largest.second];
		while (s[w] <= s[x] / 2)
			w = p[w];
		ans[x] = w;
	}
	debug << arr(ans, x);
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		g[x].push_back(i);
		p[i] = x;
	}
	dfs1(1);
	dfs2(1);
	debug << range(ans + 1, ans + n + 1);
	for (int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
#ifdef LOCAL
	for (int i = 1; i <= n; ++i) {
		if (!(s[i] - s[ans[i]] <= s[i] / 2))
			debug << "err on " imie(i) arr(s, ans[i]);
		for (int x : g[ans[i]]) {
			if (!(s[x] <= s[i] / 2))
				debug << "err on " << arr(s, x) imie(i);
		}
	}
#endif
}