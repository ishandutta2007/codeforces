#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, ans, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 2; i <= n; i++)
			if (a[i] <= a[i - 1]) a[i]++;
		a[n + 1] = -1;
		for (int i = 2; i <= n + 1; i++)
			if (a[i] != a[i - 1]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}