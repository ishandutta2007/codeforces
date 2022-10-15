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
const int kN = 3e2 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m; char g[kN][kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		memset(g, 0, sizeof(g));
		rd(n);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", g[i] + 1);
		}
		int p = 0, p_cnt = kInf;
		for(int i = 0; i < 3; ++i) {
			int cur_cnt = 0;
			for(int j = 1; j <= n; ++j) 
				for(int k = 1; k <= n; ++k)
					if(g[j][k] == 'X' && (j + k) % 3 == i) {
						++cur_cnt;
					}
			if(cur_cnt <= p_cnt) p_cnt = cur_cnt, p = i;
		}
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				if(g[j][k] == 'X') {
					putchar((j + k) % 3 == p ? 'O' : 'X');
				} else putchar('.');
			}
			putchar('\n');
		}
	} return 0;
}