#include <bits/stdc++.h>

const int kN = 1e5 + 5;

int a[kN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		std::sort(a + 1, a + n + 1);
		int len = std::unique(a + 1, a + n + 1) - a - 1;
		printf("%d\n", len);
	}
	return 0;
}