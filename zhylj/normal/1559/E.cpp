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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % Mod)
		if(b & 1) ret = 1LL * ret * bas % Mod;
	return ret;
}

int n, m, o_l[N], o_r[N], a[N];

int mu[N], p[N], p_cnt; bool flag[N];
void Sieve() {
	mu[1] = 1;
	for(int i = 2; i <= m; ++i) {
		if(!flag[i]) {
			p[++p_cnt] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= p_cnt && i * p[j] <= m; ++j) {
			flag[i * p[j]] = true;
			if(i % p[j] == 0) { mu[i * p[j]] = 0; break; }
			mu[i * p[j]] = -mu[i];
		}
	}
}
int f[N], fac[N], fac_inv[N];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % Mod;
	fac_inv[N - 1] = QPow(fac[N - 1], Mod - 2);
	for(int i = N - 2; ~i; --i) fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % Mod;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % Mod * fac_inv[x - y] % Mod;
}
int Calc(int d) {
	int ret = 0, t = m / d + 1;
	for(int i = 0; i <= 2 * t; ++i) f[i] = 0;
	for(int i = 1; i <= n; ++i) {
		int l = (o_l[i] - 1) / d + 1, r = o_r[i] / d;
		if(l > r) return 0;
		a[i] = r - l + 1;
		t -= l;
	}
	f[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = t; j >= a[i]; --j)
			f[j] = (f[j] - f[j - a[i]] + Mod) % Mod;
	}
	for(int i = 0; i <= t; ++i)
		ret = (ret + 1LL * f[i] * C(t - i + n - 1, n - 1) % Mod + Mod) % Mod;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m); Init(); Sieve();
		for(int i = 1; i <= n; ++i)
			rd(o_l[i], o_r[i]);
		o_l[++n] = 1; o_r[n] = m;
		int ans = 0;
		for(int i = 1; i <= m; ++i)
			if(mu[i] != 0)
				ans = ((ll)ans + mu[i] * Calc(i) + Mod) % Mod;
		printf("%d\n", ans);
	} return 0;
}