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

int n, st[N], top;
char str[N], ans[N], ansf[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n + 1; ++i)
			ans[i] = ansf[i] = 0;
		scanf("%s", str + 1);
		int cnt_0 = 0, tot_0 = 0;
		for(int i = 1; i <= n; ++i)
			if(str[i] == '0') ++tot_0;
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '0') {
				++cnt_0;
				ans[i] = cnt_0 % 2 ? '(' : ')';
			} if(str[i] == '1') {
				ans[i] = i - cnt_0 <= (n - tot_0) / 2 ? '(' : ')';
			}
		}
		int top_0 = 0, top_1 = 0;
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			if(str[i] == '0')
				ansf[i] = ans[i] == '(' ? ')' : '(';
			else ansf[i] = ans[i];
			if(ans[i] == '(') ++top_0;
			else --top_0;
			if(ansf[i] == '(') ++top_1;
			else --top_1;
			if(top_0 < 0) flag = false;
			if(top_1 < 0) flag = false;
		}
		if(top_0 != 0) flag = false;
		if(top_1 != 0) flag = false;
		if(flag) {
			printf("YES\n%s\n%s\n", ans + 1, ansf + 1);
		} else {
			printf("NO\n");
		}
	} return 0;
}