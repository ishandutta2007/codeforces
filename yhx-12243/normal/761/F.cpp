#include <bits/stdc++.h>

typedef long long ll;
const int N = 1054, Q = 300054;

int R, C, q;
int r1[Q], r2[Q], c1[Q], c2[Q];
int mdf[26][N][N];
ll ori[N][N], puc[26][N][N];
char map[N][N], dt[Q];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

template <typename T>
void ps(T (*m)[N]) {
	int i, j;
	for (i = 1; i <= R; ++i) for (j = 2; j <= C; ++j) m[i][j] += m[i][j - 1];
	for (i = 2; i <= R; ++i) for (j = 1; j <= C; ++j) m[i][j] += m[i - 1][j];
}

inline ll qr(ll (*m)[N], int r1, int r2, int c1, int c2) {return m[r2][c2] - m[r2][c1 - 1] - m[r1 - 1][c2] + m[r1 - 1][c1 - 1];}

int main() {
	int i, j, k, c, u, cur[26]; ll ans = LLONG_MAX;
	scanf("%d%d%d", &R, &C, &q);
	for (i = 1; i <= R; ++i) scanf("%s", map[i] + 1);
	for (i = 0; i < q; ++i)
		scanf("%d%d%d%d%s", r1 + i, c1 + i, r2 + i, c2 + i, dt + i), c = dt[i] - 97,
		++mdf[c][r1[i]][c1[i]], --mdf[c][r1[i]][c2[i] + 1],
		--mdf[c][r2[i] + 1][c1[i]], ++mdf[c][r2[i] + 1][c2[i] + 1];
	for (k = 0; k < 26; ++k) ps(mdf[k]);
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= C; ++j) {
			c = map[i][j] - 97, u = 0;
			for (k = 0; k < 26; ++k) cur[k] = mdf[k][i][j];
			cur[c] += q - std::accumulate(cur, cur + 26, 0);
			for (k = 1; k < 26; ++k) u += cur[k] * k, cur[k] += cur[k - 1];
			for (k = 0; k < 26; ++k) puc[k][i][j] = u, u += cur[k] * 2 - q;
			ori[i][j] = puc[c][i][j];
		}
	for (k = 0; k < 26; ++k) ps(puc[k]);
	ps(ori);
	for (i = 0; i < q; ++i)
		down(ans, qr(puc[dt[i] - 97], r1[i], r2[i], c1[i], c2[i]) - qr(ori, r1[i], r2[i], c1[i], c2[i]));
	printf("%lld\n", ori[R][C] + ans);
	return 0;
}