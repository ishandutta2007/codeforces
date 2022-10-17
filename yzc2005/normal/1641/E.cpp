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
	inline int val() const {
		return x;
	}
	inline Z operator-() const {
		if (!x) return 0;
		return Z(P - x);
	}
	inline Z &operator+=(const Z &rhs) {
		x += rhs.x;
		if (x > P) x -= P;
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
vector<int> rev;
vector<Z> roots{0, 1};
inline int extend(int n) {
	int len = 1;
	while (len < n)
		len <<= 1;
	return len;
}
using poly = vector<Z>;
void dft(poly &a) {	
	int n = a.size();
	int k = __builtin_ctz(n);
	if (int(rev.size()) != n) {
		rev.resize(n);
		for (int i = 0; i < n; ++i)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
	}
	if (int(roots.size()) < n) {
		int k1 = __builtin_ctz(roots.size());
		roots.resize(n);
		for (; k1 < k; ++k1) {
			Z e = power(Z(3), (P - 1) >> (k1 + 1));
			for (int i = 1 << (k1 - 1); i < (1 << k1); ++i) {
				roots[i * 2] = roots[i];
				roots[i * 2 + 1] = roots[i] * e;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2) {
		for (int i = 0; i < n; i += k * 2) {
			for (int j = 0; j < k; ++j) {
				Z x = a[i + j];
				Z y = a[i + j + k] * roots[j + k];
				a[i + j] = x + y;
				a[i + j + k] = x - y;
			}
		}
	}
}
void idft(poly &a) {
	reverse(a.begin() + 1, a.end());
	dft(a);
	int n = a.size();
	Z coef = Z(n).inv();
	for (int i = 0; i < n; ++i) 
		a[i] *= coef;
}
poly operator*(poly a, poly b) {
	int len = int(a.size() + b.size() - 1);
	int n = extend(len);
	a.resize(n), dft(a);
	b.resize(n), dft(b);
	for (int i = 0; i < n; ++i)
		a[i] *= b[i];
	idft(a);
	a.resize(len);
	return a;
}
const int N = 1e5 + 5;
const Z p = (P + 1) / 2;
int n, m, a[N], sum[N];
Z f[N], g[N], c[N];
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid), solve(mid + 1, r);
	vector<Z> v1, v2;
	for (int i = l; i <= mid; ++i)
		v1.emplace_back(f[max(i, 0)]);
	for (int i = mid + 1; i <= r; ++i)
		v2.emplace_back(g[min(i, n)]);
	auto res = v1 * v2;
	int offset = l + mid + 1;
	for (int i = 0; i < (int) res.size(); ++i) {
		int pos = i + offset;
		if (pos > 0 && (pos & 1) && pos < 2 * n) c[(pos + 1) / 2] += res[i];
	}
}
int main() {
	cin >> n >> m;
	Z coef = power(Z(2), m), coef1 = coef - 1, ans = 0;
	for (int i = 1; i <= n; ++i)	
		cin >> a[i], ans -= Z(a[i]) * min(i + n, n * 2 - i + 1);
	while (m--) {
		int x;
		cin >> x;
		++sum[x];
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] += sum[i - 1];
		f[i - 1] = power(Z(2), sum[i - 1]);
		g[i] = power(p, sum[i]);
	}
	solve(-n, n * 2);
	for (int i = 1; i <= n; ++i)
		ans += c[i] * a[i] * coef;
	ans /= coef1;
	cout << ans.x << "\n";
	return 0;
}