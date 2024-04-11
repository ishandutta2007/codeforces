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
	inline Z operator/(const Z &rhs) const {
		Z res = *this;
		return res /= rhs;
	}
};
const int N = 12252240;
int n, x, y, k, M, a[10000005];
Z f[N], g[N], ans;
int main() {
	scanf("%d%d%d%d%d%d", &n, &a[0], &x, &y, &k, &M);
	for (int i = 1; i < n; ++i)
		a[i] = (1ll * a[i - 1] * x + y) % M;
	Z coef = power(Z(n), k - 1) * k;
	for (int i = 0; i < n; ++i) {
		int x = a[i] / N, y = a[i] % N;
		ans += coef * x * N;
		f[y] += 1;		
	}
	for (int i = 1; i <= k; ++i) {
		memset(g, 0, sizeof g);
		Z res = 0;
		for (int x = 0; x < N; ++x) {
			if (!f[x].x) continue;
			res += f[x] * x;
			g[x] += f[x] * (n - 1);
			g[x - x % i] += f[x];
		}
		ans += res * power(Z(n), k - i);
		memcpy(f, g, sizeof f);
	}
	printf("%d\n", ans.x);
	return 0;
}