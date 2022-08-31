#include <bits/stdc++.h>

typedef long long ll;
const int N = 3054, mod = 998244353;

int S, T, U = 0;
char s[N], t[N];
int pw2[N];
int f[N][N], F[N][N];
int g[N][N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

int main() {
	int i, j, ans = 0;
	scanf("%s%s", s, t), S = strlen(s), T = strlen(t);
	for (i = T; i <= S; ++i) g[i][0] = 1;
	for (i = S; i; --i)
		for (j = 0; j <= S - i; ++j) if (g[i][j]) {
			if (j >= T || s[i - 1] == t[j])
				add(g[i - 1][j + 1], g[i][j]);
			if (j + i - 1 >= T || s[i - 1] == t[j + i - 1])
				add(g[i - 1][j], g[i][j]);
		}
	for (i = 0; i <= S; ++i) add(ans, g[0][i]);
	printf("%d\n", ans);
	return 0;
}