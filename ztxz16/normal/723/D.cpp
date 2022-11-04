#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 55;

int n, m, k, tot, color[N][N], val[N * N];
int visit[N][N], fillColor[N * N];
char str[N][N];

void dfs(int x, int y, int color) {
	if (x < 1 || x > n || y < 1 || y > m) {
		val[color] = 1000000;
		return;
	}
	
	if (str[x][y] != '.' || visit[x][y]) {
		return;
	}
	
	visit[x][y] = color;
	val[color]++;
	dfs(x - 1, y, color);
	dfs(x + 1, y, color);
	dfs(x, y - 1, color);
	dfs(x, y + 1, color);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i] + 1);
	}
	
	int lakeCnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			color[i][j] = ++tot;
			if (str[i][j] == '.' && !visit[i][j]) {
				dfs(i, j, color[i][j]);
				if (val[color[i][j]] <= n * m) {
					lakeCnt++;
				}
			}
		}
	}
	
	int ans = 0;
	while (lakeCnt > k) {
		int fill = 0;
		for (int i = 1; i <= n * m; i++) {
			if (val[i] <= n * m && val[i] >= 1 && (fill == 0 || val[i] < val[fill])) {
				fill = i;
			}
		}
		
		lakeCnt--;
		ans += val[fill];
		fillColor[fill] = 1;
		val[fill] = 1000000;
	}
	
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str[i][j] == '.' && fillColor[visit[i][j]] == 1) {
				printf("*");
			} else {
				printf("%c", str[i][j]);
			}
		}
		
		printf("\n");
	}
	
	return 0;
}