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
const int kN = 2e6 + 5, kMod = 1e9 + 7;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % kMod)
		if(b & 1) ret = 1LL * ret * bas % kMod;
	return ret;
}

void FWTxnor(int f[], int len, bool flag) {
	int x = flag ? 1 : QPow(2, kMod - 2);
	for(int i = 1; i < 1 << len; i <<= 1)
		for(int j = 0; j < 1 << len; j += i << 1)
			for(int k = 0; k < i; ++k) {
				int l = f[j + k], r = f[i + j + k];
				f[j + k] = 1LL * (l + r) % kMod * x % kMod;
				f[i + j + k] = 1LL * (l - r + kMod) % kMod * x % kMod;
			}
}

int n, s[kN]; char str[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		int ans = 0;
		rd(n); scanf("%s", str);
		for(int i = 0; i < 1 << n; ++i)
			s[i] = str[i] - '0';
		FWTxnor(s, n, true);
		for(int i = 0; i < 1 << n; ++i)
			s[i] = 1LL * s[i] * s[i] % kMod;
		FWTxnor(s, n, false);
		for(int i = 0; i < 1 << n; ++i) {
			int pcnt = __builtin_popcount(i);
			ans = (ans + (1LL << (n - pcnt)) * s[i]) % kMod;
		}
		ans = 3LL * ans % kMod;
		printf("%d\n", ans);
	} return 0;
}