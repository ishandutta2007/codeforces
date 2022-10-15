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

int n, idx[kN]; ll s[kN], ans[kN], w;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, w);
		for(int i = 1; i <= n; ++i) rd(s[i]), idx[i] = i;
		std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
			return s[x] > s[y];
		});
		int cnt = 0; ll cur_w = 0;
		for(int i = 1; i <= n; ++i) {
			ll v = s[idx[i]];
			if(cur_w + v <= w) {
				cur_w += v;
				ans[++cnt] = idx[i];
			}
		}
		if(cur_w >= (w + 1) / 2) {
			printf("%d\n", cnt);
			for(int i = 1; i <= cnt; ++i) printf("%lld ", ans[i]);
			printf("\n");
		} else {
			printf("-1\n");
		}
	} return 0;
}