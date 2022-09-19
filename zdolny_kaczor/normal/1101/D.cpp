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
sim> void mini(c &a, c b) { if (a > b) a = b; }
sim> void maxi(c &a, c b) { if (a < b) a = b; }
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int nax = 2e5 + 44;
vector <int> divs[nax];
vector <int> occs[nax];
vector <int> graf[nax];
bool active[nax];
int last_touched[nax];
int timer;
pair <int, int> dfs(int x, int y) {
	last_touched[x] = timer;
	pair <int, int> ans = {1, x};
	for (int v : graf[x])
		if (active[v] && v != y) {
			pair <int, int> to = dfs(v, x);
			maxi(ans, {to.first + 1, to.second});
		}
	return ans;
}
int diameter(int x) {
	return dfs(dfs(x, -1).second, -1).first;
}
bool prime[nax];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i < nax; ++i)
		for (int j = i; j < nax; j += i)
			divs[j].push_back(i);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		for (int x : divs[a])
			occs[x].push_back(i);
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int ans = 0;
	for (int d = 2; d < nax; ++d) {
		debug << arr(occs, d);
		timer = d;
		for (int c : occs[d])
			active[c] = true;
		for (int c : occs[d])
			if (last_touched[c] != timer)
				maxi(ans, diameter(c));
		for (int c : occs[d])
			active[c] = false;
	}
	printf("%d\n", ans);
}