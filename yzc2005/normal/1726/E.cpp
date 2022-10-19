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
const int N = 300005;
Z fac[N], ifac[N], pw[N], dp[N], coef[N];
void init(int n) {
	fac[0] = pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1] * i;
		pw[i] = pw[i - 1] * 2;
	}
	ifac[n] = fac[n].inv();
	for (int i = n; i; --i) {
		ifac[i - 1] = ifac[i] * i;
	}
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i > 1) {
            dp[i] += dp[i - 2] * (i - 1);
        }
    }
    coef[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        coef[i] = coef[i - 2] * (i - 1) * 2;
    }
}

Z binom(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] * ifac[n - m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init(N - 1);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Z ans = 0;

        for (int i = 0; i * 4 <= n; ++i) {
            Z res = dp[n - i * 4];
            res *= binom(n - 2 * i, 2 * i);
            ans += res * coef[i * 2];
        }

        cout << ans.x << "\n";
    }

    return 0;
}