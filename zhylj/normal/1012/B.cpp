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

int n, m, q, tot, fa[kN];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if(fx != fy) {
		--tot; fa[fy] = fx;
	}
}
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m, q); tot = n + m;
		for(int i = 1; i <= n + m; ++i) fa[i] = i;
		for(int i = 1; i <= q; ++i) {
			int r, c; rd(r, c);
			Merge(r, n + c);
		}
		printf("%d", tot - 1);
	} return 0;
}