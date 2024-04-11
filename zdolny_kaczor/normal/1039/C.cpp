# include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define dor > debug &operator<<
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug&>::type operator<<(c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud (c *x) -> decltype(cerr << *x, 0);
sim> char dud(...);
struct debug {
	#ifdef DEB
	~debug() {cerr << endl;}
	eni(==) ris << range(begin(i), end(i));}
	eni(!=) cerr << boolalpha << i; ris;}
	sim, class b dor(pair <b,c> r) {ris << "<" << r.first << ", " << r.second << ">";}
	sim dor (rge<c> x) {cerr << "{";
		for (c it = x.b; it != x.e; ++it)
			*this << ", " + 2 * (it == x.b) << *it;
		ris << "}";
	}
	#else
	sim dor (const c&) {ris;}
	#endif
};
#define imie(a...) "[" #a ": " << (a) << "] "
#define imask(a...) "[" #a ": " << bitset<8 * sizeof(a)>(a) << "] "
#define arr(a, i) "[" #a imie(i) " : " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) " : " << a[i][j] << "] "
#define debug debug() << "[" << __FUNCTION__ << "#"	<< __LINE__ << "] "
const int MN = 5e5 + 44;
int u[MN];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
vector <int> touched;
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	u[a] = b;
	touched.push_back(a);
}
long long c[MN];
const int mod = 1e9 + 7;
int powe(int b, int e) {
	int ans = 1;
	while (e > 0) {
		if (e & 1)
			ans = ans * 1ll * b % mod;
		b = b * 1ll * b % mod;
		e /= 2;
	}
	return ans;
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", c + i);
	for (int i = 0; i <= n; ++i)
		u[i] = i;
	unordered_map<long long, vector <pair <int, int> > > edges;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[c[a] ^ c[b]].emplace_back(a, b);
	}
	long long ans = ((1ll << k) - edges.size()) % mod * powe(2, n) % mod;
	for (auto &x : edges) {
		int comp = n;
		for (pair <int, int> e : x.second) {
			int a = e.first, b = e.second;
			if (find(a) != find(b)) {
				comp--;
				Union(a, b);
			}
		}
		for (int x : touched)
			u[x] = x;
		touched.clear();
		ans += powe(2, comp);
	}
	ans %= mod;
	if (ans < 0) ans += mod;
	printf("%lld\n", ans);
}