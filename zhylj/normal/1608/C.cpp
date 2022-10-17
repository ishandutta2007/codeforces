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

int n, a[N], b[N], ans[N];
std::priority_queue <pii> p, q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		while(!p.empty()) p.pop();
		while(!q.empty()) q.pop();
		rd(n);
		for(int i = 1; i <= n; ++i) ans[i] = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]), p.push(mkp(a[i], i));
		for(int i = 1; i <= n; ++i) rd(b[i]), q.push(mkp(b[i], i));
		int a_mn = p.top().fi, b_mn = q.top().fi;
		while(!p.empty() || !q.empty()) {
			bool flag = false;
			if(!p.empty() && p.top().fi >= a_mn) {
				int i = p.top().se; p.pop();
				ans[i] = 1;
				b_mn = std::min(b_mn, b[i]);
				flag = true;
			}
			if(!q.empty() && q.top().fi >= b_mn) {
				int i = q.top().se; q.pop();
				ans[i] = 1;
				a_mn = std::min(a_mn, a[i]);
				flag = true;
			}
			if(!flag) break;
		}
		for(int i = 1; i <= n; ++i)
			printf("%d", ans[i]);
		printf("\n");
	} return 0;
}