#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )
sim> void mini(c &a, c b) { if (a > b) a = b;}
void solve() {
	int k;
	int a[7];
	scanf("%d", &k);
	for (int i = 0; i < 7; ++i)
		scanf("%d", a + i);
	int ile = 0;
	for (int i = 0; i < 7; ++i) ile += a[i];
	int rest = k % ile;
	if (rest == 0) rest += ile;
	int ans = 7 * ((k - rest) / ile);
	int longest = 1e9;
	for (int i = 0; i < 7; ++i) {
		int seen = 0;
		int curr = 0;
		for (int p = i; seen < rest; p = (p + 1) % 7) {
			seen += a[p];
			curr++;
		}
		mini(longest, curr);
	}
	ans += longest;
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}