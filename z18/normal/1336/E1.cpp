#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fi first
#define se second
using namespace std;

typedef long long ll;
const int maxn = 1 << 9, mod = 998244353;
int n, m, num = 1, k, M, dp[60][60][maxn + 3], res[100];
ll b[100], a[100], c[100];

void insert(ll x) {
	per(i, m - 1, 0) if (x >> i & 1) {
		if (b[i]) x ^= b[i]; else {
			per(j, i - 1, 0) if (b[j] && x >> j & 1) x ^= b[j];
			b[i] = x;
			rep(j, i + 1, m - 1) if (b[j] && b[j] >> i & 1) b[j] ^= x;
			return;
		}
	}
	num = 2ll * num % mod;
}

void dfs(int i, ll x = 0) {
	if (i > k) {
		res[__builtin_popcountll(x)]++;
		return;
	}
	dfs(i + 1, x);
	dfs(i + 1, x ^ c[i]);
}

void mod_add(int &x, int y) {
	x += y, x < mod ? 0 : x -= mod;
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, 1, n) {
		ll x; scanf("%lld", &x), insert(x);
	}
	rep(i, 0, m - 1) if (b[i]) {
		a[++k] = i;
	}
	if (k <= 25) {
		rep(i, 1, k) c[i] = b[a[i]];
		dfs(1);
	} else {
		rep(i, 0, m - 1) if (!b[i]) {
			rep(j, 1, k) c[j] |= (b[a[j]] >> i & 1) << M;
			M++;
		}
		dp[0][0][0] = 1;
		rep(i, 1, k) {
			rep(j, 0, i - 1) {
				rep(msk, 0, (1 << M) - 1) {
					mod_add(dp[i][j][msk], dp[i - 1][j][msk]);
					mod_add(dp[i][j + 1][msk ^ c[i]], dp[i - 1][j][msk]);
				}
			}
		}
		rep(i, 0, k) {
			rep(msk, 0, (1 << M) - 1) {
				int t = __builtin_popcountll(msk);
				mod_add(res[i + t], dp[k][i][msk]);
			}
		}
	}
	rep(i, 0, m) printf("%d%c", int(1ll * res[i] * num % mod), " \n"[i == m]);
	return 0;
}