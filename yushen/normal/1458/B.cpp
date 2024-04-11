#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int n, tot, a[Maxn], b[Maxn], f[Maxn][Maxn * Maxn];
int main()
{
	scanf("%d", &n);
	memset(f, -0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]), tot += b[i];
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j >= 1; j--)
			for (int k = 10000; k >= a[i]; k--)
				f[j][k] = max(f[j][k], f[j - 1][k - a[i]] + b[i]);
	for (int i = 1; i <= n; i++)
	{
		double ans = 0;
		for (int j = 0; j <= 10000; j++)
			ans = max(ans, min((double) j, (tot + f[i][j]) / 2.0));
		printf("%.10lf ", ans);
	}
	return 0;
}