#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 4e6 + 5, MOD = 998244353, G = 3, GINV = (MOD + 1) / 3;

int QPow(int a, ll b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}
int Inv(int a) { return QPow(a, MOD - 2); }

int rev[N], ur[N];
int GetRev(int x) {
	int len = 1, h_bit = 0; ur[0] = 1;
	for(; len <= x; len <<= 1, ++h_bit);
	for(int i = 0; i < len; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h_bit - 1));
	return len;
}
void NTT(int f[], int len, bool flag) {
	for(int i = 1; i < len; ++i)
		if(i < rev[i]) std::swap(f[i], f[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		int g = QPow(flag ? G : GINV, (MOD - 1) / (i << 1));
		for(int j = 1; j < i; ++j)
			ur[j] = 1LL * ur[j - 1] * g % MOD;
		for(int j = 0; j < len; j += i << 1)
			for(int k = 0; k < i; ++k) {
				int fl = f[j + k], fr = 1LL * f[i + j + k] * ur[k] % MOD;
				f[j + k] = fl + fr >= MOD ? fl + fr - MOD : fl + fr;
				f[i + j + k] = fl - fr < 0 ? fl - fr + MOD : fl - fr;
			}
	}
	if(!flag) {
		int len_inv = Inv(len);
		for(int i = 0; i < len; ++i)
			f[i] = 1LL * f[i] * len_inv % MOD;
	}
}

int n, f[N], fac[N], fac_inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i <= n; ++i)
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[n] = Inv(fac[n]);
	for(int i = n - 1; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % MOD * fac_inv[x - y] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); Init();
		int ans = 0, len = GetRev((n << 1) + 2);
		for(int i = 0; i < n; ++i)
			f[i] = 1LL * C(n, i) * QPow(GINV, 1LL * i * (i - 1) / 2) % MOD;
		NTT(f, len, true);
		for(int i = 0; i < len; ++i)
			f[i] = 1LL * f[i] * f[i] % MOD;
		NTT(f, len, false);
		for(int i = 0, si = 1; i <= 2 * n; ++i, si *= -1)
			ans = (ans + 3LL * f[i] % MOD * si * QPow(3, 1LL * i * (i - 1) / 2)) % MOD;
		for(int i = 0; i <= n; ++i) {
			int si = i % 2 == 0 ? 1 : -1;
			int t = 1LL * si * C(n, i) % MOD * QPow(3, 1LL * (n - i) * n) % MOD;
			ans = (ans + 1LL * QPow(3, i) * t % MOD * (i == 0 ? 1 : 2)) % MOD;
		}
		ans = (ans + MOD) % MOD;
		ans = (QPow(3, 1LL * n * n) - ans + MOD) % MOD;
		printf("%d\n", ans);
	} return 0;
}