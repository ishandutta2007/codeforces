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

int n, k, a[kN], s[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(a[i] > k) a[i] = 2;
			else if(a[i] == k) a[i] = 1;
			else a[i] = 0;
		}
		if(n == 1 && a[1] == 1) { printf("yes\n"); continue; }
		bool flg1 = false, flg2 = false;
		for(int i = 1; i <= n; ++i) if(a[i] == 1) flg1 = true;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= std::min(i + 2, n); ++j)
				if(a[j] >= 1 && a[i] >= 1) flg2 = true;
		}
		printf(flg1 && flg2 ? "yes\n" : "no\n");
	} return 0;
}