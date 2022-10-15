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
const int N = 2e5 + 5;

std::vector <int> a[N];
int idx[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, m; rd(n, m);
		for(int i = 1; i <= n; ++i) a[i].clear();
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				int x; rd(x);
				a[i].push_back(x);
			}
		}
		for(int i = 0; i < m; ++i) idx[i] = i;
		auto cmp = [&](const int &x, const int &y) {
			for(int i = 1; i <= n; ++i)
				if(a[i][x] != a[i][y]) return a[i][x] < a[i][y];
			return false;
		};
		std::stable_sort(idx, idx + m, cmp);
		bool flag = true;
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < m - 1; ++j)
				if(a[i][idx[j]] > a[i][idx[j + 1]]) flag = false;
		int cnt = 0, p_x = 0, p_y = 0;
		for(int i = 0; i < m; ++i) {
			bool flag_2 = true;
			for(int j = 1; j <= n; ++j)
				if(a[j][idx[i]] != a[j][i]) flag_2 = false;
			if(!flag_2) {
				++cnt;
				if(cnt == 1) p_x = i;
				if(cnt == 2) p_y = i;
			}
		}
		if(!flag || (cnt != 0 && cnt != 2)) printf("-1\n");
		else if(!cnt) printf("1 1\n");
		else printf("%d %d\n", p_x + 1, p_y + 1);
	} return 0;
}