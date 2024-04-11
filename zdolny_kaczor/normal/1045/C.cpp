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
const int MN = 1e5 + 44;
const int LOG = 17;
int jump[MN][LOG];
vector <int> graf[MN];
int dep[MN];
int go(int x, int len) {
	for (int i = 0; i < LOG; ++i)
		if (len >> i & 1)
			x = jump[x][i];
	return x;
}
set <pair <int, int> > edges;
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
		edges.insert(make_pair(min(a, b), max(a, b)));
	}
	for (int i = 1; i <= n; ++i)
		dep[i] = 1e9;
	dep[1] = 0;
	queue <int> kol;
	kol.push(1);
	while (!kol.empty()) {
		int x = kol.front();
		kol.pop();
		for (int y : graf[x])
			if (dep[y] > dep[x] + 1) {
				dep[y] = dep[x] + 1;
				jump[y][0] = x;
				kol.push(y);
			}
	}
	jump[1][0] = 1;
	for (int i = 1; i < LOG; ++i)
		for (int v = 1; v <= n; ++v)
			jump[v][i] = jump[jump[v][i - 1]][i - 1];
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		int l = dep[a] + dep[b];
		if (dep[a] > dep[b])
			a = go(a, dep[a] - dep[b]);
		if (dep[a] < dep[b])
			b = go(b, dep[b] - dep[a]);
		assert(dep[a] == dep[b]);
		if (a == b)
			l -= 2 * dep[a];
		else {
			for (int i = LOG - 1; i >= 0; --i) {
				int aa = jump[a][i];
				int bb = jump[b][i];
				if (aa != bb) {
					a = aa;
					b = bb;
				}
			}
			l -= 2 * dep[a];
			if (edges.count(make_pair(min(a, b), max(a, b))))
				l++;
			else
				l += 2;
		}
		printf("%d\n", l);
	}

}