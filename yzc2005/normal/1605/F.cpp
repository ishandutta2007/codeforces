#include <bits/stdc++.h>
using namespace std;
int n, k, P;
template<typename T> 
T power(T a, int b) {
	T ans = 1;
	for (; b; b >>= 1, a *= a)
		if (b & 1) ans *= a;
	return ans;
}
struct Z {
	int x;
	Z(int _x = 0) : x(_x) {}
	inline void operator+=(const Z &rhs) {
		x += rhs.x;
		if (x >= P) x -= P;
	}
	inline void operator-=(const Z &rhs) {
		x -= rhs.x;
		if (x < 0) x += P;
	}
	inline void operator*=(const Z &rhs) {
		x = 1ull * x * rhs.x % P;
	}
	inline Z operator+(const Z &rhs) {
		Z res = *this;
		return res += rhs, res;
	}
	inline Z operator-(const Z &rhs) {
		Z res = *this;
		return res -= rhs, res;
	}
	inline Z operator*(const Z &rhs) {
		Z res = *this;
		return res *= rhs, res;
	}
};
Z good[85][85], bad[85][85], tot[85][85], tr[85][85];
Z C[85][85], p2[10000];
Z fac[85], ifac[85];
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i;
	ifac[n] = power(fac[n], P - 2);
	for (int i = n - 1; ~i; --i)
		ifac[i] = ifac[i + 1] * (i + 1);
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
}
int main() {
	cin >> n >> k >> P;
	init(80);
	p2[0] = 1;
	for (int i = 1; i < 10000; ++i)
		p2[i] = p2[i - 1] * 2;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int t = 0; t <= j; ++t) {
				Z f = C[j][t] * p2[t * i];
				Z g = C[j][t], cur = p2[t] - 1;
				for (int tt = 0; tt < i; ++tt)
					g *= cur, cur -= 1;
				if ((j - t) & 1) {
					tot[i][j] -= f; 
					tr[i][j] -= g;
				} else {
					tot[i][j] += f;
					tr[i][j] += g;
				}
			}
			tot[i][j] *= C[k][j];
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int i1 = 0; i1 < i; ++i1) {
				for (int j1 = 0; j1 <= j; ++j1) {
					Z cur = good[i1][j1] * C[k - j1][j - j1];
					cur *= tr[i - i1][j - j1] * p2[j1 * (i - i1)] * C[i][i1];
					bad[i][j] += cur;
				}
			}
			good[i][j] = tot[i][j] - bad[i][j];
		}
	}
	Z ans = 0;
	for (int j = 0; j <= k; ++j)
		ans += good[n][j];
	if (n & 1) {
		for (int j = 0; j <= k; ++j) {
			Z cur = good[n - 1][j] * n;
			cur *= p2[j] * (p2[k - j] - 1);
			ans += cur;
		}
	}
	cout << ans.x << "\n";
	return 0;
}