#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i,j};}
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
	sim, class b mor pair <b,c> r){ris << "(" << r.first << ", " << r.second << ")";}
#else
	sim mor const c&){ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug muu() << __FUNCTION__ << '#' << __LINE__ << ": "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define range(a, b) "[[ "#a ", " #b "): " << range(a, b) << "] "
using ll = long long;
using pii = pair <int, int>;
sim, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
sim> void mini(c &a, c b) {if (a > b) a = b;}
sim> void maxi(c &a, c b) {if (a < b) a = b;}
const int nax = 2100, mod = 1e9 + 7;
ll fac[nax], fin[nax];
ll powe(ll b, ll e) {
	ll r = 1;
	while (e) {
		if (e & 1) r = r * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return r;
}
ll cho(int a, int b) {
	return fac[a] * fin[b] % mod * fin[a - b] % mod;
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < nax; ++i) fac[i] = fac[i - 1] * i % mod;
	fin[nax - 1] = powe(fac[nax - 1], mod - 2);
	for (int i = nax - 2; i >= 0; --i) fin[i] = fin[i + 1] * (i + 1) % mod;
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%lld\n", cho(n + 2 * m - 1, 2 * m));
}