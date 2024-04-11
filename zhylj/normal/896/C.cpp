#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, MOD = 1e9 + 7;

int n, m, seed, v_max;

int QPow(ll a, int b, int y) {
	a %= y;
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % y)
		if(b & 1) ret = 1LL * ret * bas % y;
	return ret % y;
}

int Rnd() {
	int ret = seed;
	seed = (seed * 7LL + 13) % MOD;
	return ret;
}

struct Node {
	int l, r;
	mutable ll v;
	Node(int _l, int _r, ll _v) : l(_l), r(_r), v(_v) { }
	bool operator <(const Node &x) const { return l < x.l; }
};
std::set <Node> odt;
auto Split(int x) {
	if(x > n) return odt.end();
	auto it = std::prev(odt.upper_bound((Node) { x, 0, 0 }));
	if(it -> l == x) return it;
	int l = it -> l, r = it -> r; ll v = it -> v;
	odt.erase(it);
	odt.insert((Node) { l, x - 1, v });
	return odt.insert((Node) { x, r, v }).fi;
}
auto Assign(int l, int r, int v) {
	auto it_r = Split(r + 1), it = Split(l);
	odt.erase(it, it_r);
	odt.insert((Node) { l, r, v });
	return odt;
}
void Add(int l, int r, int x) {
	auto it_r = Split(r + 1), it = Split(l);
	for(; it != it_r; ++it)
		it -> v += x;
}
ll FindKth(int l, int r, int k) {
	std::vector <std::pair <ll, int> > b;
	auto it_r = Split(r + 1), it = Split(l);
	for(; it != it_r; ++it)
		b.push_back(mkp(it -> v, it -> r - it -> l + 1));
	std::sort(b.begin(), b.end());
	ll ret = -1;
	for(auto i : b) {
		if(k > i.se) k -= i.se;
		else {
			ret = i.fi;
			break;
		}
	}
	return ret;
}
int GetPow(int l, int r, int x, int y) {
	int ret = 0;
	auto it_r = Split(r + 1), it = Split(l);
	for(; it != it_r; ++it)
		ret = (ret + 1LL * (it -> r - it -> l + 1) * QPow(it -> v, x, y)) % y;
	return ret;
}

int a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m, seed, v_max);
		for(int i = 1; i <= n; ++i) {
			a[i] = Rnd() % v_max + 1;
			odt.insert((Node) { i, i, a[i] });
		}
		for(int i = 1; i <= m; ++i) {
			int opt = Rnd() % 4 + 1,
				l = Rnd() % n + 1,
				r = Rnd() % n + 1,
				x, y;
			if(l > r) std::swap(l, r);
			if(opt == 3) x = Rnd() % (r - l + 1) + 1;
			else x = Rnd() % v_max + 1;
			if(opt == 4) y = Rnd() % v_max + 1;

			if(opt == 1) Add(l, r, x);
			if(opt == 2) Assign(l, r, x);
			if(opt == 3) printf("%lld\n", FindKth(l, r, x));
			if(opt == 4) printf("%d\n", GetPow(l, r, x, y));
		}
	} return 0;
}