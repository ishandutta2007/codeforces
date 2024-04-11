# include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define dor > debug & operator<<
#define ris return *this
#define en1(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug&>::type operator<<(c h) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct debug {
#ifdef LOCAL
	stringstream o;
	~debug() {cerr << o.str() << endl;}
	en1(!=) o << boolalpha << h; ris;}
	en1(==) ris << range(begin(h), end(h));}
	sim dor (rge<c> u) {
		o << '[';
		for (c a = u.b; a!= u.e; ++a)
			*this << ", " + 2 * (a == u.b) << *a;
		ris << ']';
	}
	sim, class b dor (pair <b,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim dor (const c&) {ris;}
	#endif
};
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
#ifdef LOCAL
const int MN = 1 << 3;
#else
const int MN = 1 << 18;
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define tree __tree__12uEq
ordered_set<int> tree[MN * 2];
void add(int x, int pos) {
	pos += MN;
	while (pos > 0) {
		tree[pos].insert(x);
		pos /= 2;
	}
}
void rem(int x, int pos) {
	pos += MN;
	while (pos > 0) {
		tree[pos].erase(x);
		pos /= 2;
	}
}
int in_range(int l, int r, int low, int high, int wh = 1, int lb = 0, int rb = MN) {
	debug << imie(l) imie(r) imie(lb) imie(rb) arr(tree, wh);
	if (l >= rb || r <= lb) {
		debug << "out";
		return 0;
	}
	if (l <= lb && r >= rb) {
		debug << "whole";
		return tree[wh].order_of_key(high) - tree[wh].order_of_key(low);
	}
	int s = (lb + rb) >> 1;
	debug << "split " << imie(s);
	return in_range(l, r, low, high, wh << 1, lb, s) + in_range(l, r, low, high, wh << 1 | 1, s, rb);
}
int a[MN];
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
		add(i, i);
	}
	long long invs = 0;
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (l > r)
			swap(l, r);
		if (l != r) {
			if (a[l] < a[r])
				invs++;
			else
				invs--;
			rem(a[l], l);
			rem(a[r], r);
			invs += 2 * in_range(l, r, a[l], a[r]);
			add(a[l], r);
			add(a[r], l);
			swap(a[r], a[l]);
			debug << range(a + 1, a + n + 1);
		}
		printf("%lld\n", invs);
	}
}