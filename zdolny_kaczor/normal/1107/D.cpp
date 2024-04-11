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
const int nax = 5212;
bool A[nax][nax];
char in[nax];
int c[128];
int dp[nax][nax];
int main() {
	for (int i = 0; i < 10; ++i)
		c['0' + i] = i;
	for (int i = 0; i < 6; ++i)
		c['A' + i] = i + 10;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", in);
		for (int j = 0; j < n / 4; ++j)
			for (int k = 0; k < 4; ++k)
				A[i][j * 4 + k] = (c[in[j]] >> (3 - k)) & 1;
		debug << range(A[i], A[i] + n);
	}
	for (int i = 0; i < n; ++i)
		dp[i][n - 1] = dp[n - 1][i] = 1;
	for (int i = n - 2; i >= 0; --i)
		for (int j = n - 2; j >= 0; --j) {
			if (A[i][j] == A[i + 1][j] && A[i][j] == A[i][j + 1]) {
				int l = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = l;
				if (A[i][j] == A[i + l][j + l])
					dp[i][j]++;
			}
			else
				dp[i][j] = 1;
			debug << arr2(dp, i, j);
		}
	for (int x = n; x >= 2; --x)
		if (n % x == 0) {
			bool valid = true;
			for (int i = 0; i < n; i += x)
				for (int j = 0; j < n; j += x)
					if (dp[i][j] < x)
						valid = false;
			if (valid) {
				printf("%d\n", x);
				return 0;
			}
		}
	printf("1\n");
}