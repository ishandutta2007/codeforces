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

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		std::set <int> s;
		for(int i = 0; i < n; ++i) {
			rd(a[i]);
			if(a[i]) s.insert(a[i]);
		}
		bool flag = true;
		for(int i = 0; i < n; ++i) rd(b[i]);
		for(int i = 0; i < n; ++i)
			if(b[i] != i + 1) flag = false;
		if(flag) {
			printf("0\n");
			return 0;
		}
		std::deque <int> q;
		for(int i = 0; i < n; ++i)
			q.push_back(b[i]);
		int cnt = 0, ans = 2 * n;
		while(true) {
			++cnt;
			if(s.count(q.back() + 1)) {
				q.push_back(q.back() + 1);
				if(q.back() == n) {
					q.pop_front();
					for(int i = 0; i < n; ++i)
						if(q[i] != i + 1) cnt = 2 * n;
					break;
				}
			} else { cnt = 2 * n; break; }
			s.insert(q.front()); q.pop_front();
		}
		ans = std::min(ans, cnt);
		int mx_mov = 0;
		for(int i = 0; i < n; ++i) if(b[i]) {
			mx_mov = std::max(mx_mov, i + 1 - b[i] + 1);
		}
		ans = std::min(ans, mx_mov + n);
		printf("%d\n", ans);
	} return 0;
}