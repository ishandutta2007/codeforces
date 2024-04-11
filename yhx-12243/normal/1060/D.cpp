#include <bits/stdc++.h>
#define N 100010

typedef long long ll;

int n;
int l[N], r[N];
ll s = 0;

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d%d", l + i, r + i), s += l[i] + r[i] + 1;
	std::sort(l + 1, l + (n + 1));
	std::sort(r + 1, r + (n + 1));
	for (i = 1; i <= n; ++i) s -= std::min(l[i], r[i]);
	printf("%lld\n", s);
	return 0;
}