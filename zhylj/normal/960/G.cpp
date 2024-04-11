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
const int N = 1e6 + 5, MOD = 998244353, G = 3, GINV = (MOD + 1) / 3;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}
int Inv(int a) { return QPow(a, MOD - 2); }

int fac[N], fac_inv[N], inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[N - 1] = Inv(fac[N - 1]);
	for(int i = N - 2; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
	for(int i = 1; i < N; ++i)
		inv[i] = 1LL * fac_inv[i] * fac[i - 1] % MOD;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % MOD * fac_inv[x - y] % MOD;
}

int rev[N], ur[N];
int GetRev(int n) {
	int len = 1, h_bit = 0; ur[0] = 1;
	for(; len <= n; len <<= 1, ++h_bit);
	for(int i = 0; i < len; ++i)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h_bit - 1));
	return len;
}
void NTT(int f[], int len, bool flag) {
	for(int i = 1; i < len; ++i)
		if(i < rev[i]) std::swap(f[i], f[rev[i]]);
	for(int i = 1; i < len; i <<= 1) {
		int g = QPow(flag ? G : GINV, (MOD - 1) / (i << 1));
		for(int j = 1; j < i; ++j) ur[j] = 1LL * ur[j - 1] * g % MOD;
		for(int j = 0; j < len; j += i << 1)
			for(int k = 0; k < i; ++k) {
				int fl = f[j + k], fr = 1LL * ur[k] * f[i + j + k] % MOD;
				f[j + k] = fl + fr >= MOD ? fl + fr - MOD : fl + fr;
				f[i + j + k] = fl - fr < 0 ? fl - fr + MOD : fl - fr;
			}
	}
	if(!flag) {
		int len_inv = inv[len];
		for(int i = 0; i < len; ++i) f[i] = 1LL * f[i] * len_inv % MOD;
	}
}

int s[N], f[N], g[N];
void Div(int n) {
	if(n == 0) { s[0] = 1; return; }
	if(n == 1) { s[1] = 1; return; }
	Div(n / 2);
	int len = GetRev((n + 2) << 1);
	memset(f, 0, len * sizeof(int));
	memset(g, 0, len * sizeof(int));
	for(int i = 0; i <= n; ++i) f[i] = 1LL * s[i] * fac[i] % MOD;
	for(int i = 0, bas = 1; i <= n; ++i, bas = 1LL * bas * (n / 2) % MOD)
		g[i] = 1LL * bas * fac_inv[i] % MOD;
	std::reverse(g, g + n + 1);
	NTT(f, len, true); NTT(g, len, true);
	for(int i = 0; i < len; ++i)
		f[i] = 1LL * f[i] * g[i] % MOD;
	NTT(f, len, false);
	memset(g, 0, len * sizeof(int));
	for(int i = n; i <= n << 1; ++i)
		g[i - n] = 1LL * f[i] * fac_inv[i - n] % MOD;
	memset(f, 0, len * sizeof(int));
	if(n % 2 == 1) f[0] = n - 1, f[1] = 1;
	else f[0] = 1;
	NTT(s, len, true); NTT(g, len, true); NTT(f, len, true);
	for(int i = 0; i < len; ++i)
		s[i] = 1LL * s[i] * g[i] % MOD * f[i] % MOD;
	NTT(s, len, false);
}

int n, a, b;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		Init();
		rd(n, a, b);
		Div(n - 1);
		int ans = 1LL * s[a + b - 2] * C(a + b - 2, a - 1) % MOD;
		printf("%d\n", ans);
	} return 0;
}