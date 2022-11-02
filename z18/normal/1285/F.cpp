#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, m, a[maxn + 3], k, p[maxn + 3], mu[maxn + 3];
int tot, num[maxn + 3], top, st[maxn + 3], cnt[maxn + 3];
bool vis[maxn + 3];
vector<int> fac[maxn + 3];

void prework(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			p[++k] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= k && i * p[j] <= n; j++) {
			vis[i * p[j]] = true;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		} 
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		a[x] = 1, m = max(m, x);
	}
	prework(m);
	for (int k = 1; k <= m; k++) {
		for (int i = k; i <= m; i += k) {
			fac[i].push_back(k);
		}
	}
	long long ans = 0;
	for (int k = 1; k <= m; k++) {
		tot = 0;
		for (int i = k; i <= m; i += k) if (a[i]) {
			ans = max(ans, 1ll * i);
			num[++tot] = i / k;
		}
		top = 0;
		fill(cnt + 1, cnt + m / k + 1, 0);
		for (int i = tot; i; i--) {
			int x = num[i];
			while (top > 0) {
				int res = 0;
				for (int j = 0; j < fac[x].size(); j++) {
					int y = fac[x][j];
					res += mu[y] * cnt[y];
				}
				if (res > 0) {
					ans = max(ans, 1ll * k * x * st[top]);
					for (int j = 0; j < fac[st[top]].size(); j++) {
						cnt[fac[st[top]][j]]--;
					}
					top--;
				} else {
					break;
				}
			}
			st[++top] = x;
			for (int j = 0; j < fac[x].size(); j++) {
				cnt[fac[x][j]]++;
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}