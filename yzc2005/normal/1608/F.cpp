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
int n, k, b[2005];	
Z f[105][2005], g[105][2005], sum[2005];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]); 
	b[0] = -k;
	for (int j = 0; j <= 2 * k; ++j) {
		int val = b[n] + j - k;
		if (val >= 0 && val <= n) f[j][1] = 1;
	}
	for (int i = n; i; --i) {
		memset(g, 0, sizeof g);
		for (int j = 0; j <= 2 * k; ++j) {
			int pos = b[i] + j - k - b[i - 1] + k;
			if (pos < 0 || pos > 2 * k) continue;
			for (int c = 1; c <= n + 1; ++c)
				g[pos][c] += f[j][c] * (n + 1 - c);
		} // case1 : a_{i-1} = a_i
		memset(sum, 0, sizeof sum);
		for (int v = b[i] + k - 1; v >= b[i - 1] - k; --v) {
			for (int c = n + 1; c; --c)
				sum[c] -= sum[c - 1];
			int pos = v + 1 - b[i] + k;
			if (pos >= 0) {
				for (int c = 1; c <= n + 1; ++c)
					sum[c] += f[pos][c];
			}
			pos = v - b[i - 1] + k;
			if (pos <= 2 * k) {
				for (int c = 1; c <= n; ++c)
					g[pos][c + 1] += sum[c];
			}
		} // case2 : a_{i-1} < a_i
		memcpy(f, g, sizeof f);
	}
	Z ans = 0;
	for (int c = 1; c <= n + 1; ++c)
		ans += f[2 * k][c];
	printf("%d\n", ans.x);	
	return 0;
}