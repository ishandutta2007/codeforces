#include <bits/stdc++.h>

const int kN = 1e5 + 5;

int x[kN], y[kN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", x + i);
		for(int i = 1; i <= n; ++i) scanf("%d", y + i);
		std::sort(x + 1, x + n + 1);
		std::sort(y + 1, y + n + 1);
		for(int i = 1; i <= n; ++i)
			printf("%d ", x[i]);
		printf("\n");
		for(int i = 1; i <= n; ++i)
			printf("%d ", y[i]);
		printf("\n");
	}
	return 0;
}