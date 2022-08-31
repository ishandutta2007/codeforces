#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
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

int n, a[N], ph[N], cnt[N], rg, ord[N], tp, ns;
void Main () {
	rg = 0;
	cin >> n;
	L(i, 1, n) cnt[i] = 0;
	L(i, 1, n) cin >> a[i], cnt[a[i]] += 1;
	L(i, 1, n) rg = __gcd(rg, cnt[i]);
	if(rg == n) {
		cout << 1 << '\n';
		return ;
	}
	tp = 0;
	L(i, 1, n) if(cnt[i]) ord[++tp] = i;
	
	ns = 0;
	L(i, 1, n) ph[i] = 0;
	L(i, 1, n) ph[__gcd(n, i)] += 1;
	int all = 0;
	L(i, 1, n) if(ph[i] && rg % (n / i) == 0) { // cyc = i 
		int ret = 0, mk = n / i;
		int now = fac[i];
		L(j, 1, tp) 
			now = (ll) now * ifac[cnt[ord[j]] / mk] % mod;
		L(j, 1, tp) if(cnt[ord[j]] / mk > 1) 
			(ret += (ll) cnt[ord[j]] / mk * (cnt[ord[j]] / mk - 1) % mod * 
				inv[i] % mod * inv[i - 1] % mod * now % mod) %= mod;
		(ns += (ll) ret * ph[i] % mod) %= mod;
		(all += (ll) now * ph[i] % mod) %= mod;
//		cout << i << " : " << (ll) ret * 2 % mod << '\n';
	}
//	cout << "all = " << all << '\n';
	all = (ll) all * inv[n] % mod;
	ns = (ll) ns * qpow(all) % mod;
	cout << (n + mod - ns) % mod << '\n';
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init (N - 2);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}