#include <bits/stdc++.h>

const int N = 100054;

int n;
int x[N], y[N];

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
	if (n & 1) return puts("No"), 0;
	x[n] = *x, y[n] = *y;
	for (i = 0; i < n / 2; ++i)
		if (x[i + 1] - x[i] + x[i + n / 2 + 1] - x[i + n / 2]
		 || y[i + 1] - y[i] + y[i + n / 2 + 1] - y[i + n / 2])
			return puts("No"), 0;
	return puts("Yes"), 0;
}