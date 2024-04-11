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
const int kN = 2e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, nxt[kN], col[kN], a[kN], b[kN];

void Dfs(int u) {
	if(!~col[u ^ 1]) col[u ^ 1] = col[u] ^ 1, Dfs(u ^ 1);
	else if(!~col[nxt[u]]) col[nxt[u]] = col[u] ^ 1, Dfs(nxt[u]);
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(col, 0xff, sizeof(col));
		rd(n);
		for(int i = 0; i < n; ++i) {
			rd(a[i], b[i]);
			--a[i]; --b[i];
			nxt[a[i]] = b[i];
			nxt[b[i]] = a[i];
		}
		for(int i = 0; i < 2 * n; ++i) {
			if(!~col[i]) col[i] = 0, Dfs(i);
		}
		for(int i = 0; i < n; ++i) {
			printf("%d %d\n", col[a[i]] + 1, col[b[i]] + 1);
		}
	} return 0;
}