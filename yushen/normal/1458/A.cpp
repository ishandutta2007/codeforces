#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m;
long long ans, a[Maxn], b[Maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &b[i]);
	for (int i = 1; i < n; i++)
		ans = __gcd(a[i + 1] - a[i], ans);
	for (int i = 1; i <= m; i++)
		printf("%lld ", __gcd(ans, a[1] + b[i]));
	return 0;
}