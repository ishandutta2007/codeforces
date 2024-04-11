#include <bits/stdc++.h>

int n;

int main() {
	int i;
	scanf("%d", &n);
	for (i = 2; i < n; ++i)
		if (!(n % i))
			return printf("%d%d\n", i, n / i), 0;
	return 0;
}