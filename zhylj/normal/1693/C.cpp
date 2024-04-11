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
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, INF = 0x3f3f3f3f;

int n, m, d[N], dg[N], f[N];
bool vis[N];
std::vector <int> E[N], r_E[N];
void Add(int u, int v) {
	++dg[u];
	E[u].push_back(v);
	r_E[v].push_back(u);
}

std::priority_queue <pii, std::vector <pii>, std::greater <pii> > q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(d, 0x3f, sizeof(d));
		memset(f, 0x3f, sizeof(f));
		rd(n, m); d[n] = f[n] = 0; q.push(mkp(0, n));
		for(int i = 1; i <= m; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		while(!q.empty()) {
			pii p = q.top(); q.pop();
			int u = p.se, w = p.fi;
			if(w != f[u] || vis[u]) continue;
			//printf("%d %d\n", u);
			f[u] = w; vis[u] = true;
			for(int v : r_E[u]) if(!vis[v]) {
				--dg[v];
				f[v] = std::min(f[v], f[u] + dg[v] + 1);
				q.push(mkp(f[v], v));
			}
		}
		printf("%d\n", f[1]);
	} return 0;
}