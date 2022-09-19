#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define en1(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	en1(<) a << boolalpha << g; ris;}
	en1(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << '[';
		for (c s = u.b; s != u.e; ++s)
			*this << ", " + 2 * (s == u.b) << *s;
		ris << ']';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c&) {ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 2e5 + 44, LOG = 30;
int in[MN];
#define next __next_U3qEU4
int next[MN][LOG];
int a[MN];
long long ans = 0;
int n;
vector <pair <int, pair <int, int> > > edges;
void join(int i, int j) {
	edges.emplace_back(a[i] ^ a[j], make_pair(i, j));
}
void closest(int i, int l, int r, int b) {
	while (b >= 0) {
		debug << range(a + l, a + r) << " " imie(b) arr(a, i);
		int s = min(r, next[l][b]);
		if (s != l && s != r) {
			if (a[i] >> b & 1)
				l = s;
			else
				r = s;
		}
		b--;
	}
	if (l != r)
		join(i, l);
}
void gen(int i) {
	int l = 0, r = n;
	int b = LOG - 1;
	while (b >= 0) {
		int s = min(r, next[l][b]);
		debug << imie(l) imie(r) imie(b) imie(s);
		if (s != l && s != r) {
			if (a[i] >> b & 1) {
				closest(i, l, s, b - 1);
				l = s;
			}
			else {
				closest(i, s, r, b - 1);
				r = s;
			}
		}
		b--;
	}
}
int u[MN];
int find(int x) {
	if (u[x] == x)
		return x;
	return u[x] = find(u[x]);
}
void uni0n(int x, int y) {
	u[find(x)] = find(y);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (int b = 0; b < LOG; ++b) {
		next[n][b] = n;
		for (int i = n - 1; i >= 0; --i)
			if (a[i] >> b & 1)
				next[i][b] = i;
			else
				next[i][b] = next[i + 1][b];
	}
	for (int i = 0; i < n; ++i)
		gen(i);
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; ++i)
		u[i] = i;
	long long ans = 0;
	for (auto x : edges) {
		if (find(x.second.first) != find(x.second.second)) {
			ans += x.first;
			uni0n(x.second.first, x.second.second);
		}
	}
	debug << imie(edges);
	printf("%lld\n", ans);
}