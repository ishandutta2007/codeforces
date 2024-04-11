#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 200054, mod = 998244353;

int n, K;
int b[N];
pr a[N];

int main() {
	int i, x; ll s = 0, t = 1;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; ++i) scanf("%d", &x), a[i] = pr(x, i);
	std::sort(a + 1, a + (n + 1), std::greater <pr> ());
	for (i = 1; i <= K; ++i) s += a[i].first, b[i] = a[i].second;
	b[0] = 0, b[K + 1] = n + 1, std::sort(b + 1, b + (K + 1));
	for (i = 1; i < K; ++i)
		t = t * (b[i + 1] - b[i]) % mod;
	printf("%lld %lld\n", s, t);
	return 0;
}