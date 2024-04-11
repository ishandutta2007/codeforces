#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
struct Z {
	int x;
	Z(int _x = 0) : x(_x) {}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x > P) x -= P;
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
	inline Z operator+(const Z &rhs) const {
		Z res = *this;
		return res += rhs;
	}
	inline Z operator-(const Z &rhs) const {
		Z res = *this;
		return res -= rhs;
	}
	inline Z operator*(const Z &rhs) const {
		Z res = *this;
		return res *= rhs;
	}
};
int n;
vector<pair<int, int>> g[200005];
array<Z, 3> dp[200005];
void dfs(int u, int fa) {
	sort(g[u].begin(), g[u].end());
	vector<array<Z, 3>> f(1);
	int mid = 0; 
	for (auto p : g[u]) {
		int v = p.second;
		if (v != fa) {
			dfs(v, u);
			f.emplace_back(dp[v]);
		} else {
			mid = f.size() - 1;
		}
	}
	int m = f.size() - 1;
	vector<Z> pre(m + 2), suf(m + 2);
	pre[0] = 1;
	for (int i = 1; i <= m; ++i)
		pre[i] = pre[i - 1] * (f[i][0] + f[i][1]);
	suf[m + 1] = 1;
	for (int i = m; i; --i)
		suf[i] = suf[i + 1] * (f[i][0] + f[i][2]);
	for (int i = 1; i <= mid; ++i)
		dp[u][0] += pre[i - 1] * f[i][2] * suf[i + 1];
	dp[u][1] = pre[mid] * suf[mid + 1];
	for (int i = mid + 1; i <= m; ++i)
		dp[u][2] += pre[i - 1] * f[i][2] * suf[i + 1];
	dp[u][2] += pre[m];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].emplace_back(i, v);
		g[v].emplace_back(i, u);
	}
	g[1].emplace_back(0, 0);
	dfs(1, 0);
	printf("%d\n", dp[1][2].x);
	return 0;
}