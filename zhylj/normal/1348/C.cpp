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
const int kN = 1e6 + 5;
const ll kMod = 998244353;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

char c[kN], ans1[kN], ans2[kN]; int n, k, cnt = 0;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		cnt = 0;
		rd(n, k);
		scanf("%s", c + 1);
		std::sort(c + 1, c + n + 1);
		for(int i = 1; i <= n; i += k) {
			if(c[i] == c[i + k - 1]) ans1[++cnt] = c[i];
			else {
				ans1[++cnt] = c[std::min(i + k - 1, n)];
				break;
			}
		}
		bool flag = true;
		for(int i = k; i <= n; ++i)
			ans2[i - k + 1] = c[i];
		ans2[n - k + 2] = 0; ans1[cnt + 1] = 0;
		for(int i = 1; i <= cnt + 1; ++i) {
			if(ans1[i] != ans2[i]) {
				flag = (ans1[i] < ans2[i]); break;
			}
		}
		if(flag) {
			printf("%s\n", ans1 + 1);
		} else {
			printf("%s\n", ans2 + 1);
		}
	} return 0;
}