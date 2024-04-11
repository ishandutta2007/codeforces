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
const int MN = 1 << 19, LOG = 19;
#define prev __prev__13B24E
#define next __next__77xq43
vector <int> tree[MN * 2];
int next[MN];
vector <pair <int, int> > queries[MN];
vector <int> occs[MN];
int ans[MN];
int a[MN];
pair <int, int> ranges[MN];
void put_r(int l, int r, int v, int wh = 1, int lb = 0, int rb = MN) {
	debug << imie(wh) imie(lb) imie(rb);
	if (l >= rb || r <= lb)
		return;
	if (l <= lb && r >= rb) {
		debug << "push_back " imie(l) imie(r) imie(lb) imie(rb) imie(wh) imie(v);
		tree[wh].push_back(v);
	}
	else {
		int s = (lb + rb) >> 1;
		put_r(l, r, v, wh << 1, lb, s);
		put_r(l, r, v, wh << 1 | 1, s, rb);
	}
}
int get(int x) {
	debug << imie(x);
	for (int i = LOG; i >= 0; --i) {
		int pos = (x + MN) >> i;
		while (!tree[pos].empty()) {
			int c = tree[pos].back();
			if (ranges[c].first <= x && ranges[c].second > x)
				return c;
			debug << imie(x) " erase " arr(ranges, c);
			tree[pos].pop_back();
		}
		pos /= 2;
	}
	return 0;
}
void put(int l, int r, int v) {
	debug << imie(l) imie(r) imie(v);
	ranges[v] = make_pair(l, r);
	put_r(l, r, v);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		occs[a[i]].push_back(i);
	}
	for (int i = 0; i < MN; ++i)
		occs[i].push_back(n + 1);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		queries[l].emplace_back(r, i);
	}
	for (int i = 0; i < MN; ++i)
		for (int j = 0; j < (int)occs[i].size() - 1; ++j) {
			next[occs[i][j]] = occs[i][j + 1];
		}
	for (int i = 0; i < MN; ++i) {
		if (occs[i].size() > 1u)
			put(occs[i][0], occs[i][1], i);
	}
	next[n + 1] = n + 1;
	for (int i = 1; i <= n; ++i) {
		for (auto q : queries[i]) {
			ans[q.second] = get(q.first);
			debug << range(a + i, a + q.first + 1) << arr(ans, q.second);
		}
		put(next[i], next[next[i]], a[i]);
	}
	for (int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}
}