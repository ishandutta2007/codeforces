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
vector <int> is[nax];
int n, m;
int missing(vector <int> &x) {
	int l = 1, r = n;
	while (x.size()) {
		debug << imie(l) imie(r) imie(x);
		int med = (l + r) / 2;
		int low = 0, high = 0;
		for (int y : x) {
			if (y <= med)
				low++;
			else
				high++;
		}
		if (low < (med - l + 1)) {
			for (int i = 0; i < (int)x.size(); ++i) {
				if (x[i] > med) {
					swap(x[i], x.back());
					x.pop_back();
					i--;
				}
			}
			r = med;
		}
		else {
			for (int i = 0; i < (int)x.size(); ++i) {
				if (x[i] <= med) {
					swap(x[i], x.back());
					x.pop_back();
					i--;
				}
			}
			l = med + 1;
		}
	}
	debug << imie(l) imie(r);
	return l;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		is[i].push_back(i);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		is[a].push_back(b);
		is[b].push_back(a);
	}
	pair <int, int> miss = {-1, -1};
	for (int i = 1; i <= n; ++i)
		if ((int)is[i].size() < n) {
			miss = {i, missing(is[i])};
			break;
		}
	if (miss.first == -1)
		return 0 * printf("NO\n");
	printf("YES\n");
	int p = 3;
	for (int i = 1; i <= n; ++i) {
		if (i == miss.first)
			printf("1 ");
		else if (i == miss.second)
			printf("2 ");
		else
			printf("%d ", p++);
	}
	printf("\n");
	p = 3;
	for (int i = 1; i <= n; ++i) {
		if (i == miss.first)
			printf("2 ");
		else if (i == miss.second)
			printf("2 ");
		else
			printf("%d ", p++);
	}
	printf("\n");
}