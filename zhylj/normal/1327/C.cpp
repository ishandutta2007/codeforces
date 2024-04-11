#include <bits/stdc++.h>

const int kN = 3e5 + 5;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	std::swap(n, m);
	printf("%d\n", m - 1 + n - 1 + n * m - 1);
	for(int i = 1; i < n; ++i) printf("L");
	for(int i = 1; i < m; ++i) printf("U");
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j < m; ++j)
			printf(i % 2 ? "D" : "U");
		printf("R");
	}
	for(int j = 1; j < m; ++j)
		printf(n % 2 ? "D" : "U");
	return 0;
}