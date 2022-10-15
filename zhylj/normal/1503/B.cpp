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
const int N = 1e2 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, cnt;
std::vector <pii> res_1, res_2;

void Get(int c, pii a) {
	printf("%d %d %d\n", c, a.fi, a.se);
	fflush(stdout);
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int c; rd(n);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j) {
				if((i + j) % 2 == 0) res_1.push_back(mkp(i, j));
				else res_2.push_back(mkp(i, j));
			}
		for(int i = 1; i <= n * n; ++i) {
			rd(c);
			if(!res_1.empty() && !res_2.empty()) {
				if(c == 1) {
					Get(2, res_1.back());
					res_1.pop_back();
				} else {
					Get(1, res_2.back());
					res_2.pop_back();
				}
			} else if(!res_1.empty()) {
				if(c == 3) {
					Get(2, res_1.back());
					res_1.pop_back();
				} else {
					Get(3, res_1.back());
					res_1.pop_back();
				}
			} else {
				if(c == 3) {
					Get(1, res_2.back());
					res_2.pop_back();
				} else {
					Get(3, res_2.back());
					res_2.pop_back();
				}
			}
		}
	} return 0;
}