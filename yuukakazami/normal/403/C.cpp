#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 2000 + 10;
bool e[MAX_N][MAX_N];
int n;

void dfs(int u, bool vis[]) {
	if (vis[u])
		return;
	vis[u] = true;
	for (int i = 0; i < n; ++i) {
		if (e[u][i])
			dfs(i, vis);
	}
}

bool v1[MAX_N], v2[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			e[i][j] = x > 0;
		}
	}

	memset(v1, 0, sizeof v1);
	dfs(0, v1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			swap(e[i][j], e[j][i]);
		}
	}
	memset(v2, 0, sizeof v2);
	dfs(0, v2);
	for (int i = 0; i < n; ++i) {
		if (!v1[i] || !v2[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}