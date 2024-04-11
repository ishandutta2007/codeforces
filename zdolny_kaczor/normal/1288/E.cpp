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
const int nax = 3e5 + 44;
int last[nax];
struct my_cmp {
	bool operator()(int a, int b) const {
		return last[a] > last[b];
	}
};
ordered_set<int, my_cmp> all;
pii ans[nax];
void inc(int x, int p) {
	mini(ans[x].first, p);
	maxi(ans[x].second, p);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		ans[i] = {i, i};
		last[i] = -i;
		all.insert(i);
	}
	debug << imie(all);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		int p = all.order_of_key(x) + 1;
		inc(x, p);
		inc(x, 1);
		all.erase(x);
		last[x] = i;
		all.insert(x);
		debug << imie(all);
	}
	int p = 1;
	for (int x : all) inc(x, p++);
	for (int i = 1; i <= n; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
}