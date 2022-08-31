#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 131100, mod = 998244353;

int V, E;
int to[N], first[N], next[N];
int deg[N], topo[N];
int sg[N], mark[N];
int f[N], p[N];

inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void addedge(int u, int v, int id) {to[id] = v, next[id] = first[u], first[u] = id, ++deg[v];}

void FWT(int *a) {
	int i, j, k, r, len = 1;
	for (i = 0; i < 17; ++i, len <<= 1)
		for (j = 0; j < 131072; j += len << 1)
			for (k = j; k < j + len; ++k)
				r = a[k + len], reduce(a[k + len] = a[k] - r), add(a[k], r);
}

int main() {
	int i, j, x, y, h, t = 0, u, v; ll iv, s = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E;
	for (i = 1; i <= E; ++i) cin >> u >> v, addedge(u, v, i);
	for (i = 1; i <= V; ++i) if (!deg[i]) topo[t++] = i;
	for (h = 0; h < t; ++h)
		for (i = first[x = topo[h]]; i; i = next[i])
			if (!--deg[y = to[i]]) topo[t++] = y;
	assert(t == V);
	for (i = V - 1; i >= 0; --i) {
		x = topo[i];
		for (j = first[x]; j; j = next[j]) mark[sg[to[j]]] = x;
		for (sg[x] = 0; mark[sg[x]] == x; ++sg[x]);
		++p[sg[x]];
	}
	iv = PowerMod(V + 1, mod - 2);
	for (i = 0; i < 131072; ++i) p[i] = p[i] * iv % mod;
	FWT(p);
	for (i = 0; i < 131072; ++i) s += f[i] = PowerMod(mod + 1 - p[i], mod - 2);
	s = s % mod * 998236737ll % mod * iv % mod;
	cout << (mod + 1 - s) % mod << '\n';
	return 0;
}