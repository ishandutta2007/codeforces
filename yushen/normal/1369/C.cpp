#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, k, cnt, a[Maxn], w[Maxn];
long long ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &w[i]);
			if (w[i] == 1) cnt++, i--, k--;
		}
		sort(a + 1, a + 1 + n), sort(w + 1, w + 1 + k, greater <int>());
		for (int i = n; i >= n - k - cnt + 1; i--)
			ans += a[i];
		for (int i = n; i >= n - cnt + 1; i--)
			ans += a[i];
		int pnt = 1;
		for (int i = 1; i <= k; i++)
			if (w[i] > 1) ans += a[pnt], pnt += w[i] - 1;
		printf("%lld\n", ans);
	}
	return 0;
}