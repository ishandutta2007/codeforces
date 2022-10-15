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

int n, m, a[N], b[N], _b[N];
std::vector <int> buk[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); m = 0;
		for(int i = 1; i <= n; ++i) buk[i].clear();
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) rd(b[i]);
		for(int i = 1; i < n; ++i) {
			if(b[i] == b[i + 1]) {
				buk[b[i]].push_back(i);
			} else _b[++m] = i;
		}
		_b[++m] = n;
		_b[m + 1] = n + 1;
		for(int i = 1; i <= n; ++i)
			std::reverse(buk[i].begin(), buk[i].end());
		bool flag = true;
		for(int i = 1, j = 1; i <= n; ++i) {
			if(j <= m && a[i] == b[_b[j]] && (buk[a[i]].empty() || buk[a[i]].back() > _b[j + 1])) {
				++j;
			} else if(!buk[a[i]].empty()) {
				buk[a[i]].pop_back();
			} else {
				flag = false;
				break;
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}