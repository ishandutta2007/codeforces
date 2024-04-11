#include <bits/stdc++.h>

const int N = 105;

int n;
int a[N];

int main() {
	int i, j, x, ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &x), a[x] = 1;
	for (i = 1; i <= 100; ++i)
		if (a[i]) {
			for (j = i; j <= 100; j += i) a[j] = 0;
			++ans;
		}
	printf("%d\n", ans);
	return 0;
}