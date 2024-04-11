#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 5054, mod = 1000000007;

int n, K;
int f[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int main() {
	int i, j, x, in, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K, *f = 1, in = PowerMod(n, mod - 2);
	for (i = 0; i < n; ++i) {
		cin >> x;
		for (j = i + 1; j; --j) f[j] = ((ll)f[j] * x + mod - f[j - 1]) % mod;
		*f = (ll)*f * x % mod;
	}
	for (x = mod - 1, i = 1; i <= n && i <= K; ++i)
		x = x * (K - i + 1ll) % mod * in % mod,
		ans = (ans + (ll)x * f[i]) % mod;
	cout << ans << '\n';
	return 0;
}