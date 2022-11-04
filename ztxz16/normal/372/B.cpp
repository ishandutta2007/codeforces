#include <stdio.h>
#include <stdlib.h>

int n, m, q, i, x1, y1, x2, y2;
char str[105][105];
int f[41][41][41][41], up[105][105], now, ans;

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	gets(str[0] + 1);
	for (i = 1; i <= n; i++)
		gets(str[i] + 1);
	for (x1 = 1; x1 <= n; x1++)
		for (y1 = 1; y1 <= m; y1++)
		{
			for (x2 = x1; x2 <= n; x2++)
				for (y2 = y1; y2 <= m; y2++)
					if (str[x2][y2] == '1')
						up[x2][y2] = 0;
					else if (x2 == x1)
						up[x2][y2] = 1;
					else
						up[x2][y2] = up[x2 - 1][y2] + 1;
			for (x2 = x1; x2 <= n; x2++)
				for (y2 = y1; y2 <= m; y2++)
				{
					if (x2 == x1 && y2 == y1)
						f[x1][y1][x2][y2] = 0;
					else if (x2 == x1)
						f[x1][y1][x2][y2] = f[x1][y1][x2][y2 - 1];
					else if (y2 == y1)
						f[x1][y1][x2][y2] = f[x1][y1][x2 - 1][y2];
					else
						f[x1][y1][x2][y2] = f[x1][y1][x2 - 1][y2] + f[x1][y1][x2][y2 - 1] - f[x1][y1][x2 - 1][y2 - 1];
					ans = now = up[x2][y2];
					for (i = y2 - 1; i >= y1; i--)
					{
						if (up[x2][i] < now)
							now = up[x2][i];
						if (now == 0)
							break;
						ans += now;
					}
					
					f[x1][y1][x2][y2] += ans;
				}
		}
	while (q--)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", f[x1][y1][x2][y2]);
	}
	
	return 0;
}