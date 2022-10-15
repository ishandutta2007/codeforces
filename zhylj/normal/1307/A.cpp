#include <bits/stdc++.h>

const int kMaxN = 2333 + 5;

int a[kMaxN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, d, ans = 0;
		scanf("%d%d%d", &n, &d, &ans);
		for(int i = 2; i <= n; ++i) {
			scanf("%d", a + i);
			ans += std::min(d / (i - 1), a[i]);
			d -= (std::min(d / (i - 1), a[i])) * (i - 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}