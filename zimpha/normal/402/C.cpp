#include <cstdio>
#include <cstring>

int main() {
	int t, n, p, vis[100][100];
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &p);
		memset(vis, 0, sizeof(vis));
		int tot = 2 * n + p;
		int x = 1, y = 2;
		while (tot --) {
			printf("%d %d\n", x, y);
			y ++;
			if (y > n) {
				x ++;
				y = x + 1;
			}
		}
	}
	return 0;
}