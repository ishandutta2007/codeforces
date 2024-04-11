#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int i, j, k, l, n, tj, tk, ok[16], Ans[1005];
int f[1005][16][16], sj[1005][16][16], sk[1005][16][16];
char str[16];

int main()
{
	gets(str + 1);
	for (i = 1; i <= 10; i++)
		if (str[i] == '1')
			ok[i] = 1;
	scanf("%d", &n);
	f[0][0][0] = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j <= 10; j++)
			for (k = 0; k <= 10; k++)
			{
				if (f[i][j][k] == 0)
					continue;
				for (l = 1; l <= 10; l++)
					if (l > k && l != j && ok[l] == 1)
					{
						f[i + 1][l][l - k] = 1;
						sj[i + 1][l][l - k] = j;
						sk[i + 1][l][l - k] = k;
					}
			}
	for (j = 1; j <= 10; j++)
		for (k = 1; k <= 10; k++)
			if (f[n][j][k] == 1)
				tj = j, tk = k;
	j = tj, k = tk, i = n;
	if (tj == 0)
		printf("NO\n");
	else
	{
		printf("YES\n");
		while (i > 0)
		{
			Ans[++Ans[0]] = sk[i][j][k] + k;
			tj = sj[i][j][k], tk = sk[i][j][k];
			j = tj, k = tk, i--;
		}
		
		for (i = Ans[0]; i >= 1; i--)
		printf("%d ", Ans[i]);
		printf("\n");	
	}
	return 0;
}