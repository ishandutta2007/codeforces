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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll n, x, y, s[kN][3]; char str[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		scanf("%s", str + 1);
		n = strlen(str + 1);
		rd(x, y);
		ll cur_ans = 0, ans;
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '0') ++s[i][0];
			if(str[i] == '1') ++s[i][1];
			if(str[i] == '?') ++s[i][2];
		}
		for(int i = 1; i <= n; ++i) {
			s[i][0] += s[i - 1][0];
			s[i][1] += s[i - 1][1];
			s[i][2] += s[i - 1][2];
		}
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '?' || str[i] == '1')
				cur_ans += x * s[i][0];
			if(str[i] == '0') cur_ans += y * (s[i][1] + s[i][2]);
		}
		ans = cur_ans;
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '?') {
				cur_ans += y * s[i][1] - x * (s[i][0] + s[i - 1][2]);
				cur_ans -= y * (s[n][0] - s[i][0]);
				cur_ans += x * (s[n][1] - s[i][1]) + x * (s[n][2] - s[i][2]);
			}
			ans = std::min(ans, cur_ans);
		}
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '?') {
				cur_ans += x * s[i][0] - y * (s[i][1] + s[i - 1][2]);
				cur_ans += y * (s[n][0] - s[i][0]) + y * (s[n][2] - s[i][2]);
				cur_ans -= x * (s[n][1] - s[i][1]);
			}
			ans = std::min(ans, cur_ans);
		}
		printf("%lld\n", ans);
	} return 0;
}