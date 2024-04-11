#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2.2e6 + 5, M = 21, INF = 0x3f3f3f3f;

int n, m, s[N], f[N], g[N];
char str[N], str_up[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		memset(f, 0, sizeof(f));
		memset(s, 0, sizeof(s));
		for(int i = 1; i <= n; ++i) {
			scanf("%s", str + 1);
			for(int j = 0; j <= m; ++j)
				g[j] = INF;
			if(str[1] != 'X') g[1] = 1;
			for(int j = 2; j <= m; ++j) {
				if(str[j - 1] != 'X') g[j] = std::min(g[j], g[j - 1]);
				if(str_up[j] != 'X') g[j] = std::min(g[j], f[j]);
				g[j] = std::min(g[j], j);
				s[j] = std::max(s[j], g[j]);
			}
			for(int j = 1; j <= m; ++j)
				f[j] = g[j], str_up[j] = str[j];
		}
		for(int i = 1; i <= m; ++i)
			s[i] = std::max(s[i - 1], s[i]);
		int q; rd(q);
		while(q--) {
			int u, v; rd(u, v);
			if(s[v] > u) printf("NO\n");
			else printf("YES\n");
		}
	} return 0;
}