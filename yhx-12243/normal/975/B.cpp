#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 14;

int a[50], c[25];

ll solve(int *b) {
	memcpy(c, b, n << 2);
	int i, z = *c, u = z / n, v = z % n; ll ret = 0;
	for (*c = i = 0; i < n; ++i) c[i] += u;
	for (i = 1; i <= v; ++i) ++c[i];
	for (i = 0; i < n; ++i) if (!(c[i] & 1)) ret += c[i];
	return ret;
}

int main() {
	int i; ll ans = 0;
	for (i = 0; i < n; ++i) scanf("%d", a + i), a[n + i] = a[i];
	for (i = 0; i < n; ++i) ans = max(ans, solve(a + i));
	printf("%lld\n", ans);
	return 0;
}