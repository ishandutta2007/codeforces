#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5, maxm = 20;
int n, k, a[maxn + 3];
int L, R, cnt[maxn + 3];
ll cur, dp[maxm + 3][maxn + 3];

ll query(int l, int r) {
	while (R < r) cur += cnt[a[++R]]++;
	while (L > l) cur += cnt[a[--L]]++;
	while (R > r) cur -= --cnt[a[R--]];
	while (L < l) cur -= --cnt[a[L++]];
	return cur;
}

void solve(ll f[], ll g[], int l, int r, int L, int R) {
	int mid = (l + r) / 2, pos = 0;
	ll mn = 1e18;
	for (int i = L; i <= R; i++) if (i <= mid) {
		if (g[i - 1] + query(i, mid) < mn) {
			mn = g[i - 1] + query(i, mid);
			pos = i;
		}
	}
	f[mid] = mn;
	if (l < mid) {
		solve(f, g, l, mid - 1, L, pos);
	}
	if (r > mid) {
		solve(f, g, mid + 1, r, pos, R);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	L = 1, R = 0;
	for (int i = 1; i <= n; i++) {
		dp[1][i] = query(1, i);
	}
	for (int i = 2; i <= k; i++) {
		solve(dp[i], dp[i - 1], 1, n, 1, n);
	}
	printf("%lld\n", dp[k][n]);
	return 0;
}