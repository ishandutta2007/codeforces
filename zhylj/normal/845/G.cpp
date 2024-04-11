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

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 1e5 + 5;
const int kB = 63;

int n, m; bool vis[kN];
struct Edge {
	int v; ll w;
}; std::vector<Edge> E[kN];
void AddEdge(int u, int v, ll w) { E[u].push_back((Edge) {v, w}); }

ll lb[kB], d[kN], ans;
void InsLb(ll x) {
	for(int i = kB - 1; ~i; --i) {
		if(!(x >> i)) continue;
		if(!lb[i]) {
			lb[i] = x;
			break;
		}
		x ^= lb[i];
	}
}
void Dfs(int x) {
	if(x == n) ans = d[x];
	vis[x] = true;
	for(auto i : E[x]) {
		int v = i.v; ll w = i.w;
		if(!vis[v]) d[v] = d[x] ^ w, Dfs(v);
		else InsLb(d[v] ^ d[x] ^ w);
	}
}

int main() {
	rd(n, m);
	for(int i = 1; i <= m; ++i) {
		int x, y; ll z; rd(x, y, z);
		AddEdge(x, y, z); AddEdge(y, x, z);
	}
	Dfs(1);
	for(int i = kB - 1; ~i; --i)
		if((ans ^ lb[i]) < ans) ans ^= lb[i];
	printf("%lld", ans);
	return 0;
}