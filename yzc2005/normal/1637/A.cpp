#include <bits/stdc++.h>
using namespace std;
int n, a[10005], pre[10005], suf[10005];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	suf[n + 1] = 1e9;
	for (int i = 1; i <= n; ++i)
		pre[i] = max(pre[i - 1], a[i]);
	for (int i = n; i; --i)
		suf[i] = min(suf[i + 1], a[i]);
	for (int i = 1; i < n; ++i) {
		if (pre[i] > suf[i + 1]) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}