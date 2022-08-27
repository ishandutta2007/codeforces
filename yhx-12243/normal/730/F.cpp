#include <bits/stdc++.h>

const int N = 5054, M = 10054;

int n, B;
int a[N], A[N], ans[N];
int dp[2][M], *cur = *dp, *nxt = dp[1];
short from[N][M];

inline bool down(int &x, const int y) {return x > y ? x = y, 1 : 0;}

int main() {
	int i, j, nj, u, v, used, s = 0;
	scanf("%d%d", &n, &B);
	memset(nxt, 63, sizeof *dp), *nxt = 0;
	for (i = 1; i <= n; ++i) {
		scanf("%d", a + i), A[i] = A[i - 1] + a[i], s += a[i] / 10;
		std::swap(cur, nxt), memset(nxt, 63, sizeof *dp);
		for (j = 0; j <= s; ++j)
			if ((used = A[i - 1] - cur[j]) >= 0)
				for (u = 0, v = a[i]; u <= v && u <= B - used + j; ++u, --v)
					if (down(nxt[nj = j + v / 10], cur[j] + v))
						from[i][nj] = u;
	}
	j = std::min_element(nxt, nxt + (s + 1)) - nxt;
	printf("%d\n", nxt[j]);
	for (i = n; i; --i) ans[i] = u = from[i][j], v = a[i] - u, j -= v / 10;
	for (i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? 10 : 32);
	return 0;
}