#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N];
void solve() {
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 1; j < i; ++j)
			ans = max(ans, a[i] + a[j]);
	}
	printf("%d\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}