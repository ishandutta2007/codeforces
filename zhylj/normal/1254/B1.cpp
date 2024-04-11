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
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n; ll s[kN];

ll Check(ll p) {
	ll cur_ans = 0;
	for(int j = 1; j < n; ++j)
		cur_ans += std::min(s[j] % p, p - s[j] % p);
	return cur_ans;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(s[i]), s[i] += s[i - 1];
		ll ans = kInfLL;
		for(ll i = 2; i * i <= s[n]; ++i) if(s[n] % i == 0) {
			ans = std::min(ans, Check(i));
			while(s[n] % i == 0) s[n] /= i;
		}
		if(s[n] > 1) ans = std::min(ans, Check(s[n]));
		if(ans == kInfLL) printf("-1\n");
		else printf("%lld\n", ans);
	} return 0;
}