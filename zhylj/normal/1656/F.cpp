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
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n; ll a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1);
		ll k = 0, b = 0, mx = -INF;
		for(int i = 1; i < n; ++i) {
			k += a[i] + a[n];
			b += a[i] * a[n];
		}
		if(k < 0) mx = INF;
		else mx = std::max(mx, k * (-a[n - 1]) + b);
		for(int i = n - 1; i > 1; --i)  {
			k -= a[i] + a[n]; k += a[i] + a[1];
			b -= a[i] * a[n]; b += a[i] * a[1];
			mx = std::max(mx, k * (-a[i]) + b);
			mx = std::max(mx, k * (-a[i - 1]) + b);
		}
		if(k > 0) mx = INF;
		else mx = std::max(mx, k * (-a[2]) + b);
		if(mx != INF) printf("%lld\n", mx);
		else printf("INF\n");
	} return 0;
}