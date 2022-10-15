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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[kN], b[kN], ans = 0;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		std::sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; ++i) {
			if(i % 2 == 0) b[i] = a[i / 2];
			else b[i] = a[n / 2 + i / 2 + 1];
		}
		for(int i = 2; i < n; ++i)
			if(b[i] < b[i - 1] && b[i] < b[i + 1]) ++ans;
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i) printf("%d ", b[i]);
		printf("\n");
	} return 0;
}