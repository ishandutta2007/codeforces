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
const int nax = 2e3 + 44;
int match[nax];
bool taken[nax];
int p[nax];
using pii = pair <int, int>;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 2 * n; ++i)
		scanf("%d", p + i);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		match[a] = b;
		match[b] = a;
	}
	int t;
	scanf("%d", &t);
	int left = 2 * n;
	if (t == 1) {
		for (int i = 1; i <= 2 * n; ++i) {
			if (match[i] && p[i] >= p[match[i]] && !taken[i]) {
				printf("%d\n", i);
				fflush(stdout);
				int x;
				scanf("%d", &x);
				assert(x == match[i]);
				taken[x] = true;
				taken[i] = true;
				left -= 2;
			}
		}
		while (left > 0) {
			pii best(-1, -1);
			for (int i = 1; i <= 2 * n; ++i)
				if (!taken[i])
					best = max(best, pii(p[i], i));
			printf("%d\n", best.second);
			fflush(stdout);
			taken[best.second] = true;
			int x;
			scanf("%d", &x);
			taken[x] = true;
			left -= 2;
		}
	}
	else {
		while (left > 0) {
			debug << range(taken + 1, taken + n * 2 + 1);
			int x;
			scanf("%d", &x);
			taken[x] = true;
			int my = -1;
			if (match[x] && !taken[match[x]]) {
				debug << "forced " << imie(my);
				my = match[x];
			}
			else {
				int matched = -1;
				for (int i = 1; i <= 2 * n; ++i) {
					if (!taken[i] && match[i] && p[i] >= p[match[i]]) {
						matched = i;
						debug << imie(matched);
					}
				}
				if (matched != -1) {
					my = matched;
				}
				else {
					pii best(-1, -1);
					for (int i = 1; i <= 2 * n; ++i)
						if (!taken[i])
							best = max(best, pii(p[i], i));
					debug << imie(best);
					my = best.second;
				}
			}
			printf("%d\n", my);
			fflush(stdout);
			taken[my] = true;
			left -= 2;
		}
	}
}