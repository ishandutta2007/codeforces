#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

typedef long long ll;
typedef std::pair <ll, int> pr;
const int N = 3600054, M = N * 2, mod = 998244353;
const ll INF64 = 0x3f3f3f3f3f3f3f3fll;

struct edge {
	int u, v, w;
	edge () {}
	edge (int u0, int v0, int w0) : u(u0), v(v0), w(w0) {}
} e[M];

int V, E, Es = 0, ln;
int first[N], next[M], u_[N], v_[N];
ll d[N];
std::priority_queue <pr, std::vector <pr>, std::greater <pr>> pq;

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void addedge(int u, int v, int w) {e[++Es] = edge(u, v, w), next[Es] = first[u], first[u] = Es;}

void Dijkstra(int n, int s) {
	int i, x, y; ll D;
	memset(d, 63, (n + 1) << 3);
	for (pq.emplace(d[s] = 0, s); !pq.empty(); ) {
		std::tie(D, x) = pq.top(), pq.pop();
		if (d[x] == D)
			for (i = first[x]; i; i = next[i])
				if (D + e[i].w < d[y = e[i].v])
					pq.emplace(d[y] = D + e[i].w, y);
	}
}

int main() {
	int i, j, u, v; ll ans = INF64;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> V >> E, ln = lg2(V) + 1;
	for (v = 1; v <= V; ++v)
		for (i = 0; i + 1 < ln; ++i) addedge(i * V + v, (i + 1) * V + v, 1 << i);
	for (j = 0; j < E; ++j) {
		cin >> u >> v, u_[j] = u, v_[j] = v; 
		for (i = 0; i < ln; ++i, std::swap(u, v))
			addedge(i * V + u, i * V + v, 1);
	}
	Dijkstra(ln * V, 1);
	for (i = 1; i <= ln; ++i) down(ans, d[i * V]);
	if (ans < INF64) return cout << ans << '\n', 0;
	Es = 0, memset(first, 0, (2 * V + 1) << 2);
	for (i = 0; i < E; ++i)
		u = u_[i], v = v_[i], addedge(u, v, 1), addedge(v + V, u + V, 1);
	for (v = 1; v <= V; ++v) addedge(v, v + V, N), addedge(v + V, v, N);
	Dijkstra(2 * V, 1), ans = min(d[V], d[2 * V]),
	cout << (PowerMod(2, ans / N) + ans % N - 1) % mod << '\n';
	return 0;
}