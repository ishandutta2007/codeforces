#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000, mod = 1e9 + 7;
int n, m, a[maxn + 3], f[maxn + 3], h[maxn + 3], l[maxn + 3], r[maxn + 3];
vector<int> S[maxn + 3];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &f[i], &h[i]);
		int cnt = h[i];
		l[i] = r[i] = -1;
		for (int j = 1; j <= n; j++) {
			if ((cnt -= (a[j] == f[i])) == 0) {
				l[i] = j;
				break;
			}
		}
		if (l[i] == -1) {
			i--, m--;
			continue;
		}
		cnt = h[i];
		for (int j = n; j; j--) {
			if ((cnt -= (a[j] == f[i])) == 0) {
				r[i] = j;
				break;
			}
		}
		S[f[i]].push_back(i);
	}
	int res = 0, ans = 0;
	for (int i = 0; i <= m; i++) {
		int x = i ? 1 : 0, y = 1;
		for (int j = 1; j <= n; j++) {
			if (j == f[i]) {
				int a = 0;
				for (int k = 0; k < S[j].size(); k++) {
					int t = S[j][k];
					if (t == i) continue;
					a += r[t] > l[i];
				}
				if (a) {
					x++, y = 1ll * y * a % mod;
				}
			} else {
				int a = 0, b = 0, c = 0;
				for (int k = 0; k < S[j].size(); k++) {
					int t = S[j][k];
					a += (l[t] < l[i]), b += (r[t] > l[i]);
					c += (l[t] < l[i]) && (r[t] > l[i]);
				}
				if (a * b - c) {
					x += 2, y = 1ll * y * (a * b - c) % mod;
				} else if (a + b) {
					x++, y = 1ll * y * (a + b) % mod;
				}
			}
		}
		if (res < x) {
			res = x, ans = 0;
		}
		if (res == x) {
			ans = (ans + y) % mod;
		}
	}
	printf("%d %d\n", res, ans);
	return 0;
}