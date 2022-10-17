#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, a[N], pre[N], suf[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1, s = 0; i <= n; ++i) {
		s += a[i];
		pre[i] = min(pre[i - 1], s);
	} 
	for(int i = n, s = 0; i; --i) {
		s += a[i];
		suf[i] = min(suf[i + 1], s);
	}
	int ans = -INT_MAX;
	for(int i = 0; i < n; ++i) ans = max(ans, -2 * (pre[i] + suf[i + 1]));
	for(int i = 1; i <= n; ++i) ans += a[i];
	printf("%d\n", ans);
	return 0;
}