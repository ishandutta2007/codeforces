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
const int N = 1e3 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

char s[N], t[N], t0[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s%s", s + 1, t + 1);
		int n = strlen(s + 1), m = strlen(t + 1);
		bool flag_1 = false;
		for(int i = 1; i <= m; ++i) {
			bool flag_2 = true;
			for(int j = i + 1; j <= m && i - (j - i) >= 1; ++j)
				if(t[j] != t[i - (j - i)]) {
					flag_2 = false;
					break;
				}
			if(!flag_2) continue;
			int len = std::max(i - 1, m - i) + 1;
			if(i - 1 >= m - i) {
				for(int j = 1; j <= len; ++j)
					t0[j] = t[j];
			} else {
				for(int j = 1; j <= len; ++j)
					t0[j] = t[i + j - 1];
				std::reverse(t0 + 1, t0 + len + 1);
			}
			for(int j = 1; j + len - 1 <= n; ++j) {
				bool flag_3 = true;
				for(int k = 1; k <= len; ++k)
					if(s[j + k - 1] != t0[k]) {
						flag_3 = false;
						break;
					}
				if(flag_3) {
					flag_1 = true;
					break;
				}
			}
			if(flag_1) break;
		}
		printf(flag_1 ? "YES\n" : "NO\n");
	} return 0;
}