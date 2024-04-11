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
const int kN = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, ans[kN], x[kN], y[kN];
bool vis[kN];

ll Dis(int i, int j) {
	return 1LL * (x[i] - x[j]) * (x[i] - x[j]) + 1LL * (y[i] - y[j]) * (y[i] - y[j]);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(x[i], y[i]);
		}
		ans[1] = 1; vis[1] = true;
		for(int i = 1; i < n; ++i) {
			int p = ans[i]; ll p_d = 0;
			for(int j = 1; j <= n; ++j) if(!vis[j]) {
				ll n_d = Dis(ans[i], j);
				if(n_d > p_d) {
					p_d = n_d;
					p = j;
				}
			}
			vis[p] = true;
			ans[i + 1] = p;
		}
		for(int i = 1; i <= n; ++i)
			printf("%d ", ans[i]);
		printf("\n");
	} return 0;
}