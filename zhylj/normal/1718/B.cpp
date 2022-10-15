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
const int N = 100 + 5, M = 44;

int n, a[N], f[N], buk[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		ll tot = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			tot += a[i];
		}
		f[0] = f[1] = 1;
		for(int i = 2; i < M; ++i)
			f[i] = f[i - 1] + f[i - 2];
		int k = -1; ll cur_s = 0;
		for(int i = 0; i < M; ++i) {
			cur_s += f[i];
			if(cur_s == tot) k = i;
		}
		if(k == -1 || n > k + 1) {
			printf("No\n");
			continue;
		}
		bool tot_flag = false;
		for(int t = 1; t <= n; ++t) {
			memset(buk, 0, sizeof(buk));
			bool flag = true;
			--a[t];
			for(int i = 1; i <= n; ++i) {
				int x = a[i];
				for(int j = M - 1; j > (i == t ? 1 : 0); --j) {
					if(x >= f[j]) {
						if(j > k || buk[j]) {
							flag = false;
							break;
						}
						x -= f[j];
						++buk[j];
						--j;
					}
				}
				if(x > 0) flag = false;
				if(!flag) break;
			}
			for(int i = 1; i <= k; ++i)
				if(buk[i] != 1) flag = false;
			if(flag) tot_flag = true;
			++a[t];
		}
		printf(tot_flag ? "Yes\n" : "No\n");
	} return 0;
}