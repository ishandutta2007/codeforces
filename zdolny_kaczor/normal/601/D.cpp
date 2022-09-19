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
using ull = unsigned long long;
const int MN = 3e5 + 44;
ull con[MN][26];
unordered_set <ull> hashes[MN];
ull bias[MN];
char chr[MN];
vector <int> graf[MN];
int c[MN];
int dep[MN];
void dfs(int x, int y, int d) {
	for (int v : graf[x])
		if (v != y)
			dfs(v, x, d + 1);
	pair <int, int> largest = make_pair(0, -1);
	for (int v : graf[x])
		if (v != y)
			largest = max(largest, make_pair((int)hashes[v].size(), v));
	if (largest.second != -1) {
		swap(hashes[x], hashes[largest.second]);
		bias[x] = bias[largest.second];
	}
	for (int v : graf[x])
		if (v != y && v != largest.second) {
			for (ull c : hashes[v])
				hashes[x].insert(c ^ bias[v] ^ bias[x]);
		}
	hashes[x].insert(bias[x]);
	bias[x] ^= con[d][chr[x] - 'a'];
	c[x] += hashes[x].size();
	debug << arr(hashes, x) arr(bias, x);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	scanf("%s", chr + 1);
	for (int i = 0; i < (n - 1); ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i = 0; i < MN; ++i)
		for (int k = 0; k < 26; ++k)
			con[i][k] = con[max(0, i - 1)][k] + rand() + ((ull)rand() << 16) + ((ull)rand() << 32) + ((ull)rand() << 48ll);
	dfs(1, 0, 0);
	int M = 0, cou = 0;
	for (int i = 1; i <= n; ++i)
		if (c[i] > M) {
			M = c[i];
			cou = 1;
		}
		else if (c[i] == M)
			cou++;
	printf("%d\n%d\n", M, cou);
}