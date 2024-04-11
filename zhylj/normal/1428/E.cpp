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
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <ull, int> pii;
const int kN = 1e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, A[kN], cnt[kN];
std::priority_queue <pii> pq;

inline ull Sq(int x) { return 1ULL * x * x; }
ull Calc(int x, int k) {
	++k;
	return x % k * Sq(x / k + 1) + (k - x % k) * Sq(x / k);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(n, m); m -= n;
	while(T--) {
		while(!pq.empty()) pq.pop();
		for(int i = 1; i <= n; ++i) {
			rd(A[i]); cnt[i] = 0;
			pq.push(mkp(Sq(A[i]) - Calc(A[i], 1), i));
		}
		for(int i = 1; i <= m; ++i) {
			pii u = pq.top(); pq.pop();
			int x = u.se; ++cnt[x];
			pq.push(mkp(Calc(A[x], cnt[x]) - Calc(A[x], cnt[x] + 1), x));
		}
		ull ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans += Calc(A[i], cnt[i]);
		}
		printf("%llu\n", ans);
	} return 0;
}