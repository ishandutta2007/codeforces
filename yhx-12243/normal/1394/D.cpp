#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 200054, M = N * 2;
const ll INF = 0x40000000000ll;

enum orient {
	UP, DOWN, BOTH
};

int n, E = 0;
int w[N], h[N];
int to[M], first[N], next[M];
int p[N];
ll fu[N], fd[N];
ll buf[N], ans = INF;
orient ori[N];

inline int min(const int x, const int y) {return x < y ? x : y;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x]) {
			p[y] = x, dfs(y);
			if (h[x] > h[y]) ori[y] = UP;
			else if (h[x] < h[y]) ori[y] = DOWN;
			else ori[y] = BOTH;
		}
}

void solve(int x) {
	int i, y, d = 0, out, in; ll IM = w[x] + w[p[x]];
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) solve(y), IM += fu[y];
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) buf[d++] = fd[y] - fu[y];
	std::sort(buf, buf + d);
	fu[x] = fd[x] = INF;
	for (in = d, out = 0; in >= 0; --in, ++out) {
		if (x == 1) down(ans, IM - (ll)w[x] * min(in + 1, out + 1));
		else {
			if (ori[x] != DOWN) down(fu[x], IM - (ll)w[x] * min(in, out + 1));
			if (ori[x] != UP) down(fd[x], IM - (ll)w[x] * min(in + 1, out));
		}
		IM += buf[out];
	}
}

int main() {
	int i, u, v;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> w[i];
	for (i = 1; i <= n; ++i) cin >> h[i];
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	dfs(1), solve(1);
	cout << ans << '\n';
	return 0;
}