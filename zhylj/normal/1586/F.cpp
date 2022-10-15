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

int n, k, c_mx, gra[N][N];
void Color(int l, int r, int c) {
	c_mx = std::max(c_mx, c);
	if(r - l < k) {
		for(int i = l; i <= r; ++i)
			for(int j = i + 1; j <= r; ++j)
				gra[i][j] = c;
		return;
	}
	int b = (r - l) / k + 1;
	for(int i = l; i <= r; ++i)
		for(int j = i + 1; j <= r; ++j)
			if((i - l) / b != (j - l) / b) gra[i][j] = c;
	for(int i = l; i <= r; i += b)
		Color(i, std::min(i + b - 1, r), c + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		Color(1, n, 1);
		printf("%d\n", c_mx);
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j)
				printf("%d ", gra[i][j]);
		printf("\n");
	} return 0;
}