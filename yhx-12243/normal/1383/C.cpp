#include <bits/stdc++.h>
#define popc __builtin_popcount
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 100054, V = 20, ALL = 1048575;

int n;
char A[N], B[N];
int G[V], p[V];
bool DAG[ALL + 2];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

void work() {
	int i, j, u, v, extra = V, ans = 0;
	cin >> n >> A >> B;
	memset(G, 0, sizeof G), std::iota(p, p + V, 0);
	for (i = 0; i < n; ++i) if ((u = A[i] - 97) != (v = B[i] - 97)) G[u] |= 1 << v, p[ancestor(u)] = ancestor(v);
	*DAG = true;
	for (i = 1; i <= ALL; ++i) {
		DAG[i] = false;
		for (j = i; j && !DAG[i]; j &= j - 1)
			v = ctz(j), DAG[i] = DAG[i] || (DAG[i & ~(1 << v)] && !(G[ctz(j)] & i));
		if (DAG[i]) down(extra, V - popc(i));
	}
	for (i = 0; i < V; ++i) ans += p[i] != i;
	cout << ans + extra << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}