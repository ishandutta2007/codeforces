#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
int n, p, cnt, maxi, a[Maxn], Ans[Maxn];
int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), maxi = max(maxi, a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= maxi; i++)
	{
		int pnt = 1;
		long long ans = 1;
		for (int j = 1; j <= n; j++)
		{
			while (pnt <= n && a[pnt] - j + 1 <= i) pnt++;
			(ans *= pnt - j) %= p;
		}
		if (ans) Ans[++cnt] = i;
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d ", Ans[i]);
	return 0;
}