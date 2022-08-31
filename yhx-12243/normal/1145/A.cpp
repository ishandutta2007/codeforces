#include <bits/stdc++.h>

const int N = 54;

int n;
int a[N];

int main() {
	int i, j, ans = 1;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; i <<= 1)
		for (j = 0; j < n; j += i)
			if (std::is_sorted(a + j, a + (j + i))) ans = i;
	printf("%d\n", ans);
	return 0;
}