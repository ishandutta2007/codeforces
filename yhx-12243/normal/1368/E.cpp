#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int V, E;
int G[N][2], f[N];
int del[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void work() {
	int i, u, v, cnt = 0;
	cin >> V >> E;
	for (i = 1; i <= V; ++i) G[i][0] = G[i][1] = f[i] = 0;
	for (i = 0; i < E; ++i) cin >> u >> v, G[u][!!*G[u]] = v;
	for (i = 1; i <= V; ++i)
		if (f[i] == 2) del[cnt++] = i;
		else up(f[G[i][0]], f[i] + 1), up(f[G[i][1]], f[i] + 1);
	cout << cnt << '\n';
	for (i = 0; i < cnt; ++i) (i ? cout << ' ' : cout) << del[i];
	cout.put(10);
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}