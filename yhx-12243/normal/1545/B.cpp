#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054, mod = 998244353;

int n, L;
char s[N];
int a[N];
int fact[N], finv[N];

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

inline ll C(int n, int r) {return (ll)fact[n] * finv[r] % mod * finv[n - r] % mod;}

void work() {
	int i, la = -1, rem; L = 0;
	cin >> n >> s;
	for (i = 0; i < n; ++i) if (~s[i] & 1) a[L++] = i & 1;
	if (!L) {cout << '1' << '\n'; return;}
	for (i = 0; i < L; ++i)
		if ((++la ^ a[i]) & 1) ++la;
	rem = (n - la - 1) / 2;
	cout << C(L + rem, rem) << '\n';
}

int main() {
	int T; init();
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}