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

int n, k; ll A[kN], s[kN], p[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, k); ++k;
		for(int i = 1; i <= n; ++i) rd(A[i]);
		std::sort(A + 1, A + n + 1);
		for(int i = n; i; --i) {
			s[i] = s[i + 1] + A[i];
			p[i] = p[i + 1] + s[i];
		}
		//for(int i = 1; i <= n; ++i) printf("%d ", p[i]);
		//printf("\n");
		ll ans = -kInfLL, cur_s = 0; int cur_c = 0, cur_cnt = 0;
		for(int i = 1; i <= n; ++i) {
			cur_s += cur_c * A[i]; ++cur_cnt;
		//	printf("%lld %lld %lld\n", cur_s, s[i + 1], p[i + 1]);
			ans = std::max(ans, cur_s + p[i + 1] + cur_c * s[i + 1]);
			if(cur_cnt == k) {
				++cur_c; cur_cnt = 0;
			}
		}
		printf("%lld\n", ans);
	} return 0;
}