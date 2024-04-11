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
const int N = 1e3 + 5;

struct Bit {
	ull f[N][N];
	void Modify(int x, int y, ull w) {
		for(int i = x; i < N; i += i & -i)
			for(int j = y; j < N; j += j & -j)
				f[i][j] ^= w;
	}
	ull Query(int x, int y) {
		ull ret = 0;
		for(int i = x; i > 0; i -= i & -i)
			for(int j = y; j > 0; j -= j & -j)
				ret ^= f[i][j];
		return ret;
	}
} t[2][2];

ull Query(int x, int y) {
	return t[0][0].Query(x, y) ^ t[0][1].Query(x, y) ^ t[1][0].Query(x, y) ^ t[1][1].Query(x, y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, m; rd(n, m);
		while(m--) {
			int opt, x_1, y_1, x_2, y_2; ull w;
			rd(opt, x_1, y_1, x_2, y_2);
			if(opt == 2) {
				rd(w);
				++x_2; ++y_2;
				t[x_2 & 1][y_2 & 1].Modify(x_2, y_2, w);
				t[x_1 & 1][y_2 & 1].Modify(x_1, y_2, w);
				t[x_2 & 1][y_1 & 1].Modify(x_2, y_1, w);
				t[x_1 & 1][y_1 & 1].Modify(x_1, y_1, w);
			} else if(opt == 1) {
				ull ans = 0;
				--x_1; --y_1;
				ans ^= t[x_2 & 1][y_2 & 1].Query(x_2, y_2);
				ans ^= t[x_2 & 1][y_1 & 1].Query(x_2, y_1);
				ans ^= t[x_1 & 1][y_2 & 1].Query(x_1, y_2);
				ans ^= t[x_1 & 1][y_1 & 1].Query(x_1, y_1);
				printf("%llu\n", ans);
			}
		}
	} return 0;
}