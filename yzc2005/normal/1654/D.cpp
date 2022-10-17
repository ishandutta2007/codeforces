#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 998244353;
template<class T>
inline T power(T a, i64 b) {
	T res = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) res *= a;
	return res;
}
inline int norm(int x) {
	if (x < 0) x += P;
	if (x >= P) x -= P;
	return x;
}
struct Z {
	int x;
	Z(int _x = 0) : x(norm(_x)) {}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x >= P) x -= P;
		return *this;
	}
	inline Z &operator-=(const Z &rhs) {
		x -= rhs.x;
		if (x < 0) x += P;
		return *this;
	}
	inline Z &operator*=(const Z &rhs) {
		x = 1ull * x * rhs.x % P;
		return *this;
	}
	inline Z inv() const {
		return power(*this, P - 2);
	}
	inline Z &operator/=(const Z &rhs) {
		*this *= rhs.inv();
		return *this;
	}
	inline friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res += rhs, res;
	}
	inline friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res -= rhs, res;
	}
	inline friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res *= rhs, res;
	}
	inline friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		return res /= rhs, res;
	}
};
const int N = 2e5 + 5;
bool is_prime[N];
int n, id[N], eid[N], dfn, c[N], pot[N];
vector<pair<int, pair<Z, Z>>> e[N];
pair<int, int> info[N];
Z coef[N];
vector<int> pos[N]; 
void modify(int p, int x) {
	for (; p <= n; p += p & -p)
		c[p] += x;
}
void modify(int l, int r, int x) {
	modify(l, x);
	modify(r + 1, -x);
}
int query(int p) {
	int res = 0;
	for (; p; p -= p & -p)
		res += c[p];
	return res;
}
void clear(int p) {
	for (; p <= n; p += p & -p)
		c[p] = 0;
}
void dfs1(int u, int fa) {
	id[u] = ++dfn;
	for (auto it : e[u]) {
		int v = it.first;
		if (v == fa) continue;
		Z x, y; tie(x, y) = it.second;
		coef[v] = coef[u] * y / x;
		info[v] = make_pair(x.x, y.x);
		pos[y.x].emplace_back(v);
		pos[x.x].emplace_back(v);
		dfs1(v, u);
	}
	eid[u] = dfn;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		e[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		int g = __gcd(x, y);
		x /= g, y /= g;
		e[u].push_back({v, make_pair(x, y)});
		e[v].push_back({u, make_pair(y, x)});
	}
	dfn = 0;
	coef[1] = 1;
	for (int i = 1; i <= n; ++i)
		pos[i].clear();
	dfs1(1, 0);
	Z ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += coef[i];
	for (int d = 2; d <= n; ++d) {
		if (!is_prime[d]) continue;
		pot[d] = 1;
		vector<int> vec;
		for (int i = 2; i * d <= n; ++i)
			pot[i * d] = (i % d == 0) ? (pot[i] + 1) : 1; 
		for (int x = d; x <= n; x += d) {
			for (auto u : pos[x])
				vec.emplace_back(u);
		}
		sort(vec.begin(), vec.end(), [&](int u, int v) {
			return id[u] < id[v];
		});
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		int mx = 0;
		for (auto u : vec) {
			int cur = query(id[u]);
			cur += pot[info[u].first] - pot[info[u].second];
			mx = max(mx, cur);
			modify(id[u], eid[u], pot[info[u].first] - pot[info[u].second]);
		}
		while (mx--)
			ans *= d;
		for (int x = d; x <= n; x += d)
			pot[x] = 0;
		for (auto u : vec)
			clear(id[u]), clear(eid[u] + 1);
	}
	printf("%d\n", ans.x);
}
int main() {
	memset(is_prime, true, sizeof is_prime);
	for (int i = 2; i < N; ++i)
		for (int j = 2; i * j < N; ++j)
			is_prime[i * j] = false;
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}