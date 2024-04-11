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
const int N = 3e3 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		bool flag = true;
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(a[i] % 2 != i % 2) flag = false;
		}
		if(!flag) {
			printf("-1\n");
			continue;
		}
		std::vector <int> ans;
		for(int i = n; i > 1; i -= 2) {
			int pos;
			for(int j = 1; j <= n; ++j)
				if(a[j] == i) pos = j;
			ans.push_back(pos);
			std::reverse(a + 1, a + pos + 1);
			for(int j = 1; j <= n; ++j)
				if(a[j] == i - 1) pos = j;
			--pos;
			ans.push_back(pos);
			std::reverse(a + 1, a + pos + 1);
			for(int j = 1; j <= n; ++j)
				if(a[j] == i - 1) pos = j;
			++pos;
			ans.push_back(pos);
			std::reverse(a + 1, a + pos + 1);
			for(int j = 1; j <= n; ++j)
				if(a[j] == i) pos = j;
			ans.push_back(pos);
			std::reverse(a + 1, a + pos + 1);
			ans.push_back(i);
			std::reverse(a + 1, a + i + 1);
		}
		printf("%d\n", ans.size());
		for(auto i : ans)
			printf("%d ", i);
		printf("\n");
	} return 0;
}