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
			u.f(*this, *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 1555;
int dp[MN][MN];
int a[MN];
int ran[MN];
int n, s, k, m;
sim> void mini(c &x, c y) {
	if (x > y) x = y;
}
sim> void maxi(c &x, c y) {
	if (x < y) x = y;
}
bool test(int bound) {
	for (int i = 2; i <= n + 1; ++i) {
		for (int j = 0; j <= m; ++j)
			dp[i][j] = dp[i - 1][j];
		if (ran[i] < i) {
			int cou = 0;
			for (int k = ran[i]; k < i; ++k)
				if (a[k] <= bound)
					cou++;
			for (int j = 0; j < m; ++j)
				maxi(dp[i][j + 1], dp[ran[i]][j] + cou);
		}
	}
	return dp[n + 1][m] >= k;
}
int main() {
	scanf("%d%d%d%d", &n, &s, &m, &k);
	for (int i = 0; i < MN; ++i)
		ran[i] = MN;
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < s; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		ran[r + 1] = min(ran[r + 1], l);
	}
	for (int i = n; i >= 1; --i)
		mini(ran[i], ran[i + 1]);
	vector <int> seen;
	for (int i = 1; i <= n; ++i)
		seen.push_back(a[i]);
	sort(seen.begin(), seen.end());
	seen.resize(unique(seen.begin(), seen.end()) - seen.begin());
	int ans = 1e9 + 44;
	bool any = false;
	int l = 0, r = seen.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (test(seen[m])) {
			ans = seen[m];
			r = m - 1;
			any = true;
		}
		else
			l = m + 1;
	}
	if (any)
		printf("%d\n", ans);
	else
		printf("-1\n");
}