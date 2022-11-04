#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, j, k, a[55], p;
double f[55][55][55], x[55], Ans;

int main()
{
	scanf("%d", &n);
	x[0] = 1;
	for (i = 1; i <= n; i++)
		x[i] = x[i - 1] * i;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &p);
	f[0][0][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= i; j++)
			for (k = 0; k <= p; k++)
			{
				f[i][j][k] = f[i - 1][j][k];
				if (j >= 1 && k >= a[i])
					f[i][j][k] += f[i - 1][j - 1][k - a[i]];
			}
	for (i = 1; i <= n; i++)
		for (j = 0; j <= p; j++)
			Ans += (f[n][i][j] * x[n - i] * x[i]);
	Ans /= x[n];
	printf("%lf\n", Ans);
	return 0;
}