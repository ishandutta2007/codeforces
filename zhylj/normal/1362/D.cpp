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
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, t[kN], ct[kN], idx[kN], nb[kN], cnt = 0;
V <int> E[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			E[u].push_back(v); E[v].push_back(u);
		}
		for(int i = 1; i <= n; ++i) idx[i] = i, rd(t[i]);
		std::sort(idx + 1, idx + n + 1, [&](int a, int b) { return t[a] < t[b]; });
		bool flag = true;
		for(int i = 1; i <= n; ++i) {
			int v = idx[i];
			nb[cnt = 1] = 0;
			for(auto j : E[v]) if(ct[j]) nb[++cnt] = ct[j];
			std::sort(nb + 1, nb + cnt + 1);
			cnt = std::unique(nb + 1, nb + cnt + 1) - nb - 1;
			int mt = cnt;
		//	printf("%d: ", i);
			//for(auto j : nb) printf("%d ", nb[j]);
			for(int j = 2; j <= cnt; ++j) if(nb[j] != nb[j - 1] + 1) {
				mt = nb[j - 1] + 1; break;
			}
		//	printf(", fi: %d\n", mt);
			if(mt != t[v]) {
				flag = false;
				break;
			}
			ct[v] = t[v];
		}
		if(flag) for(int i = 1; i <= n; ++i) printf("%d ", idx[i]);
		else printf("-1");
	} return 0;
}