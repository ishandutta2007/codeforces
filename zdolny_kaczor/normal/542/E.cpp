# include <cstdio>
# include <vector>
# include <cstdlib>
using namespace std;
const int MN = 1 << 10;
vector <int> graph[MN];
const int inf = 1 << 22;
int dist[MN][MN];
int color[MN];
int component[MN];
int maxincomponent[MN];
void err() {
	printf("-1\n");
	exit(0);
}
void dfs(int x, int c, int nr) {
	component[x] = nr;
	if (color[x] == c) {
		return;
	}
	else if (color[x] == 3 - c) {
		err();
	}
	color[x] = c;
	for (auto v : graph[x]) {
		dfs(v, 3 - c, nr);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			dist[i][k] = inf;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			dfs(i, 1, i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			for (int l = 1; l <= n; ++l) {
				dist[k][l] = min(dist[k][l], dist[k][i] + dist[i][l]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (dist[i][k] != inf) {
				maxincomponent[component[i]] = max(maxincomponent[component[i]], dist[i][k]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += maxincomponent[i];
	}
	printf("%d\n", res);
}