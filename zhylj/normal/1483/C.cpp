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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int h[N], b[N], st[N], top, n;
ll f[N], mx[N], mx_h[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(f, ~0x3f, sizeof(f));
		memset(mx, ~0x3f, sizeof(mx));
		memset(mx_h, ~0x3f, sizeof(mx_h));
		f[0] = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) rd(h[i]);
		for(int i = 1; i <= n; ++i) rd(b[i]);
		for(int i = 1; i <= n; ++i) {
			ll n_mx = -InfLL;
			while(top > 0 && h[st[top]] > h[i]) {
				n_mx = std::max(n_mx, mx[top]);
				--top;
			}
			st[++top] = i; mx[top] = n_mx;
			mx[top] = std::max(mx[top], f[i - 1]);
			mx_h[top] = std::max(mx_h[top - 1], mx[top] + b[i]);
			f[i] = mx_h[top];
		}
		printf("%lld\n", f[n]);
	} return 0;
}