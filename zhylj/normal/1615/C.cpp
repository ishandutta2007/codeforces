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
const int N = 5e5 + 5;

int n, a[N], b[N];
char a_str[N], b_str[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		scanf("%s%s", a_str + 1, b_str + 1);
		for(int i = 1; i <= n; ++i) {
			a[i] = a_str[i] - '0';
			b[i] = b_str[i] - '0';
		}
		a[n + 1] = b[n + 1] = 0;
		int cnt_a_0 = 0, cnt_a_1 = 0,
			cnt_b_0 = 0, cnt_b_1 = 0;
		for(int i = 1; i <= n + 1; ++i) {
			cnt_a_1 += a[i];
			cnt_b_1 += b[i];
		}
		cnt_a_0 = n + 1 - cnt_a_1;
		cnt_b_0 = n + 1 - cnt_b_1;
		int ans = n + 2;
		if(cnt_a_0 == cnt_b_0 && cnt_a_1 == cnt_b_1) {
			int cur_ans = 0;
			for(int i = 1; i <= n + 1; ++i)
				if(a[i] != b[i]) ++cur_ans;
			ans = std::min(ans, cur_ans);
		}
		if(cnt_a_0 == cnt_b_1 && cnt_a_1 == cnt_b_0) {
			for(int i = 1; i <= n + 1; ++i) a[i] ^= 1;
			int cur_ans = 0;
			for(int i = 1; i <= n + 1; ++i)
				if(a[i] != b[i]) ++cur_ans;
			--cur_ans;
			ans = std::min(ans, cur_ans);
		}
		printf("%d\n", ans == n + 2 ? -1 : ans);
	} return 0;
}