#include <bits/stdc++.h>
#define c0 c[0]
#define c1 c[1]
#define c2 c[2]
#define m0 m[0]
#define m1 m[1]
#define m2 m[2]

const int N = 81, INF = 0x3f3f3f3f;
const int tr[2][3] = {{0, 0, 1}, {0, -1, 1}};

int n;
int f[N][N][N][2];
int o[3][N], sum[3][N];
char s[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

int main() {
	int i, j, t, d, cur, c[3], m[3] = {0};
	scanf("%d%s", &n, s);
	for (i = 0; i < n; ++i) s[i] = (s[i] == 86 ? 2 : s[i] == 75);
	for (i = 0; i < n; ++i)
		sum[0][i + 1] = sum[0][i] + (s[i] == 0),
		sum[1][i + 1] = sum[1][i] + (s[i] == 1),
		sum[2][i + 1] = sum[2][i] + (s[i] == 2),
		o[(int)s[i]][ m[(int)s[i]]++ ] = i;
	memset(f, 63, sizeof f), ****f = 0;
	for (c0 = 0; c0 <= *m; ++c0)
		for (c1 = 0; c1 <= m[1]; ++c1)
			for (c2 = 0; c2 <= m[2]; ++c2)
				for (t = 0; t < 2; ++t) if ((cur = f[c0][c1][c2][t]) < INF)
					for (d = 0; d < 3; ++d) if (c[d] < m[d]) {
						i = o[d][ c[d]++ ], j = i - (min(sum[0][i], c0) + min(sum[1][i], c1) + min(sum[2][i], c2));
						if (~tr[t][d]) down(f[c0][c1][c2][tr[t][d]], cur + j);
						--c[d];
					}
	printf("%d\n", min(f[m0][m1][m2][0], f[m0][m1][m2][1]));
	return 0;
}