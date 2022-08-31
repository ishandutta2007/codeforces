#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long llong;

const int N = 200500;

vector<int> E[N];

int n;

int solve_bad() {
	bool mega_vertex = false;
	for (int i = 0; i < n; i++) {
		if ((int)E[i].size() == n - 1)
			mega_vertex = true;
	}
	return mega_vertex;
}

int D[N];
int F[N];

void DFS(int x, int p = -1) {
	D[x] = F[x] = 0;
	for (int i = 0; i < E[x].size(); i++) {
		int y = E[x][i];
		if (y == p) {
			E[x].erase(E[x].begin() + i);
			--i;
			continue;
		}
		DFS(y, x);
	}
	int sD = 0;
	for (int y : E[x]) {
		sD += D[y];
	}
	F[x] = max(F[x], sD);
	for (int y : E[x]) {
		F[x] = max(F[x], F[y] + 1 + sD - D[y]);
	}
	
	int max1 = -N, max2 = -N;
	D[x] = max(D[x], F[x]);
	for (int y : E[x]) {
		int cur = F[y] - D[y];
		if (cur > max1)
			max2 = max1, max1 = cur;
		else if (cur > max2)
			max2 = cur;
	}
	if (max1 < 0 || max2 < 0)
		return;
	D[x] = max(D[x], 2 + sD + max1 + max2);
}

int solve_good() {
	DFS(0);
	int ans = max(D[0], F[0]);
	return ans;
}

int main() {
	int x, y;
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int span_edges = 0;
	if (x >= y) {
		span_edges = solve_bad();
	} else {
		span_edges = solve_good();
	}
	llong ans = span_edges * 1ll * x + (n - 1 - span_edges) * 1ll * y;
	cout << ans << endl;
}