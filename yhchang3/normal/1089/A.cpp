#include <bits/stdc++.h>

using namespace std;

bool vis[201][201][4][4][4][4], f[201][201][4][4][4][4];
pair<int, int> nxt[201][201][4][4][4][4];
bool dp(int a, int b, int x, int y, int cura, int curb) {
	if (x < 0 || y < 0) return false;
	if (cura == 3 || curb == 3) {
		if (a > 0 || b > 0) return false;
		if (x == 0 && y == 0) return true;
		return false;
	}

	if (vis[a][b][x][y][cura][curb]) return f[a][b][x][y][cura][curb];
	vis[a][b][x][y][cura][curb] = true;
	f[a][b][x][y][cura][curb] = false;
	int st = (cura + curb == 4 ? 15 : 25);
	for (int i = 0; i <= st - 2; i ++) {
		int j = st;
		if (a >= i && b >= j) {
			int tmp = dp(a - i, b - j, x, y - 1, cura, curb + 1);
			if (tmp) { nxt[a][b][x][y][cura][curb] = make_pair(i, j); return f[a][b][x][y][cura][curb] = true; }
		}
		if (a >= j && b >= i) {
			int tmp = dp(a - j, b - i, x - 1, y, cura + 1, curb);
			if (tmp) { nxt[a][b][x][y][cura][curb] = make_pair(j, i); return f[a][b][x][y][cura][curb] = true; }
		}
	}
	for (int i = st + 1; i <= a; i ++) {
		int j = i - 2;
		if (a >= i && b >= j) {
			int tmp = dp(a - i, b - j, x - 1, y, cura + 1, curb);
			if (tmp) { nxt[a][b][x][y][cura][curb] = make_pair(i, j); return f[a][b][x][y][cura][curb] = true; }
		}
		else break;
	}
	for (int i = st + 1; i <= b; i ++) {
		int j = i - 2;
		if (b >= i && a >= j) {
			int tmp = dp(a - j, b - i, x, y - 1, cura, curb + 1);
			f[a][b][x][y][cura][curb] |= tmp;
			if (tmp) { nxt[a][b][x][y][cura][curb] = make_pair(j, i); return f[a][b][x][y][cura][curb] = true; }
		}
		else break;
	}

//	printf("%d %d %d %d %d %d: %d\n", a, b, x, y, cura, curb, f[a][b][x][y]);
	return f[a][b][x][y][cura][curb] = false;
}

int main( ) {
	int m;
//	dp(25, 29, 1, 1, 2, 0);
//	printf("%d %d\n", nxt[25][29][1][1].first, nxt[25][29][1][1].second);


	int a, b;
	scanf("%d", &m);
	while (m --) {
		int mx = -0x3f3f3f3f;
		pair<int, int> ans = make_pair(-1, -1);
		scanf("%d %d", &a, &b);
		for (int i = 0; i <= 3; i ++)
			for (int j = 0; j <= 3; j ++) {
				if (max(i, j) != 3 || (i == j && i == 3)) continue;
				int tmp = dp(a, b, i, j, 0, 0);
				if (tmp) {
					if (i - j > mx) {
						mx = i - j;
						ans = max(ans, make_pair(i, j));
					}
				}
			}
		if (ans == make_pair(-1, -1)) printf("Impossible\n");
		else {
			printf("%d:%d\n", ans.first, ans.second);
			int cura = 0, curb = 0;
			do {
				pair<int, int> cur = nxt[a][b][ans.first][ans.second][cura][curb];
				printf("%d:%d ", cur.first, cur.second);
				a -= cur.first;
				b -= cur.second;
				if (cur.first > cur.second) {
					ans.first --;
					cura ++;
				}
				else {
					ans.second --;
					curb ++;
				}
			}while (a > 0 || b > 0);
			puts("");
		}
	}
	return 0;
}