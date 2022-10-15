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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;
const ff kEps = 1e-5;

int n, idx[kN]; ll k, A[kN], B[kN], d[kN];

bool Check(ll mid) {
	ll t = 0;
	for(int i = 1; i <= n; ++i) {
		ll x = sqrt(std::max(A[i] / 3.0 + mid, kEps));
		t += std::min(x, A[i]);
	}
	return t >= k;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i)
			rd(A[i]);
		ll l = -1e18, r = 1e18;
		while(l < r) {
			ll mid = (l + r + 1) >> 1;
			if(Check(mid)) r = mid - 1;
			else l = mid;
		}
		ll s = 0;
		for(int i = 1; i <= n; ++i) {
			B[i] = sqrt(std::max(A[i] / 3.0 + l, kEps));
			B[i] = std::min(B[i], A[i]);
			if(B[i] < A[i]) {
				d[i] = -3 * (B[i] * B[i] + B[i]) + A[i];
			} else d[i] = -kInfLL;
			s += B[i];
			idx[i] = i;
		}
		std::sort(idx + 1, idx + n + 1, [](const int &x, const int &y) {
			return d[x] > d[y];
		});
		for(int i = 1; i <= k - s; ++i) ++B[idx[i]];
		for(int i = 1; i <= n; ++i) printf("%lld ", B[i]);
		printf("\n");
	} return 0;
}