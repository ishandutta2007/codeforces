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
const int N = 5e5 + 5, MAX = 1e9;

int n, cnt;
std::map <pii, ll> vis;
ll Ask(int l, int r) {
	if(vis.count(mkp(l, r))) return vis[mkp(l, r)];
	++cnt;
	if(cnt > 40) {
		printf("FUCK\n");
		exit(0);
	}
	printf("? %d %d\n", l, r);
	fflush(stdout);
	ll ret; rd(ret);
	return vis[mkp(l, r)] = ret;
}

ll FindKth(ll x) {
	int l = 1, r = MAX;
	while(l < r) {
		int mid = (l + r) >> 1;
		ll t = 1LL * mid * (mid - 1) / 2;
		//printf("%d %d\n", l, r);
		if(t == x) return mid;
		if(t < x) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
ll Check(int x) { return 1LL * x * (x - 1) / 2; }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); cnt = 0;
		vis.clear();
		int l = 3, r = n - 1, left_len = 0, right_len = 0;
		while(l < r) {
			int mid = (l + r) >> 1;
			ll x = Ask(1, mid);
			if(Check(FindKth(x)) == x) {
				int tmp = FindKth(x);
				if(mid - tmp + 1 <= 0 || Ask(1, mid - tmp + 1)) {
				//	printf("A\n");
					r = mid;
				} else {
				//	printf("B\n");
					l = mid + 1;
				}
			} else {
				//printf("C\n");
				r = mid;
			}
		}
		//printf("====\n");
		left_len = FindKth(Ask(1, l - 1));
		right_len = FindKth(Ask(l, n));
		printf("! %d %d %d\n", l - left_len, l, l + right_len - 1);
		fflush(stdout);
	} return 0;
}