#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
typedef long long ll;
int n, m, num = 1, rnk, k, ans[100], res[100], C[100][100];
ll b[100], a[100], c[100];

void insert(ll x) {
	for (int i = m - 1; ~i; i--) if (x >> i & 1) {
		if (b[i]) x ^= b[i]; else {
			for (int j = i - 1; j >= 0; j--) if (b[j] && x >> j & 1) x ^= b[j];
			b[i] = x, rnk++;
			for (int j = i + 1; j < m; j++) if (b[j] >> i & 1) b[j] ^= x;
			return;
		}
	}
	num = 2ll * num % mod;
}

void dfs(int x, ll y) {
	if (x > k) {
		ans[__builtin_popcountll(y)]++;
		return;
	}
	dfs(x + 1, y);
	dfs(x + 1, y ^ a[x]);
}

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) if (b & 1) c = 1ll * a * c % mod;
	return c;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x; scanf("%lld", &x);
		insert(x);
	}
	if (rnk <= 27) {
		for (int i = 0; i < m; i++) if (b[i]) a[++k] = b[i];
		dfs(1, 0);
	} else {
		for (int i = 0; i < m; i++) if (!b[i]) {
			a[++k] |= 1ll << i;
			for (int j = 0; j < m; j++) if (b[j] >> i & 1) {
				a[k] |= 1ll << j;
			}
		}
		dfs(1, 0);
		for (int i = 0; i <= m; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
			}
		}
		for (int i = 0; i <= m; i++) {
			int cur = 1;
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k <= m - i; k++) {
					res[j + k] = (res[j + k] + 1ll * ans[i] * cur % mod * C[i][j] % mod * C[m - i][k]) % mod;
				}
				cur = mod - cur;
			}
		}
		int x = qpow(2, mod - 1 - (m - rnk));
		for (int i = 0; i <= m; i++) res[i] = 1ll * res[i] * x % mod;
		swap(ans, res);
	}
	for (int i = 0; i <= m; i++) ans[i] = 1ll * ans[i] * num % mod;
	for (int i = 0; i <= m; i++) printf("%d%c", ans[i], " \n"[i == m]);
	return 0;
}