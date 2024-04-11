#include <bits/stdc++.h>

const int kN = 2e5 + 5;

int a[kN], b[kN];

int main() {
	int n, m, ans = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) a[i] %= m;
	for(int i = 1; i <= n; ++i) b[i] = a[i];
	std::sort(b + 1, b + n + 1);
	for(int i = 1; i < n; ++i) if(b[i] == b[i + 1]) {
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			ans = ans * (a[i] - a[j] + m) % m;
	printf("%d", ans);
	return 0;
}