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
typedef std::pair <ll, int> pii;
const int N = 5e5 + 5, MAX = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

int n, k; ll a[N], b[N];

int cnt; ll tot, ans = INF;
std::priority_queue <pii, std::vector <pii>, std::greater <pii> > q;
void Check(ll mid) {
	while(!q.empty()) q.pop();
	cnt = tot = 0;
	for(int i = 1; i <= n; ++i) {
		q.push(mkp(a[i] - mid, 1));
		pii cur = q.top();
		ll v = b[i] + cur.fi;
		if(v <= 0) {
			tot += v; cnt += cur.se;
			q.pop(); q.push(mkp(-b[i], 0));
		}
	}
	ans = tot + k * mid;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) rd(b[i]);
		ll l = 0, r = MAX, x;
		while(l <= r) {
			ll mid = (l + r) >> 1;
			Check(mid);
			if(cnt > k) {
				r = mid - 1;
			} else l = mid + 1, x = mid;
		}
		Check(x);
		printf("%lld\n", ans);
	} return 0;
}