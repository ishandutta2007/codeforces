#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int mod = 998244353;

int inv[2000054];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int main() {
	int i, n, m; ll H = 1;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> m;
	for (inv[1] = 1, i = 2; i <= n; ++i) H += inv[i] = ll(mod - mod / i) * inv[mod % i] % mod;
	cout << PowerMod(m + 1, mod - 2, (H % mod * m + 1) % mod * (n + m + 1) % mod) << '\n';
	return 0;
}