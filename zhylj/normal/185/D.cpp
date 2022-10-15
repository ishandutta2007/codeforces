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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int QPow(int a, ll b, int p) {
	int ret = 1, bas = a % p;
	for(; b; b >>= 1, bas = 1LL * bas * bas % p)
		if(b & 1) ret = 1LL * ret * bas % p;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		ll k, l, r, p, pw_cnt = 0, mx_cnt = 0, ans = 1, tmp_k;
		rd(k, l, r, p);
		if(p == 2) printf("%lld\n", ~k & 1);
		else if(l == r) {
			printf("%lld\n", k % p ? (QPow(k, QPow(2, l, p - 1), p) + 1) % p : 1);
		} else {
			tmp_k = k + 1;
			if(k & 1) pw_cnt += r - std::max(l, 1LL) + 1, mx_cnt = 1;
			if(!l) {
				ll f_cnt = 0;
				while(~tmp_k & 1) tmp_k /= 2, ++pw_cnt, ++f_cnt;
				mx_cnt = std::max(mx_cnt, f_cnt);
				++l;
				ans = 1LL * ans * (k + 1) % p;
			}
			ll t = k % p ? QPow(k, QPow(2, l, p - 1), p) : 0;
			if(t > 1) {
				ans = 1LL * ans * (QPow(t, QPow(2, r - l + 1, p - 1), p) - 1 + p) % p * 
					QPow(t - 1, p - 2, p) % p;
			} else ans = 1LL * QPow(t + 1, r - l + 1, p) % p * ans % p;
			ans = 1LL * ans * QPow(2, 1LL * (p - 2) % (p - 1) * (pw_cnt % (p - 1)), p) % p;
			ans = 1LL * ans * QPow(2, mx_cnt, p) % p;
			printf("%lld\n", ans);
		}
	} return 0;
}