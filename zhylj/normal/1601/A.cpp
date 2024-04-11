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

int n, a[N], cnt[50];

int Gcd(int a, int b) {
	return b ? Gcd(b, a % b) : a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < 30; ++j)
				if((a[i] >> j) & 1) ++cnt[j];
		}
		int g = 0;
		for(int i = 0; i < 30; ++i)
			g = Gcd(g, cnt[i]);
		for(int i = 1; i <= n; ++i)
			if(g % i == 0)
				printf("%d ", i);
		printf("\n");
	} return 0;
}