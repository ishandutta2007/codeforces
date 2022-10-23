#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
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

int n, a[N];
map < vi, int > mp;
int solve(vi a) {
	if(mp.count(a)) return mp[a];
	int all = 0, cnt = 0;
	L(i, 0, sz(a) - 1) {
		L(j, i + 1, sz(a) - 1) {
			cnt += a[i] > a[j];
			all += 1;
		}
	} 
	if(!cnt) return mp[a] = 0;
	int s = (ll) all * qpow(cnt) % mod;
	L(i, 0, sz(a) - 1) {
		L(j, i + 1, sz(a) - 1) if(a[i] > a[j]) {
			swap(a[i], a[j]);
			(s += (ll) solve(a) * qpow(cnt) % mod) %= mod;
			swap(a[i], a[j]);
		}
	} 
	return mp[a] = s;
}
int f[N];
void Main() {
	cin >> n;
//	L(i, 1, n) cin >> a[i];
	f[0] = 0;
	L(i, 1, n) {
		int all = (ll) n * (n - 1) / 2 % mod;
		int cnt = (ll) i * i % mod;
		f[i] = (f[i - 1] + (ll) all * qpow(cnt) % mod) % mod;
	}
//	vector < pair < int, vi > > prs;
//	L(i, 0, (1 << n) - 1) {
//		vi x;
//		L(j, 0, n - 1) x.push_back(i >> j & 1);
//		prs.push_back({solve(x), x});
//	}
//	sort(prs.begin(), prs.end());
//	for(auto u : prs) {
//		int c0 = 0, c1 = 0, mx = 0;
//		for(auto t : u.second) cout << t, c0 += t == 0;
//		for(auto t : u.second) c1 += t == 1, c0 -= t == 0, mx = max(mx, min(c0, c1));
//		cout << " : " << u.first << ' ' << f[mx] << '\n';
//	}
//	vi x;
//	L(i, 1, n) x.push_back(a[i]);
//	cout << solve(x) << '\n';
	L(i, 1, n) 
		cin >> a[i];
	int c0 = 0, c1 = 0, mx = 0;
	L(i, 1, n) c0 += a[i] == 0;
	L(i, 1, n) c1 += a[i] == 1, c0 -= a[i] == 0, mx = max(mx, min(c0, c1));
	cout << f[mx] << '\n';
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(N - 7);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}