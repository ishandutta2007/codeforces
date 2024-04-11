#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054, mod = 1000000007;

int n, K;
int fact[N], finv[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

inline ll C(int n, int r) {return n < r ? 0 : (ll)fact[n] * finv[r] % mod * finv[n - r] % mod;}
inline ll iC(int n, int r) {return n < r ? 0 : (ll)finv[n] * fact[r] % mod * fact[n - r] % mod;}

void work() {
	int i, m, ans = 1;
	cin >> n >> K, m = n;
	for (i = 1; i <= m; ++i, m -= K - 1) ans = (ans + C(m, i) * iC(n, i)) % mod;
	cout << ans << '\n';
}

int main() {
	int T; init();
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}