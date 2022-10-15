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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, tot = 0; ll p[kN], siz[kN]; std::vector <int> E[kN];
void Add(int u, int v) { E[u].push_back(v); }

ll Dfs(int u, int fa) {
	ll ret = 1;
	for(auto i : E[u])
		if(i != fa) {
			ll tmp = Dfs(i, u);
			ret += tmp;
			siz[++tot] = tmp * (n - tmp);
		}
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		memset(p, 0, sizeof(p));
		tot = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) E[i].clear();
		for(int i = 1; i <= n - 1; ++i) {
			int u, v; rd(u, v);
			Add(u, v); Add(v, u);
		}
		rd(m);
		for(int i = 1; i <= std::max(n, m) * 2; ++i) p[i] = 1;
		for(int i = 1; i <= m; ++i) rd(p[i]);
		std::sort(p + 1, p + m + 1, [](const ll &x, const ll &y) { return x > y; });
		Dfs(1, 0);
		std::sort(siz + 1, siz + n, [](const ll &x, const ll &y) { return x > y; });
		for(int i = 1; i <= n - 1; ++i) siz[i] %= kMod;
		ll ans = siz[1]; int ptr = 1;
		//printf("%d\n", m - (n - 2));
		for(ptr = 1; ptr <= std::max(1, m - (n - 2)); ++ptr) {
			//printf("A: %lld %lld\n", siz[1], p[ptr]);
			ans = ans * p[ptr] % kMod;
		}
		for(int i = 2; i <= n - 1; ++i, ++ptr) {
			//printf("B: %lld %lld\n", siz[i], p[ptr]);
			ans = (ans + siz[i] * p[ptr] % kMod) % kMod;
		}
		printf("%lld\n", ans);
	} return 0;
}