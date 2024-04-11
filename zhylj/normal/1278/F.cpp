#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 1e7 + 5, kP = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ret = 1, bas = a % kMod;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, m, k, p;

int prime[kP], cnt = 0, pw_xk[kN];
bool flag[kN];
void Sieve() {
	pw_xk[1] = 1;
	for(int i = 2; i <= k; ++i) {
		if(!flag[i]) {
			prime[++cnt] = i;
			pw_xk[i] = QPow(i, k);
		}
		for(int j = 1; j <= cnt && i * prime[j] <= k; ++j) {
			flag[i * prime[j]] = true;
			pw_xk[i * prime[j]] = (ll)pw_xk[i] * pw_xk[prime[j]] % kMod;
			if(i % prime[j] == 0) break;
		}
	}
}
int pw_px[kN], C_n_x[kN], C_nx1_kx[kN], inv[kN], f[kN];
void Init() {
	Sieve();
	pw_px[0] = C_n_x[0] = 1; f[0] = 0;
	ll np = -p + kMod, fac = 1;
	for(int i = 1; i <= k; ++i) fac = fac * i % kMod;
	inv[k] = QPow(fac, kMod - 2); fac = 1;
	for(int i = k - 1; ~i; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % kMod;
	for(int i = 1; i <= k; ++i) {
		inv[i] = (ll)inv[i] * fac % kMod;
		fac = fac * i % kMod;
	}
	for(int i = 1; i <= k; ++i) {
		pw_px[i] = (ll)pw_px[i - 1] * np % kMod;
		C_n_x[i] = (ll)C_n_x[i - 1] * (n - i + 1) % kMod * inv[i] % kMod;
	}
	C_nx1_kx[0] = (ll)C_n_x[k] * QPow(n, kMod - 2) % kMod * (n - k) % kMod;
	for(int i = 1; i <= k; ++i)
		C_nx1_kx[i] = C_nx1_kx[i - 1] * QPow(n - i, kMod - 2) % kMod * (k - i + 1) % kMod;
	f[k] = 1;
	for(int i = k - 1; ~i; --i) {
		f[i] = (ll)f[i + 1] * (1 + np) % kMod + (ll)C_nx1_kx[i] * pw_px[k - i] % kMod;
	}
}

ll Calc() {
	ll ret = 0;
	if(n > k) {
		ll bas_p = 1;
		for(int i = 0; i <= k; ++i) {
			ret = (ret + (ll)bas_p * pw_xk[i] % kMod * C_n_x[i] % kMod * f[i]) % kMod;
			bas_p = bas_p * p % kMod;
		}
	} else {
		ll bas_p = 1, bas_1p = QPow(1 - p + kMod, n), inv_1p = QPow(1 - p + kMod, kMod - 2);
		for(int i = 0; i <= k; ++i) {
			ret = (ret + C_n_x[i] * bas_p % kMod * bas_1p % kMod * pw_xk[i]) % kMod;
			bas_p = bas_p * p % kMod;
			bas_1p = bas_1p * inv_1p % kMod;
		}
	}
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m, k);
		if(m == 1) {
			printf("%d\n", n);
			continue;
		}
		p = QPow(m, kMod - 2);
		Init();
		printf("%lld\n", Calc());
	} return 0;
}