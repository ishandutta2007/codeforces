#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; 
inline void add(int &a, int b) {
    (a += b) >= mod && (a -= mod);
}
inline int Add(int a, int b) {
    return add(a, b), a;
}
inline void sub(int &a, int b) {
    (a -= b) < 0 && (a += mod);
}
inline int Sub(int a, int b) {
    return sub(a, b), a;
}
inline void mul(int &a, int b) {
    a = 1ll * a * b % mod;
}
inline int Mul(int a, int b) {
    return 1ll * a * b % mod;
}

const int N = 500005;
int n, ans, a[N], b[N], c[N];

struct BIT {
	int s[N];
	inline void init() {
		memset(s, 0, sizeof(s));
	}
	inline void addval(int p, int v) {
		for(; p <= n; p += p & -p) add(s[p], v);
	}
	inline int query(int p) {
		int res = 0;
		for(; p; p -= p & -p) add(res, s[p]);
		return res;
	}
} bit;

inline void solve() {
	for(int i = 1; i <= n; ++i) {
		add(ans, Mul(c[i], Mul(bit.query(a[i]), n - i + 1)));
		bit.addval(a[i], i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i], c[i] = b[i] = a[i];
	for(int i = 1; i <= n; ++i) add(ans, Mul(a[i], Mul(i, n - i + 1)));
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	solve(), reverse(a + 1, a + n + 1), reverse(c + 1, c + n + 1), bit.init(), solve();
	return cout << ans, 0;
}