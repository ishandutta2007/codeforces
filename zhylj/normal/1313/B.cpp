#include <bits/stdc++.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		if(y >= x) std::swap(x, y);
		int maxn = std::min(x + y - 1, n), zs = std::min(std::max(x + y - n + 1, 1), n);
		printf("%d %d\n", zs, maxn);
	}
	return 0;
}