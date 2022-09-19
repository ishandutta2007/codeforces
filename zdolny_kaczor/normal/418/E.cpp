#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return {i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
~muu() {cerr << a.str() << endl;}
stringstream a;
R22(<) a << boolalpha << g; ris;}
R22(==) ris << range(begin(g), end(g));}
sim mor rge<c>u ) {
	a << "[";
	for (c i = u.b; i != u.e; ++i)
		*this << ", " + 2 * (i == u.b) << *i;
	ris << "]";
}
sim, class b mor pair <b,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
template <class...c mor tuple<c...> r) {
	a << "(";
	int q = 0;
	apply([&](c...y){
		((*this << ", " + 2 * !q++ << y), ...);
	}, r);
	ris << ")";
}
#define qel(t) sim, class d, class ...e mor t<c,d,e...> r) {ris << *(d*)&r;}
qel(stack) qel(queue) qel(priority_queue)
#else
	sim mor const c&){ris;}
#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) ": " << a[i][j] << "] "
#define imask(r...) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define fun(f, x...) "[" #f << make_tuple(x) << ": " f(x) << "] "
using vi = vector <int>; using pii = pair <int, int>; using ld = long double;
using ll = long long; using ull = unsigned long long; using unt = unsigned int;
using vpii = vector <pii>; using vll = vector <ll>; 
sim> void mini(c &a, const c&b) { if (a > b) a = b; }
sim> void maxi(c &a, const c&b) { if (a < b) a = b; }
sim> using ordered_set = tree<c, null_type, less<c>, rb_tree_tag, tree_order_statistics_node_update>;
map <int, ordered_set<int> > first;
set<int> large;
const int nax = 1e5 + 44, root =
#ifdef LOCAL
3;
#else
40;
#endif
ordered_set<int> second[nax];
int a[nax];
void put(int p, int v) {
	// debug imie(p) imie(v) arr(first, v);
	a[p] = v;
	auto &firstv = first[v];
	auto [it, added] = firstv.insert(p);
	assert(added);
	if (!large.count(v)) {
		if ((int)firstv.size() == root) {
			// debug imie(second);
			int i = 0;
			for (int x : firstv) {
				if (x == p) continue;
				i++;
				// debug arr(second, i) imie(x);
				auto was = second[i].erase(x);
				assert(was);
			}
			large.insert(v);
		}
		else {
			int now = firstv.order_of_key(p) + 1;
			second[now].insert(p);
			it++;
			now++;
			for (auto ii = it; ii != firstv.end(); ++ii, ++now) {
				second[now - 1].erase(*ii);
				second[now].insert(*ii);
			}
		}
	}
}
void rem(int p, int v) {
	// debug imie(p) arr(first, v);
	assert(a[p] == v);
	auto &firstv = first[v];
	bool was = firstv.erase(p);
	assert(was);
	if (!large.count(v)) {
		auto it = firstv.lower_bound(p);
		int now = firstv.order_of_key(p) + 1;
		second[now].erase(p);
		now++;
		for (auto ii = it; ii != firstv.end(); ++ii, ++now) {
			// debug "move" imie(*ii) "from " imie(now) "to " imie(now - 1);
			second[now - 1].insert(*ii);
			second[now].erase(*ii);
		}
	}
}
int get_first(int p) {
	return a[p];
}
int get_second(int p) {
	return first[a[p]].order_of_key(p) + 1;
}
int get_third(int p) {
	int prev = get_second(p);
	int ans = second[prev].order_of_key(p) + 1;
	// debug "pre" imie(ans) imie(prev);
	for (int x : large) {
		if ((int)first[x].order_of_key(p) >= prev) {
			ans++;
			// debug "inc at " arr(first, x);
		}
	}
	return ans;
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		put(i, x);
	}
	scanf("%d", &m);
	for (int _ = 0; _ < m; ++_) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			rem(y, a[y]);
			put(y, x);
		}
		else {
			int ans;
			if (x == 1) ans = get_first(y);
			else if (x % 2) ans = get_third(y);
			else ans = get_second(y);
			printf("%d\n", ans);
		}
		// debug imie(first) imie(second) imie(large);
	}
}