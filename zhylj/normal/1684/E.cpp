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

int buk[N], s[N], a[N], b[N], m, s_p;
std::priority_queue <int> p;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		m = s_p = 0;
		while(!p.empty()) p.pop();
		int n, k; rd(n, k);
		for(int i = 0; i <= n << 1; ++i) buk[i] = s[i] = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(a[i] >= n + 1) b[++m] = a[i];
		}
		std::sort(b + 1, b + m + 1);
		m = std::unique(b + 1, b + m + 1) - b - 1;
		for(int i = 1; i <= n; ++i) {
			if(a[i] >= n + 1)
				a[i] = n + std::lower_bound(b + 1, b + m + 1, a[i]) - b;
		}
		for(int i = 1; i <= n; ++i) {
			++buk[a[i]]; s[a[i]] = 1;
		}
		for(int i = 1; i <= n << 1; ++i) s[i] += s[i - 1];
		int ans = s[n << 1];
		for(int i = n << 1; i; --i) {
			if(i - s[i - 1] <= k) {
				int siz = p.size();
				ans = std::min(ans, std::max(s[n << 1] - siz - i + (i - s[i - 1]), 0));
			}
			if(buk[i]) {
				s_p += buk[i]; p.push(buk[i]);
				while(s_p > k) {
					s_p -= p.top();
					p.pop();
				}
			}
		}
		printf("%d\n", ans);
	} return 0;
}