#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[10005], b[10005], c[10005];
int i, j, s, op[10005][25];

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i < n; i++)
		a[i] = 1, b[i] = n - i;
	for (i = 1; i <= n; i++)
		c[b[i]] = i;
	for (i = 2, s = 1; i < n; (i <<= 1), s++)
		for (int xx = 1; xx <= s; xx++)
			op[c[i]][++op[c[i]][0]] = c[i];
	for (i = 1; i < n; i++)
	{
		if (op[i][0] > 0)
			continue;
		op[i][++op[i][0]] = n;
		while ((a[i] & b[i]) == 0)
		{
			op[i][++op[i][0]] = i;
			a[i] += a[i];
		}
		
		for (j = a[i] + a[i]; j < n; (j <<= 1))
			if ((b[i] & j) > 0)
				op[i][++op[i][0]] = c[j];
			else
				op[i][++op[i][0]] = n;
	}
	
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= n; j++)
			if (op[j][0] >= i)
				printf("%d ", op[j][i]);
			else
				printf("%d ", n);
		printf("\n");
	}
	
	return 0;
}