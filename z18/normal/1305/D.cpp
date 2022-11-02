#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
int n, deg[maxn + 3];
vector<int> G[maxn + 3];
bool vis[maxn + 3];

void dfs(int u, int f) {
	vis[u] = true;
	deg[u]--, deg[f]--;
	for (int i = 0, v; i < G[u].size(); i++) {
		v = G[u][i];
		if (v == f) continue;
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	for (int k = 1; ; k++) {
		int p = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && deg[i] >= 2) {
				p = i; break;
			}
		}
		if (!p) {
			int a = 0, b = 0;
			for (int i = 1; i <= n; i++) {
				if (!vis[i]) {
					if (!a) a = i;
					else { b = i; break; }
				}
			}
			if (b == 0) {
				printf("! %d\n", a);
				fflush(stdout);
				break;
			} else {
				printf("? %d %d\n", a, b);
				fflush(stdout);
				int c; scanf("%d", &c);
				printf("! %d\n", c);
				fflush(stdout);
				break;
			}
		}
		int a = 0, b = 0;
		for (int j = 0; j < G[p].size(); j++) {
			int v = G[p][j];
			if (!vis[v]) {
				if (!a) a = v;
				else { b = v; break; }
			}
		}
		printf("? %d %d\n", a, b);
		fflush(stdout);
		int c; scanf("%d", &c);
		if (c == a) dfs(p, a);
		else if (c == b) dfs(p, b);
		else dfs(a, p), dfs(b, p);
	}
	return 0;
}