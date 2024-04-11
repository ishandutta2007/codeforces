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

int n, p[kN], f_L[kN], f_R[kN], g_L[kN], g_R[kN], f[kN], g[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(p[i]);
		for(int i = 2; i <= n; ++i) {
			if(p[i - 1] < p[i]) f_L[i] = f_L[i - 1] + 1;
			if(p[i - 1] > p[i]) g_L[i] = g_L[i - 1] + 1;
		}
		for(int i = n - 1; i; --i) {
			if(p[i + 1] < p[i]) f_R[i] = f_R[i + 1] + 1;
			if(p[i + 1] > p[i]) g_R[i] = g_R[i + 1] + 1;
		}
		int ans = 0, mx = 0, cnt = 0;
		for(int i = 1; i <= n; ++i) {
			f[i] = std::max(f_L[i], f_R[i]);
			g[i] = std::max(g_L[i], g_R[i]);
			mx = std::max(mx, g[i]);
		}
		for(int i = 1; i <= n; ++i) {
			if(mx == f[i]) ++cnt;
		}
		for(int i = 1; i <= n; ++i) {
			int L = f_L[i], R = f_R[i];
			if(L > R) std::swap(L, R);
			if(R % 2 == 0) --R;
			if(f[i] == mx && L > R) ++ans;
		}
		printf("%d\n", cnt > 1 ? 0 : ans);
	} return 0;
}