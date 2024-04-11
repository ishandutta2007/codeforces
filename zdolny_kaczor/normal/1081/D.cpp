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
const int nax = 1e5 + 44;
int u[nax];
int s[nax];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	s[a] += s[b];
	u[b] = a;
}
int size(int x) {
	return s[find(x)];
}
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		s[x] = 1;
	}
	for (int i = 1; i <= n; ++i)
		u[i] = i;
	vector <pair <int, pair <int, int> > > edges;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges.emplace_back(c, make_pair(a, b));
	}
	sort(edges.begin(), edges.end());
	for (auto x : edges) {
		Union(x.second.first, x.second.second);
		if (size(x.second.first) == k) {
			for (int i = 0; i < k; ++i)
				printf("%d ", x.first);
			printf("\n");
			exit(0);
		}
	}
}