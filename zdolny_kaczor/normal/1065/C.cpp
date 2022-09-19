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
	#else
	sim mor const c&) {ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 2e5 + 44;
int on[MN];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int m = 1e9;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		on[x]++;
		m = min(m, x);
	}
	for (int i = MN - 2; i >= 0; --i)
		on[i] += on[i + 1];
	int seen = 0, ans = 0;
	for (int i = MN - 1; i > m; --i) {
		if (seen + on[i] > k) {
			ans++;
			seen = 0;
		}
		seen += on[i];
	}
	if (seen > 0)
		ans++;
	printf("%d\n", ans);
}