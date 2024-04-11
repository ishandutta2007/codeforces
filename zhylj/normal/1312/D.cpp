#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }
template <typename T> inline void Write(T x) { if(x / 10) Write(x / 10); putchar(x % 10 + 48); }
template <typename T, typename... Args> inline void Write(T x, Args... args) {
	Write(x); putchar(' '); Write(args...);
}
template<typename T> inline T Abs(T x) { return x > 0 ? x : -x; }

typedef long long ll;

const int kN = 2e5 + 5;
const ll kMod = 998244353;

ll fac[kN], inv[kN], fi[kN];

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	while(b) {
		if(b & 1) ans = ans * bas % kMod;
		bas = bas * bas % kMod;
		b >>= 1;
	}
	return ans % kMod;
}

int main() {
	ll n, m, ans = 0; scanf("%lld%lld", &n, &m);
	if(n == 2) {
		printf("0\n");
		return 0;
	}
	fac[0] = 1;
	for(int i = 1; i <= m; ++i) fac[i] = fac[i - 1] * i % kMod;
	inv[1] = 1;
	for(int i = 2; i <= m; ++i)
		inv[i] = ((kMod - kMod / i) % kMod) * (inv[kMod % i] % kMod) % kMod;
	fi[0] = 1;
	for(int i = 1; i <= m; ++i)
		fi[i] = fi[i - 1] * inv[i] % kMod;
	for(int i = n - 1; i <= m; ++i) {
		ans = (ans + fac[i - 1] * fi[n - 2] % kMod * fi[i - n + 1] % kMod) % kMod;
	}
	ans = ans * QPow(2, n - 3) % kMod * (n - 2) % kMod;
	printf("%lld", ans);
	return 0;
}