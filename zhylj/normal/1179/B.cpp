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
const int N = 1e6 + 5;

int n, m, r[N], c[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n / 2; ++i)
			r[i * 2 - 1] = i, r[i * 2] = n - i + 1;
		if(n % 2 == 1) r[n] = (n + 1) / 2;
		for(int i = 1; i <= m / 2; ++i)
			c[i * 2 - 1] = i, c[i * 2] = m - i + 1;
		if(m % 2 == 1) c[m] = (m + 1) / 2;
		for(int i = 1; i + 1 <= n; i += 2) {
			for(int j = 1; j + 1 <= m; j += 2)
				printf("%d %d\n%d %d\n", r[i], c[j], r[i + 1], c[j + 1]);
			if(m % 2 == 1) printf("%d %d\n", r[i], c[m]);
			if(m % 2 == 0) {
				for(int j = m; j - 1 > 0; j -= 2)
					printf("%d %d\n%d %d\n", r[i], c[j], r[i + 1], c[j - 1]);
			} else {
				for(int j = m; j - 1 > 0; j -= 2)
					printf("%d %d\n%d %d\n", r[i + 1], c[j], r[i], c[j - 1]);
				printf("%d %d\n", r[i + 1], c[1]);
			}
		}
		if(n % 2 == 1) {
			for(int j = 1; j <= m; ++j)
				printf("%d %d\n", r[n], c[j]);
		}
	} return 0;
}