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
const int kN = 1e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int x, n, pos, vis[kN];
ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}
ll fac[kN], fac_inv[kN];
void Init() {
	fac[0] = 1;
	for(int i = 1; i < kN; ++i) fac[i] = fac[i - 1] * i % kMod;
	fac_inv[kN - 1] = QPow(fac[kN - 1], kMod - 2);
	for(int i = kN - 2; ~i; --i) fac_inv[i] = fac_inv[i + 1] * (i + 1) % kMod;
}
ll C(int x, int y) {
	if(x < y) return 0;
	return fac[x] * fac_inv[y] % kMod * fac_inv[x - y] % kMod;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, x, pos); Init();
		int l = 0, r = n, cnt_g = 0, cnt_l = 0;
		while(l < r) {
			int mid = (l + r) >> 1;
		//	printf("%d %d %d\n", l, r, mid);
			if(pos + 1 <= mid) {
				r = mid;
				if(!vis[mid]) ++cnt_g, vis[mid] = 1;
				else if(vis[mid] == -1) return printf("0\n"), 0;
			} else if(pos == mid) l = mid + 1;
			else if(pos + 1 > mid) {
				l = mid + 1;
				if(!vis[mid]) ++cnt_l, vis[mid] = -1;
				else if(vis[mid] == 1) return printf("0\n"), 0;
			}
		}
		//printf("%lld %lld %lld\n", fac[n - cnt - 1], fac[cnt], C(n - x, cnt));
		//printf("%d %d\n", cnt_l, cnt_g);
		//printf("%lld %lld %lld %lld %lld\n", fac[n - cnt_l - cnt_g - 1], fac[cnt_l],
		//				fac[cnt_g], C(n - x, cnt_g), C(x - 1, cnt_l));
		printf("%lld\n", fac[n - cnt_l - cnt_g - 1] * fac[cnt_l] % kMod *
						fac[cnt_g] % kMod * C(n - x, cnt_g) % kMod * C(x - 1, cnt_l) % kMod);
	} return 0;
}