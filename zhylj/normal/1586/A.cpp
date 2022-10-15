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
const int N = 1e5 + 5;

bool Check(int x) {
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) return true;
	return false;
}

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		int s = 0;
		for(int i = 1; i <= n; ++i) rd(a[i]), s += a[i];
		if(Check(s)) {
			printf("%d\n", n);
			for(int i = 1; i <= n; ++i)
				printf("%d ", i);
			printf("\n");
		} else {
			printf("%d\n", n - 1);
			for(int i = 1; i <= n; ++i)
				if(Check(s - a[i])) {
					for(int j = 1; j <= n; ++j)
						if(i != j) printf("%d ", j);
					printf("\n");
					break;
				}
		}
	} return 0;
}