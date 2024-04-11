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
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int nax = 1 << 18, kax = 5;
struct node {
	int greatest[1 << kax];
};
int n, k;
muu & operator<<(muu &d, const node &no) {
	return d << range(no.greatest, no.greatest + (1 << k));
}
node tree[nax * 2];
sim> void maxi(c &x, c y) {
	if (x < y) x = y;
}
void init(node &a, int x[]) {
	memset(a.greatest, 0, sizeof(a.greatest));
	for (int m = 0; m < (1 << kax); ++m)
		for (int i = 0; i < kax; ++i)
			if (m >> i & 1)
				a.greatest[m] += x[i];
			else
				a.greatest[m] -= x[i];
}
void move_to(node &a, const node &b, const node &c) {
	for (int i = 0; i < (1 << kax); ++i)
		a.greatest[i] = max(b.greatest[i], c.greatest[i]);
}
int diameter(const node &a) {
	int ans = 0;
	debug << imie(a);
	for (int i = 0; i < (1 << kax); ++i)
		maxi(ans, a.greatest[i] + a.greatest[((1 << kax) - 1) ^ i]);
	return ans;
}
void inc(node &a, const node &b) {
	debug << imie(b);
	for (int i = 0; i < (1 << kax); ++i)
		maxi(a.greatest[i], b.greatest[i]);
}
node res;
void rec(int l, int r, int wh = 1, int lb = 0, int rb = (nax - 1)) {
	if (l > rb || r < lb)
		return;
	if (l <= lb && r >= rb) {
		debug << imie(lb) imie(rb) arr(tree, wh);
		inc(res, tree[wh]);
		return;
	}
	int s = (lb + rb) >> 1;
	rec(l, r, wh << 1, lb, s);
	rec(l, r, wh << 1 | 1, s + 1, rb);
}
int read(int l, int r) {
	debug << imie(l) imie(r);
	for (int i = 0; i < (1 << kax); ++i)
		res.greatest[i] = -1e9;
	rec(l, r);
	return diameter(res);
}
int x[kax];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k; ++j)
			scanf("%d", x + j);
		init(tree[i + nax], x);
	}
	for (int i = nax - 1; i; --i)
		move_to(tree[i], tree[i << 1], tree[i << 1 | 1]);
	int q;
	scanf("%d", &q);
	for (int _ = 0; _ < q; ++_) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int i;
			scanf("%d", &i);
			for (int j = 0; j < k; ++j)
				scanf("%d", x + j);
			init(tree[i + nax], x);
			int p = (i + nax) / 2;
			while (p) {
				move_to(tree[p], tree[p << 1], tree[p << 1 | 1]);
				p >>= 1;
			}
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", read(l, r));
		}
	}
}