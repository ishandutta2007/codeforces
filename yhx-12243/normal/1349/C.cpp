#include <bits/stdc++.h>

typedef long long ll;
const int N = 1054, INF = 0x3f3f3f3f;
const int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};

int R, C, q;
int ti[N][N];
char map[N][N];
int que[N * N];

void bfs() {
	int h, t = 0, i, j, d, ni, nj;
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			if (ti[i][j] == 1) que[t++] = i | j << 16;
	for (h = 0; h < t; ++h) {
		i = que[h] & 65535, j = que[h] >> 16;
		for (d = 0; d < 4; ++d) {
			ni = i + dr[d], nj = j + dc[d];
			if (ti[ni][nj] >= INF)
				ti[ni][nj] = ti[i][j] + 1,
				que[t++] = ni | nj << 16;
		}
	}
}

int main() {
	int i, j; ll P;
	scanf("%d%d%d", &R, &C, &q);
	for (i = 1; i <= R; ++i)
		scanf("%s", map[i] + 1), memset(ti[i] + 1, 63, C << 2);
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j) {
			if (map[i][j] == map[i][j + 1])
				ti[i][j] = ti[i][j + 1] = 1;
			if (map[i][j] == map[i + 1][j])
				ti[i][j] = ti[i + 1][j] = 1;
		}
	bfs();
	for (; q; --q) {
		scanf("%d%d%lld", &i, &j, &P);
		if (ti[i][j] >= INF || P < ti[i][j]) putchar(map[i][j]);
		else putchar(map[i][j] ^ int((P ^ ti[i][j] ^ 1) & 1));
		putchar(10);
	}
	return 0;
}