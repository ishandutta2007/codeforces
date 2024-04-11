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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, s[kN], A[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		int ans = kInf;
		rd(n);
		for(int i = 1; i <= n; ++i) rd(A[i]), s[i] = s[i - 1] ^ A[i];
		if(n >= 100) {
			printf("%d\n", 1);
		} else {
			for(int i = 1; i < n; ++i) {
				for(int j = 1; j <= i; ++j)
					for(int k = i + 1; k <= n; ++k)
						if((s[i] ^ s[j - 1]) > (s[k] ^ s[i])) {
							ans = std::min(ans, k - j - 1);
						}
			}
			printf("%d\n", ans == kInf ? -1 : ans);
		}
	} return 0;
}