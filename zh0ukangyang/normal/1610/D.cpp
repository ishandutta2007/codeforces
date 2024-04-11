#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7; 
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, a[N], cnt[N], ns;
int main() { 
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	init (n);
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) {
		int lg = 0;
		while ((a[i] & ((1 << (lg + 1)) - 1)) == 0) ++ lg;
		cnt[lg] += 1;
	}
	(ns += (ll) (qpow (2, cnt[0]) + mod - 1) * qpow (2, n - cnt[0]) % mod) %= mod;
	L(i, 1, 30) {
		int ret = 0;
		L(j, i + 1, 30) ret += cnt[j];	
		int Z = qpow(2, ret);
		for (int t = 2; t <= cnt[i]; t += 2) {
			(ns += (ll) C(cnt[i], t) * Z % mod) %= mod;
		}
	}
	cout << ns << '\n';
	return 0;
}