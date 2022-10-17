#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 1e9 + 7;
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
int n, a[2005], b[2005], sa[2005][2], sb[2005][2];
char s[2005], t[2005];
Z binom[4005][4005];
void solve() {
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = (s[i] == '?') ? -1 : (s[i] + i) % 2;
		b[i] = (t[i] == '?') ? -1 : (t[i] + i) % 2;
	}
	Z ans = 0;
	auto calc = [&](int A, int B, int C) {
		if (C < 0) swap(A, B), C = -C;
		return binom[A + B][B + C];
	};
	auto solve = [&]() {
		for (int i = 1; i <= n; ++i) {
			sa[i][0] = sa[i - 1][0] + (a[i] == -1);
			sa[i][1] = sa[i - 1][1] + (a[i] == 0);
			sb[i][0] = sb[i - 1][0] + (b[i] == -1);
			sb[i][1] = sb[i - 1][1] + (b[i] == 0);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int A = sa[i][0], B = sb[i][0];
				int C = j - (sa[i][1] - sb[i][1]);
				Z x = calc(A, B, C);
				A = sa[n][0] - sa[i][0], B = sb[n][0] - sb[i][0];
				C = -j - (sa[n][1] - sa[i][1] - (sb[n][1] - sb[i][1]));
				Z y = calc(A, B, C);
				ans += x * y * j;
			}
		}
	};
	solve();
	swap(a, b);
	solve();
	printf("%d\n", ans.x);
}
int main() {
	for (int i = 0; i <= 4000; ++i) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; ++j) 
			binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
	}
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}