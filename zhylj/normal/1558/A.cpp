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

int a, b;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(a, b);
		if(a < b) std::swap(a, b);
		std::vector <int> ans;
		if((a + b) % 2 == 0) {
			for(int i = abs(a - b) / 2; i <= 2 * b + (a - b) / 2; i += 2)
				ans.push_back(i);
		} else {
			for(int i = abs(a - b) / 2; i <= 2 * b + (a - b) / 2 + 1; ++i)
				ans.push_back(i);
		}
		printf("%d\n", ans.size());
		for(auto i : ans)
			printf("%d ", i);
		printf("\n");
	} return 0;
}