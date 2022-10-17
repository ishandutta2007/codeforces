#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int rng(int l, int r) { return rnd() % (r - l + 1) + l; }
using i64 = long long;
const int P = 998244353;
template<class T>
inline T power(T a, i64 b) {
	T res = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) res *= a;
	return res;
}
struct Z {
	int x;
	Z(int _x = 0) : x(_x) {}
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
const int N = 305;
int n, r;
vector<int> e[N];
Z f[N][N], g[N][N], tf[N], tg[N];
void merge(Z *f1, Z *g1, Z *f2, Z *g2) {
	memset(tf, 0, sizeof tf), memset(tg, 0, sizeof tg);
	int l1 = r, l2 = r;
	while (~l1 && !f1[l1].x && !g1[l1].x) --l1;
	while (~l2 && !f2[l2].x && !g2[l2].x) --l2;
	for (int i = 0; i <= l1; ++i) {
		if (!f1[i].x && !g1[i].x) continue;
		for (int j = 0; j <= l2; ++j) {
			tf[min(i, j)] += f1[i] * f2[j];
			(i + j >= r ? tg[j] : tf[i]) += f1[i] * g2[j];
			(i + j >= r ? tg[i] : tf[j]) += g1[i] * f2[j];
			tg[max(i, j)] += g1[i] * g2[j];
		}
	}
}
void dfs(int u, int fa) {
	Z prod = 1; f[u][r] = 1;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u); Z sum = 0;
		for (int i = 0; i <= r; ++i)
			sum += f[v][i] + g[v][i]; 
		prod *= sum;
		merge(f[u], g[u], f[v], g[v]);
		memcpy(f[u], tf, sizeof tf), memcpy(g[u], tg, sizeof tg);
	}
	for (int i = r; i > 1; --i) g[u][i] = g[u][i - 1];
	g[u][1] = f[u][r]; 
	for (int i = r; i; --i) f[u][i] = f[u][i - 1];
	f[u][0] = prod;
}
Z calc() {
	memset(f, 0, sizeof f), memset(g, 0, sizeof g);
	dfs(1, 0); Z ans = 0;
	for (int i = 0; i <= r; ++i) ans += f[1][i];
	return ans;
}
int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	Z ans = 0;
	for (r = 1; r <= n; ++r) {
		Z res = power(Z(2), n) - calc();
		ans += res;
	}
	ans = (ans - 1) / power(Z(2), n);
	cout << ans.x << "\n";
	return 0;
}