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

int n, c[N], s[N], d[N], ds[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(c[i]);
		for(int i = 1; i <= n; ++i) rd(s[i]);
		if(c[1] != s[1] || c[n] != s[n]) printf("No\n");
		else {
			bool flag = true;
			for(int i = 1; i < n; ++i) {
				d[i] = c[i + 1] - c[i];
				ds[i] = s[i + 1] - s[i];
			}
			std::sort(d + 1, d + n);
			std::sort(ds + 1, ds + n);
			for(int i = 1; i < n; ++i) {
				if(d[i] != ds[i]) {
					printf("No\n");
					flag = false; break;
				}
			}
			if(flag) {
				printf("Yes\n");
			}
		}
	} return 0;
}