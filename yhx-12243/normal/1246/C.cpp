#include <bits/stdc++.h>

typedef long long ll;
const int N = 2054, mod = 1000000007;

int R, C;
char map[N][N];
int H[N][N], V[N][N], cs[N];
int mapH[N][N], mapV[N][N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

int main() {
	int i, j, t, rs = 0, rem, ans;
	scanf("%d%d", &R, &C);
	for (i = 1; i <= R; ++i) scanf("%s", map[i] + 1);
	if (map[1][1] == 82 || map[R][C] == 82) return puts("0"), 0;
	if (R == 1 && C == 1) return puts("1"), 0;
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j)
			mapH[i][j] = mapH[i][j - 1] + (map[i][j] == 82),
			mapV[i][j] = mapV[i - 1][j] + (map[i][j] == 82);
	H[1][1] = V[1][1] = 1, H[1][2] = V[2][1] = mod - 1;
	for (i = 1; i <= R; ++i)
		for (rs = 0, j = 1; j <= C; ++j) {
			add(rs, H[i][j]), add(cs[j], V[i][j]);
			if (t = rs)
				rem = mapV[R][j] - mapV[i][j],
				add(V[i + 1][j], t), sub(V[R - rem + 1][j], t);
			if (t = cs[j])
				rem = mapH[i][C] - mapH[i][j],
				add(H[i][j + 1], t), sub(H[i][C - rem + 1], t);
		}
	add(ans = rs, cs[C]);
	printf("%d\n", ans);
	return 0;
}
/*
>>v...
..v...
..v...
..ORR.
......
......
*/