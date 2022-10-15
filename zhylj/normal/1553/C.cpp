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
const int N = 10 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

char s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s", s);
		int ans = 10;
		for(int S = 0; S < 1 << 10; ++S) {
			int a_s = 0, b_s = 0, cnt_a = 0, cnt_b = 0;
			for(int i = 0; i < 10; ++i) {
				int c = s[i] != '?' ? s[i] - '0' : (S >> i) & 1;
				if(i & 1) b_s += c, ++cnt_b;
				else a_s += c, ++cnt_a;
				if(b_s + 5 - cnt_b < a_s) {
					ans = std::min(ans, i + 1);
					break;
				} else if(a_s + 5 - cnt_a < b_s) {
					ans = std::min(ans, i + 1);
					break;
				}
			}
		}
		printf("%d\n", ans);
	} return 0;
}