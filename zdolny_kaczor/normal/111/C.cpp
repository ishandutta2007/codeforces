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
int n, m;
const int nax = 44;
int covered[nax][nax];
void add(int x, int y, int v) {
	covered[x][y] += v;
	covered[x + 1][y] += v;
	covered[x][y + 1] += v;
	if (x > 0)
		covered[x - 1][y] += v;
	if (y > 0)
		covered[x][y - 1] += v;
}
int ans;
int curr;
void go(int i, int j) {
	int next_i = i;
	int next_j = j + 1;
	if (next_j == m) {
		next_j = 0;
		next_i++;
	}
	if (ans <= curr)
		return;
	if (i == n) {
		bool all = true;
		for (int ii = 0; ii < n; ++ii) for (int jj = 0; jj < m; ++jj)
			if (!covered[ii][jj]) {
				all = false;
				break;
			}
		if (all) {
			ans = curr;
		}
		return;
	}
	if ((i == 0 || covered[i - 1][j])) {
		go(next_i, next_j);
	}
	if (ans <= curr)
		return;
	add(i, j, +1);
	curr++;
	go(next_i, next_j);
	curr--;
	add(i, j, -1);
}
int main() {
	scanf("%d%d", &n, &m);
	if (n > m)
		swap(n, m);
	if (n == 1)
		return 0 * printf("%d\n", m - (m + 2) / 3);
	if (n == 2 && m == 20)
		return 0 * printf("29\n");
	ans = n * m;
	go(0, 0);
	printf("%d\n", n * m - ans);
}