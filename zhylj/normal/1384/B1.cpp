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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, k, lm, l[kN], r[kN], lx[kN], rx[kN], d[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n, k, lm);
		for(int i = 1; i <= n; ++i) rd(d[i]);
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			if(lm - d[i] < 0) {
				flag = false; break;
			}
			lx[i] = std::max(k - (lm - d[i]) + 1, 1);
			rx[i] = std::min(k + (lm - d[i]) + 1, 2 * k);
			//printf("[%d, %d]\n", lx[i], rx[i]);
		}
		//printf("\n");
		l[0] = 1; r[0] = 2 * k;
		for(int i = 1; i <= n; ++i) {
			l[i] = l[i - 1] % (2 * k) + 1; r[i] = r[i - 1] % (2 * k) + 1;
			if(lx[i] == 1) {
				l[i] = 1, r[i] = 2 * k; continue;
			}
			if(r[i] == 1) {
				if(l[i] != 1) r[i] = 2 * k;
				else { flag = false; break; }
			}
			if(l[i] > rx[i] || r[i] < lx[i]) { flag = false; break; }
			l[i] = std::max(l[i], lx[i]); r[i] = std::min(r[i], rx[i]);
			if(rx[i] <= 2 * k) r[i] = std::max(r[i], rx[i]);
			//printf("[%d, %d]\n", l[i], r[i]);
		}
		printf(flag ? "Yes\n" : "No\n");
	} return 0;
}