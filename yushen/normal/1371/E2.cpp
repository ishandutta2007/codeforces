#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, p, cnt, mini, a[Maxn], Ans[Maxn];
int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		mini = max(a[i] - i + 1, mini);
	int lt = mini - 1, rt = mini + 99999;
	while (lt + 1 <= rt)
	{
		int mid = (lt + rt + 1) >> 1, pnt = 1;
		long long ans = 1;
		for (int j = 1; j <= n; j++)
		{
			while (pnt <= n && a[pnt] - j + 1 <= mid) pnt++;
			(ans *= pnt - j) %= p;
		}
		if (!ans) rt = mid - 1;
		else lt = mid;
	}
	printf("%d\n", lt - mini + 1);
	for (int i = mini; i <= lt; i++)
		printf("%d ", i);
	return 0;
}