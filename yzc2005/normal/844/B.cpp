#include <bits/stdc++.h>
using namespace std;

const int N = 55;
typedef long long ll;

int n, m, a[N][N], r[N], c[N];
ll ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) 
			scanf("%d", &a[i][j]), 
			r[i] += a[i][j], c[j] += a[i][j];
	for(int i = 1; i <= n; ++i) ans += (1ll << r[i]) + (1ll << m - r[i]);
	for(int i = 1; i <= m; ++i) ans += (1ll << c[i]) + (1ll << n - c[i]);
	printf("%lld\n", ans - 2 * (n + m) - n * m);
}