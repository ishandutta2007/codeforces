#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, m, k[Maxn], c[Maxn];
long long ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &k[i]);
		for (int i = 1; i <= m; i++)
			scanf("%d", &c[i]);
		sort(k + 1, k + 1 + n);
		int pnt = n;
		for (int i = 1; i <= n; i++)
			if (i <= k[pnt]) ans += c[i], pnt--;
		for (int i = pnt; i >= 1; i--)
			ans += c[k[i]];
		printf("%lld\n", ans);
	}
	return 0;
}