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
const int N = 10 + 5, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;
const ff Eps = 1e-20;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

const int inv_2 = QPow(2, Mod - 2), inv_6 = QPow(6, Mod - 2);

ll M; int m;
int P(int x) {
	int s1 = 1LL * (m + 1) * (x + m) % Mod * (m - x + 1) % Mod * inv_2 % Mod, s2;
	s1 = (s1 + Mod) % Mod;
	s2 = (1LL * m * (m + 1) % Mod * (2 * m + 1) -
			1LL * x * (x - 1) % Mod * (2 * x - 1)) % Mod;
	s2 = (s2 + Mod) % Mod;
	s2 = 1LL * s2 * inv_6 % Mod;
	return (s1 - s2 + Mod) % Mod;
}

int fac[N], fac_inv[N], inv[N];
void Init() {
	int imx = 10;
	fac[0] = 1;
	for(int i = 1; i <= imx; ++i) fac[i] = 1LL * fac[i - 1] * i % Mod;
	fac_inv[imx] = QPow(fac[imx], Mod - 2);
	for(int i = imx - 1; ~i; --i) fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % Mod;
	for(int i = 1; i <= imx; ++i) inv[i] = 1LL * fac_inv[i] * fac[i - 1] % Mod;
}
int pre[N], suf[N], Q[N];
int Get(int x) {
	int t = sqrt(M - 1LL * x * x) + Eps;
	Q[0] = P(1LL * x * x % Mod);
	for(int i = 1; i <= 8; ++i) {
		Q[i] = (Q[i - 1] + 2 * P((1LL * x * x + 1LL * i * i) % Mod) % Mod) % Mod;
	}
	if(t <= 8) return Q[t];
	int ret = 0;
	pre[0] = suf[9] = 1;
	for(int i = 1; i <= 8; ++i)
		pre[i] = 1LL * pre[i - 1] * (t - i) % Mod;
	for(int i = 8; i; --i)
		suf[i] = 1LL * suf[i + 1] * (t - i) % Mod;
	for(int i = 1; i <= 8; ++i) {
		int si = i & 1 ? -1 : 1;
		ret = (ret + 1LL * si * pre[i - 1] * suf[i + 1] % Mod *
				fac_inv[i - 1] % Mod * fac_inv[8 - i] % Mod * Q[i]) % Mod;
	}
	ret = (ret + Mod) % Mod;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(M); m = M % Mod;
		Init();
		int ans = 0;
		for(int i = 1; 1LL * i * i <= M; ++i)
			ans = (ans + 2 * Get(i) % Mod) % Mod;
		ans = (ans + Get(0)) % Mod;
		printf("%d\n", ans);
	} return 0;
}