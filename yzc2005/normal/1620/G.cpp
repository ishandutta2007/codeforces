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
const int N = 23, S = 1 << 23 | 5;
int n, cnt[N], mn[S];
Z f[S];
string s[N];
int main() {
	cin >> n;
	fill(f + 1, f + (1 << n), Z(1));
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int c = 0; c < 26; ++c) {
		for (int i = 0; i < n; ++i)
			cnt[i] = count(s[i].begin(), s[i].end(), char('a' + c));
		mn[0] = 1e9;
		for (int s = 1; s < 1 << n; ++s) {
			int i = __builtin_ctz(s);
			mn[s] = min(mn[s ^ (1 << i)], cnt[i]);
			f[s] *= mn[s] + 1;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int s = 0; s < 1 << n; ++s)
			if (s >> i & 1) f[s] -= f[s ^ (1 << i)];
	long long ans = 0;
	for (int s = 1; s < 1 << n; ++s) {
		Z res = f[s];
		int cnt = 0, sum = 0;
		for (int x = s; x; x -= x & -x)
			++cnt, sum += __builtin_ctz(x) + 1;
		if (cnt % 2 == 0) res = -res;
		ans ^= 1ll * res.x * cnt * sum;
	}
	cout << ans << "\n";
	return 0;
}