#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 300054, mod = 998244353;

int n, S = 0;
int a[N], f[N], inv[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

int main() {
	int i, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i], S += a[i];
	for (inv[1] = 1, i = 2; i < S || i <= n; ++i) inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
	f[S] = n - 1;
	for (i = S - 1; i; --i) f[i] = (f[i + 1] * ll(S - i) + S) % mod * (n - 1) % mod * inv[i] % mod;
	for (i = 1; i <= S; ++i) add(f[i], f[i - 1]);
	for (i = 1; i <= n; ++i) add(ans, f[S - a[i]]);
	cout << int((ans + f[S] * (mod - n + 1ll)) % mod * inv[n] % mod) << '\n';
	return 0;
}