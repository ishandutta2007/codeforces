#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 1e9 + 7;
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
int n, m, k;
Z dp[2005][2005];
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i == j) {
				dp[i][j] = dp[i - 1][i - 1] + k;
			} else {
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) / 2;
			}
		}
	}
	cout << dp[n][m].x << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--)	
		solve();
	return 0;
}