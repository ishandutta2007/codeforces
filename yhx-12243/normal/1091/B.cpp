#include <bits/stdc++.h>
#define N 2555

typedef long long ll;

int n;
ll x[N], y[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n * 2; ++i) scanf("%lld%lld", x + i, y + i), *x += x[i], *y += y[i];
	printf("%lld %lld\n", *x /= n, *y /= n);
	
	return 0;
}