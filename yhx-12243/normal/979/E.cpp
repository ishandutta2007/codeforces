#include <bits/stdc++.h>

typedef long long ll;
const int N = 54, mod = 1000000007, pmod = mod - 1;

int n, par;
int dp[2][2][2][2], (*cur)[2][2] = *dp, (*nxt)[2][2] = dp[1];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

ll PowerMod(ll a, int n, ll c = 1) {for (n += n >> 31 & pmod; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int main() {
	int i, j, k, p, c, t;
	scanf("%d%d", &n, &par);
	for (***nxt = i = 1; i <= n; ++i) {
		scanf("%d", &c), std::swap(cur, nxt), memset(nxt, 0, sizeof *dp);
		for (p = 0; p < 2; ++p) for (j = 0; j < 2; ++j)
			for (k = 0; k < 2; ++k) if ((t = cur[p][j][k])) {
				if (c != 1) add(nxt[!p][1][k], t), add(nxt[!p ^ k][j | !k][k], t);
				if (c != 0) add(nxt[!p][j][1], t), add(nxt[!p ^ j][j][!j | k], t);
			}
	}
	printf("%d\n", (int)PowerMod(2, (n - 1) * (n - 2) / 2 - 1, ((ll)nxt[par][0][0] + nxt[par][0][1] + nxt[par][1][0] + nxt[par][1][1]) % mod));
	return 0;
}