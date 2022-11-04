#include <stdio.h>
#include <stdlib.h>

int n, m, i, j, x, y, a[1005];
double f[1005][1005], temp[1005][1005], Ans;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i != j && a[i] < a[j])
				f[i][j] = 1.0;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		if (x > y)
			x ^= y, y ^= x, x ^= y;
		for (j = 1; j <= n; j++)
		{
			if (j == x || j == y)
				continue;
			temp[x][j] = f[x][j] * 0.5 + f[y][j] * 0.5;
			temp[j][x] = f[j][x] * 0.5 + f[j][y] * 0.5;
		}
		
		for (j = 1; j <= n; j++)
		{
			if (j == x || j == y)
				continue;
			temp[j][y] = f[j][y] * 0.5 + f[j][x] * 0.5;
			temp[y][j] = f[y][j] * 0.5 + f[x][j] * 0.5;
		}
		
		for (j = 1; j <= n; j++)
		{
			if (j == x || j == y)
				continue;
			f[x][j] = temp[x][j], f[j][x] = temp[j][x];
			f[j][y] = temp[j][y], f[y][j] = temp[y][j];
		}
		
		f[x][y] = f[y][x] = 0.5;
	}
	
	for (i = 2; i <= n; i++)
		for (j = 1; j < i; j++)
			Ans += f[i][j];
	printf("%.10lf\n", Ans);
	return 0;
}