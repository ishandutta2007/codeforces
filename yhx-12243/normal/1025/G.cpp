#include <bits/stdc++.h>

const int mod = 1000000007;

int n;
int pw2[540], size[540];

int main() {
	int i, x; long long s = 0;
	scanf("%d", &n);
	for (*pw2 = i = 1; i <= n; ++i) pw2[i] = pw2[i - 1] * 2 % mod, scanf("%d", &x), ~x && ++size[x];
	for (i = 1; i <= n; ++i) s -= pw2[ size[i] ] - 1;
	s = (s + pw2[n - 1] - 1) % mod;
	printf("%d\n", int(s + (s >> 63 & mod)));
	return 0;
}