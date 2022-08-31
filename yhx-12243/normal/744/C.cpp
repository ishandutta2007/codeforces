#include <bits/stdc++.h>
#define popc __builtin_popcount
#define ctz __builtin_ctz

const int N = 18, N2 = 126, Np = 65554, INF = 0x3f3f3f3f;

int n, ALL, Rmask, Bmask;
int r[N], b[N], f[Np][N2];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

int main() {
	int i, j, k, S, R = 0, B = 0, ans = INF; char op[4];
	scanf("%d", &n), ALL = ~(-1 << n);
	for (i = 0; i < n; ++i)
		scanf("%s%d%d", op, r + i, b + i), R += r[i], B += b[i],
		(*op == 82 ? Rmask : Bmask) |= 1 << i;
	memset(f, 192, sizeof f), **f = 0;
	for (i = 0; i < ALL; ++i)
		for (j = 0; j < N2; ++j)
			if (f[i][j] >= 0)
				for (S = ~i & ALL; S; S &= S - 1)
					k = ctz(S), up(f[i | 1 << k][j + min(r[k], popc(i & Rmask))], f[i][j] + min(b[k], popc(i & Bmask)));
	for (j = 0; j < N2; ++j) down(ans, max(R - j, B - f[ALL][j]));
	printf("%d\n", ans + n);
	return 0;
}