#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 648;

int V, E;
int G[N][N];
bool mask[N];
ll d[N], e[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}
inline int minus(int x, const ll y) {return x = (x - y) % V, x + (x >> 31 & V);}

void Dijkstra(int s) {
	int i, j, x;
	memset(d, 63, (V + 1) << 3), d[s] = 0;
	memset(mask, false, V);
	for (i = 0; i < V; ++i) {
		x = V;
		for (j = 0; j < V; ++j) if (!mask[j] && d[j] < d[x]) x = j;
		mask[x] = true;
		for (j = 0; j < V; ++j) down(d[j], d[x] + G[x][minus(j, d[x])]);
	}
}

int main() {
	int i, j, u, v, w;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> V >> E;
	memset(G, 63, sizeof G);
	for (i = 0; i < E; ++i) cin >> u >> v >> w, down(G[u][v], w);
	for (i = 0; i < V; ++i)
		for (w = 0; w < 2; ++w) {
			for (j = 1; j < V; ++j) down(G[i][j], G[i][j - 1] + 1);
			down(G[i][0], G[i][V - 1] + 1);
		}
	for (i = 0; i < V; ++i) {
		Dijkstra(i);
		for (j = 0; j < V; ++j)
			cout << d[j] << (j == V - 1 ? '\n' : ' ');
	}
	return 0;
}