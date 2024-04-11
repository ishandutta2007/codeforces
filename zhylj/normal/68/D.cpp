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

int h, q;
ff ans;
std::map <int, int> s, v;
void Dfs(int u, int mx, ff p) {
	if(mx >= s[u]) {
		ans += p * mx;
		return;
	}
	Dfs(u << 1, std::max(mx, s[u << 1 | 1] + v[u]), p / 2);
	Dfs(u << 1 | 1, std::max(mx, s[u << 1] + v[u]), p / 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(h, q);
		while(q--) {
			char str[5]; scanf("%s", str);
			if(str[0] == 'a') {
				int x, e; rd(x, e);
				v[x] += e;
				for(; x; x >>= 1) s[x] += e;
			} else {
				ans = 0; Dfs(1, v[1], 1);
				printf("%.10lf\n", ans);
			}
		}
	} return 0;
}