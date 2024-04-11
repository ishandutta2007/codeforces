#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
#define popc __builtin_popcount
using std::cin;
using std::cout;

typedef long long ll;
const int N = 16, N2 = 16400, mod = 1000000007;

int n, ALL;
int a[N];
int prob[N2];
int G[N][N], cr[N][N2];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int cross(int A, int B) {
	int ret = 1;
	for (; A; A &= A - 1) ret = (ll)ret * cr[ctz(A)][B] % mod;
	return ret;
}

int main() {
	int i, j, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n, ALL = ~(-1 << n);
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) G[i][j] = PowerMod(a[i] + a[j], mod - 2, a[i]);
	for (i = 0; i < n; ++i) {
		*cr[i] = 1;
		for (j = 1; j <= ALL; ++j)
			cr[i][j] = (ll)cr[i][j & (j - 1)] * G[i][ctz(j)] % mod;
	}
	for (i = 1; i <= ALL; ++i) {
		prob[i] = 1;
		for (j = i & (i - 1); j; j = (j - 1) & i)
			prob[i] = (prob[i] - (ll)prob[j] * cross(j, i - j)) % mod;
		prob[i] += prob[i] >> 31 & mod;
		ans = (ans + (ll)prob[i] * cross(i, ALL - i) % mod * popc(i)) % mod;
	}
	cout << ans << '\n';
	return 0;
}