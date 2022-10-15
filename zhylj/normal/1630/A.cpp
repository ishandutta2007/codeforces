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

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, k; rd(n, k);
		int U = n - 1;
		if(k == U && n == 4) printf("-1\n");
		else if(k == U) {
			printf("%d %d\n", U, U - 1);
			printf("%d %d\n", 1, 3);
			for(int i = 2; i < U - 1; ++i) {
				if(i == 3) continue;
				if((U ^ i) == 3)
					printf("%d %d\n", 0, i);
				else if(i < (U ^ i))
					printf("%d %d\n", i, U ^ i);
			}
		} else if(k == 0) {
			for(int i = 0; i <= U; ++i)
				if(i < (U ^ i)) printf("%d %d\n", i, U ^ i);
		} else {
			printf("%d %d\n", k, U);
			printf("%d %d\n", 0, U ^ k);
			for(int i = 1; i < U; ++i)
				if(i != k && i != (U ^ k) && i < (U ^ i))
					printf("%d %d\n", i, U ^ i);
		}
	} return 0;
}