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
const int nax = 3e5 + 44, mmax = 8;
int a[nax][mmax];
int seen[1 << mmax];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", a[i] + j);
	int low = 1, high = 1e9;
	pii ans = {0, 0};
	while (low <= high) {
		int med = (low + high) / 2;
		memset(seen, -1, sizeof(seen));
		for (int i = 0; i < n; ++i) {
			int curr = 0;
			for (int j = 0; j < m; ++j) if (a[i][j] >= med) curr |= (1 << j);
			seen[curr] = i;
		}
		for (int i = 0; i < m; ++i)
			for (int v = 0; v < (1 << m); ++v)
				if (seen[v] != -1) seen[v &~ (1 << i)] = seen[v];
		bool can = false;
		int all = (1 << m) - 1;
		for (int i = 0; i < (1 << m); ++i)
			if (seen[i] != -1 && seen[all - i] != -1) {
				can = true;
				ans = {seen[i], seen[all - i]};
			}
		if (can) {
			low = med + 1;
			debug << "can " imie(med);
		}
		else
			high = med - 1;
	}
	printf("%d %d\n", ans.first + 1, ans.second + 1);
}