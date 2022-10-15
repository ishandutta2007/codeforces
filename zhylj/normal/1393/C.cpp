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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, s[kN], g[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		for(int i = 1; i <= n; ++i) s[i] = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			++s[x];
		}
		int max_s = 0, max_cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] > max_s) {
				max_s = s[i]; max_cnt = 1;
			} else if(s[i] == max_s) {
				++max_cnt;
			}
		}
		printf("%d\n", std::max((n - max_cnt) / (max_s - 1) - 1, 0));
	} return 0;
}