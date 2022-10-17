#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
template<class T>
inline T power(T x, int y) {
	T res = 1;
	for (; y; y >>= 1, x *= x)
		if (y & 1) res *= x;
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
};
Z C[45][45], fac[45], dp[1445];
int n, lim[45], cnt[1445][45], siz[1445], sum[1445], buc[45];
vector<int> e[1445];
void dfs1(int cur, int u, int v) {
	if (cur == n + 1) {
		if (u != v) e[u].emplace_back(v);
		return;
	}
	for (int i = 0; i <= buc[cur]; ++i)
		dfs1(cur + 1, u, v * (lim[cur] + 1) + i);
}
void dfs(int cur, int id) {
	if (cur == n + 1) {
		memcpy(cnt[id], buc, sizeof buc);
		for (int i = 1; i <= n; ++i)
			siz[id] += i * buc[i], sum[id] += buc[i];
		dfs1(1, id, 0);
		return;
	}
	for (int i = 0; i <= lim[cur]; ++i)
		buc[cur] = i, dfs(cur + 1, id * (lim[cur] + 1) + i);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i; 
	vector<int> p(n);
	for (auto &x : p)
		scanf("%d", &x), --x;
	for (int i = 0; i < n; ++i) {
		if (p[i] == -1) continue;
		vector<int> v;
		int cur = i;
		do {
			v.emplace_back(cur);
			cur = p[cur];
		} while (cur != i);
		++lim[v.size()];
		for (auto x : v)
			p[x] = -1;
	}
	dfs(1, 0);	
	int all = 1;
	for (int i = 1; i <= n; ++i)
		all *= (lim[i] + 1);
	dp[0] = 1;
	for (int s = 0; s < all; ++s) {
		for (auto t : e[s]) {
			Z coef = 0;
			for (int i = 0; i <= siz[t]; ++i)
				coef += fac[i] * fac[n - i - 1] * C[siz[t]][i];
			coef = power(coef, siz[s] - siz[t]);
			for (int i = 1; i <= n; ++i)
				coef *= C[cnt[s][i]][cnt[s][i] - cnt[t][i]];
			if ((sum[s] - sum[t]) & 1) dp[s] += dp[t] * coef;
			else dp[s] -= dp[t] * coef;
		}
	}
	printf("%d\n", dp[all - 1].x);
	return 0;
}