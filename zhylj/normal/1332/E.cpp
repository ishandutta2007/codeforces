#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }

typedef long long ll;

const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = (a % kMod + kMod) % kMod;
	while(b) {
		if(b & 1) ans = (ans * bas) % kMod;
		bas = (bas * bas) % kMod;
		b >>= 1;
	}
	return ans;
}

int main() {
	ll n, m, L, R;
	Read(n, m, L, R);
	if(n * m % 2 == 1) {
		printf("%lld", QPow(R - L + 1, n * m));
	} else {
		ll x = R / 2 - (L - 1) / 2, y = (R - L + 1) - x;
		printf("%lld", (QPow(x + y, n * m) + QPow(x - y, n * m)) % kMod * QPow(2, kMod - 2) % kMod);
	}
	return 0;
}