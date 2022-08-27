#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 200054;

struct card {
	int u, v; bool fl;
	inline bool operator < (const card &B) const {return u < B.u;}
} a[N];

int n;
int b[N], ib[N];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

struct BIT {
	int n; ll x[N], G;
	void init(int n_) {n = n_, memset(x, 63, (n + 1) << 3), G = 0;}
	ll min(int h) {ll s = INT_MAX; for (; h >= 0; h &= h + 1, --h) down(s, x[h]); return s + G;}
	inline void add(ll v) {G += v;}
	void update(int h, ll v) {for (v -= G; h <= n; h |= h + 1) down(x[h], v);}
} f, g;

int main() {
	int i, cost_f, cost_g; ll cross_f, cross_g, ans;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i].u >> a[i].v;
		if ((a[i].fl = a[i].u > a[i].v))
			std::swap(a[i].u, a[i].v);
	}
	std::sort(a, a + n);
	for (i = 0; i < n && a[i].u == i + 1; ++i);
	if (i != n) return cout << "-1\n", 0;
	for (i = 0; i < n; ++i) b[i + 1] = 2 * n - a[i].v + 1;
	f.init(n), g.init(n), f.update(0, 0), g.update(0, 0);
	for (i = 1; i <= n; ++i) {
		//fprintf(stderr, "%d => %d\n", i, b[i]);
		cost_f = a[i - 1].fl, cost_g = !cost_f;
		cross_f = g.min(b[i]) + cost_f;
		cross_g = f.min(b[i]) + cost_g;
		if (b[i - 1] < b[i]) f.add(cost_f), g.add(cost_g);
		else f.add(2 * n), g.add(2 * n);
		if (cross_f <= n) f.update(b[i - 1], cross_f);
		if (cross_g <= n) g.update(b[i - 1], cross_g);
		//fprintf(stderr, "cross = %lld %lld\n", cross_f, cross_g);
	}
	ans = std::min(f.min(n), g.min(n));
	cout << (ans <= n ? ans : -1) << '\n';
	return 0;
}