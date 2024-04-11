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
const int kN = 4e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, k, t[kN];
ll f[15][kN], w[kN], s[kN][kN], ans = 0;

void Calc(int l, int r, int d) {
	if(l == r) {
		for(int i = 0; i <= t[l]; ++i)
			ans = std::max(ans, f[d - 1][k - i] + s[l][i]);
	} else {
		int mid = (l + r) >> 1;
		memcpy(f[d], f[d - 1], sizeof(f[d]));
		for(int i = mid + 1; i <= r; ++i)
			for(int j = k; j >= t[i]; --j)
				f[d][j] = std::max(f[d][j], f[d][j - t[i]] + w[i]);
		Calc(l, mid, d + 1);
		memcpy(f[d], f[d - 1], sizeof(f[d]));
		for(int i = l; i <= mid; ++i)
			for(int j = k; j >= t[i]; --j)
				f[d][j] = std::max(f[d][j], f[d][j - t[i]] + w[i]);
		Calc(mid + 1, r, d + 1);
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) {
			rd(t[i]);
			for(int j = 1; j <= t[i]; ++j) {
				int x; rd(x);
				if(j <= k) s[i][j] = s[i][j - 1] + x;
			}
			t[i] = std::min(t[i], k);
			w[i] = s[i][t[i]];
		}
		Calc(1, n, 1);
		printf("%lld\n", ans);
	} return 0;
}