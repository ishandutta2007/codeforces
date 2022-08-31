#include <bits/stdc++.h>

const int N = 200054;

int n;
int a[N], b[N];

int main() {
	int i, Z = INT_MIN;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", b + i), a[1] = b[1];
	for (i = 1; i <= n; ++i)
		Z = std::max(Z, a[i]), a[i + 1] = Z + b[i + 1];
	for (i = 1; i <= n; ++i)
		printf("%d%c", a[i], i==n?10:32);
	return 0;
}