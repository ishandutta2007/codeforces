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
Z fac[1000005], ifac[1000005]; 
void solve() {
	cin >> n >> m >> k;
	auto binom = [&](int n, int m) {
		return fac[n] * ifac[m] * ifac[n - m];
	};
	if (n == m) {
		Z ans = Z(k) * n;
		cout << ans.x << "\n";
		return;
	}
	Z ans = 0;
	for (int i = 1; i <= m; ++i)
		ans += binom(n - i - 1, m - i) * power(Z(2), P - 1 - (n - i)) * k * i; 
	cout << ans.x << "\n";
}
int main() {
	fac[0] = 1;
	for (int i = 1; i <= 1000000; ++i)
		fac[i] = fac[i - 1] * i;
	ifac[1000000] = fac[1000000].inv();
	for (int i = 1000000; i; --i)
		ifac[i - 1] = ifac[i] * i;
	int t;
	cin >> t;
	while (t--)	
		solve();
	return 0;
}