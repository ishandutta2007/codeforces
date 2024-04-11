# include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define dor > debug & operator<<
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug&>::type operator<<(c h) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct debug {
#ifdef LOCAL
	stringstream o;
	~debug() {cerr << o.str() << endl;}
	eni(!=) o << boolalpha << h; ris;}
	eni(==) ris << range(begin(h), end(h));}
	sim dor (rge<c> u) {
		o << '[';
		for (c a = u.h; a!= u.n; ++a)
			*this << ", " + 2 * (a == u.h) << *a;
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
map <pair <int, int>, int> ile;
const int MN = 1e5 + 44;
int after[MN];
int u[MN];
int siz[MN];
int find(int x) {
	if (u[x] == x)
		return x;
	return u[x] = find(u[x]);
}
void uni0n(int x, int y) {
	x = find(x);
	y = find(y);
	assert(x != y);
	u[x] = y;
	siz[y] += siz[x];
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		u[i] = i;
		siz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int pop;
		scanf("%d", &pop);
		for (int j = 0; j < n - 1; ++j) {
			int curr;
			scanf("%d", &curr);
			ile[make_pair(pop, curr)]++;
			pop = curr;
		}
	}
	for (auto x : ile)
		if (x.second == m)
			uni0n(x.first.first, x.first.second);
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		if (u[i] == i)
			ans += siz[i] * (siz[i] + 1ll) / 2;
	printf("%lld\n", ans);
}