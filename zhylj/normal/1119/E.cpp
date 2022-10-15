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
const int N = 3e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, a[N], b[N];
bool Check(ll k) {
	memcpy(b, a, sizeof(b));
	ll s = 0;
	for(int i = n; i; --i) {
		if(b[i] / 2 <= k) {
			k -= b[i] / 2;
			s += b[i] / 2;
			b[i] %= 2;
		} else if(k) {
			b[i] -= k * 2;
			s += k;
			k = 0;
		}
		s -= b[i]; b[i] = 0;
		s = std::max(s, 0LL);
	}
	return !s && !k;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i)
			rd(a[i]);
		ll l = 0, r = 1e15;
		while(l < r) {
			ll mid = (l + r + 1) >> 1;
			if(Check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%lld\n", l);
	} return 0;
}