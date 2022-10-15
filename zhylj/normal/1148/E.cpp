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
#define mkt std::make_tuple
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;

int n, s[N], t[N], mov[N], s_idx[N];
std::vector <std::tuple <int, int, int> > ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(s[i]), s_idx[i] = i;
		for(int i = 1; i <= n; ++i) rd(t[i]);
		std::sort(s_idx + 1, s_idx + n + 1, [&](const int &x, const int &y) { return s[x] < s[y]; });
		std::sort(t + 1, t + n + 1);
		for(int i = 1; i <= n; ++i) mov[i] = t[i] - s[s_idx[i]];
		bool flag = true;
		for(int i = 1, j = 1; i <= n, j <= n; ) {
			for(; i <= n && mov[i] <= 0; ++i);
			for(; j <= n && mov[j] >= 0; ++j);
			if(i > n || j > n) break;
			if(j < i) { flag = false; break; }
			int d = std::min(mov[i], -mov[j]);
			mov[i] -= d; mov[j] += d;
			ans.push_back(mkt(s_idx[i], s_idx[j], d));
		}
		for(int i = 1; i <= n; ++i)
			if(mov[i]) flag = false;
		if(flag) {
			printf("YES\n%d\n", (int)ans.size());
			for(int i = 0; i < ans.size(); ++i) {
				auto t = ans[i];
				printf("%d %d %d\n", std::get<0>(t), std::get<1>(t), std::get<2>(t));
			}
		} else printf("NO\n");
	} return 0;
}