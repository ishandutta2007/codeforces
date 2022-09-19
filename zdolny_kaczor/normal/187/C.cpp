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
int u[MN];
int find(int x) {
	if (u[x] == x)
		return x;
	return u[x] = find(u[x]);
}
void uni0n(int a, int b) {
	u[find(a)] = find(b);
}
vector <int> graf[MN];
pair <int, int> dist[MN];
vector <pair <int, pair <int, int> > > edges;
int main() {
	int n, m, k;
	queue <int> kol;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		dist[i] = make_pair((int)1e9, -1);
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		dist[x] = make_pair(0, x);
		kol.push(x);
	}
	for (int i = 0; i <= n; ++i)
		u[i] = i;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	dist[t] = make_pair(0, t);
	kol.push(t);
	while (!kol.empty()) {
		int c = kol.front();
		debug << arr(dist, c);
		kol.pop();
		for (int x : graf[c]) {
			if (dist[x].first > dist[c].first + 1) {
				dist[x] = make_pair(dist[c].first + 1, dist[c].second);
				kol.push(x);
			}
			else
				edges.emplace_back(dist[c].first + dist[x].first + 1, make_pair(dist[x].second, dist[c].second));
		}
	}
	sort(edges.begin(), edges.end());
	debug << imie(edges);
	for (auto x : edges) {
		uni0n(x.second.first, x.second.second);
		if (find(s) == find(t)) {
			printf("%d\n", x.first);
			return 0;
		}
	}
	printf("-1\n");
}