#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef unsigned long long u64;
const int N = 1000054, mod = 998244353, iv3 = (mod + 1) / 3;

int n;
int f[N], g[N];

inline int A(int x) {return (x + 1ull) * (x + 2ull) / 2 % mod;}
inline int B(int x) {return A(x) * (x + 3ull) % mod * iv3 % mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

int main() {
	int i, s = 0, ans;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n, *f = 1;
	for (i = 1; i <= n; ++i) f[i] = A(f[i - 1]);
	ans = 2 * (B(f[n - 1]) - B(n > 1 ? f[n - 2] : 0)) - 1;
	ans %= mod, ans += ans >> 31 & mod;
	for (g[1] = 1, i = 2; i <= n; ++i) g[i] = A(f[i - 1] - 1) - A(f[i - 2] - 1), g[i] += g[i] >> 31 & mod;
	for (i = 1; i + 1 < n; ++i) add(s, g[i]), ans = (ans + (u64)s * g[n - i - 1]) % mod;
	cout << ans << '\n';
	return 0;
}