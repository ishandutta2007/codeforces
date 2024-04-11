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
typedef std::pair <ll, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, k; ll p, h[kN], a[kN], t[kN];
std::priority_queue <pii, std::vector<pii>, std::greater<pii> > pq;
bool Check(ll H) {
	while(!pq.empty()) pq.pop();
	for(int i = 1; i <= n; ++i)
		if((t[i] = H) - m * a[i] < h[i]) pq.push(mkp(H / a[i], i));
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(pq.empty()) return true;
			int o = pq.top().se; pq.pop();
			if(t[o] - i * a[o] < 0) return false;
			if((t[o] += p) - m * a[o] < h[o]) pq.push(mkp(t[o] / a[o], o));
		}
	}
	return pq.empty();
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m, k, p);
		for(int i = 1; i <= n; ++i) {
			rd(h[i], a[i]);
		}
		ll l = 0, r = 1e15;
		while(l < r) {
			ll mid = (l + r) >> 1;
			if(Check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%lld\n", l);
	} return 0;
}