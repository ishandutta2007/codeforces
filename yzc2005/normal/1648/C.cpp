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
Z fac[200005], ifac[200005];
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i;
	ifac[n] = fac[n].inv();
	for (int i = n; i; --i)
		ifac[i - 1] = ifac[i] * i;
}
inline Z binom(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return fac[n] * ifac[m] * ifac[n - m];
}
int n, m, s[200005], t[200005], cnt[200005];
Z c[200005];
void modify(int p, Z x) { for (; p <= 200000; p += p & -p) c[p] += x; }
Z query(int p) { Z res = 0; for (; p; p -= p & -p) res += c[p]; return res; }
int main() {
	init(200000);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &t[i]), ++cnt[t[i]];
	for (int i = 1; i <= m; ++i) scanf("%d", &s[i]);
	Z coef = 1;
	for (int i = 1; i <= 200000; ++i) {
		if (!cnt[i]) continue;
		coef *= ifac[cnt[i]];
		modify(i, Z(cnt[i]));
	}
	Z ans = 0;
	for (int i = 0; i < m; ++i) {
		ans += (i == n) ? 1 : coef * query(s[i + 1] - 1) * fac[n - i - 1];
		int x = s[i + 1]; 
		if (!cnt[x]) break;
		modify(x, -Z(cnt[x])), coef *= cnt[x];
		if (--cnt[x]) modify(x, Z(cnt[x]));
	}
	printf("%d\n", ans.x);
	return 0;
}