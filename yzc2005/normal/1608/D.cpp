#include<bits/stdc++.h>
using std::cin;
using std::cout;
int n, T;
using u64 = unsigned long long;
const int N = 200005;
const int mod = 998244353;
int cnt[9];
inline int toint(int x) {
	if(x == '?') return 0;
	return x == 'B' ? 1 : 2;
}
int a[N], b[N];
int fac[N], ifac[N], inv[N];
inline int comb(int a, int b) {
	return (u64) fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
inline int calc0() {
	int ans = 1;
	for(int i = 0;i < n;++i) {
		if(a[i] && b[i] && a[i] != b[i]) return 0;
		if(!a[i] && !b[i]) ans = ans * 2 % mod;
	}
	return ans;
}
inline int calc1(int x) {
	for(int i = 0;i < n;++i) {
		if(a[i] && a[i] != x) return 0;
		if(b[i] && b[i] != x) return 0;
	}
	return 1;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	*fac = fac[1] = *ifac = ifac[1] = inv[1] = 1;
	for(int i = 2;i < N;++i) {
		inv[i] = u64(mod - mod / i) * inv[mod % i] % mod;
		fac[i] = (u64) fac[i - 1] * i % mod;
		ifac[i] = (u64) ifac[i - 1] * inv[i] % mod;
	}
	cin >> n;
	for(int i = 0;i < n;++i) {
		char x, y; cin >> x >> y;
		a[i] = toint(x);
		b[i] = toint(y);
		if(b[i] > 0) b[i] = 3 - b[i];
	}
	int ans = calc0() - calc1(1) - calc1(2);
	ans = (ans % mod + mod) % mod;
	ans = mod - ans;
	int x_cnt = 0, x_1_cnt = 0;
	for(int i = 0;i < n;++i) {
		if(a[i] == 0) x_1_cnt += 1;
		if(a[i] == 1) x_cnt += 1;
		if(b[i] == 0) x_1_cnt += 1, x_cnt -= 1;
		if(b[i] == 1) x_cnt -= 1;
	}
	x_cnt *= -1;
	if(x_cnt >= 0 && x_cnt <= x_1_cnt) {
		ans = (ans + comb(x_1_cnt, x_cnt)) % mod;
	}
	cout << ans % mod << '\n';
}