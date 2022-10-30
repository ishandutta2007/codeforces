#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5, inf = maxn + 1;
int n, k, a[maxn + 3], m, b[maxn + 3], p[maxn + 3];
map<int, int> M;
ll ans;

void prework(int n) {
	for (int i = 2; i <= n; i++) {
		if (!b[i]) {
			p[++m] = i;
			b[i] = m;
		}
		for (int j = 1; j <= m && i * p[j] <= n; j++) {
			b[i * p[j]] = j;
			if (i % p[j] == 0) {
				break;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	prework(maxn);
	for (int i = 1, x, y, z; i <= n; i++) {
		scanf("%d", &a[i]);
		x = a[i], y = 1, z = 1;
		while (x != 1) {
			int t = b[x], c = 0;
			while (x % p[t] == 0) {
				x /= p[t], c++;
			}
			c %= k;
			for (int j = 0; j < c; j++) {
				z = min(1ll * z * p[t], 1ll * inf);
			}
			c = (k - c) % k;
			for (int j = 0; j < c; j++) {
				y = min(1ll * y * p[t], 1ll * inf);
			}
		}
		if (y != inf) {
			ans += M[y];
		}
		if (z != inf) {
			M[z]++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}