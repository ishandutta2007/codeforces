#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 140

using namespace std;

int n, t, i, j, tag, x, y, mid, l1x[10005], l1y[10005], tot1;
int Now1[205][205], Now2[205][205];

int main()
{
	scanf("%d %d", &n, &t);
	mid = MAX / 2;
	l1x[1] = l1y[1] = mid;
	tot1 = 1;
	Now1[mid][mid] = n;
	
	int sss = 0;
	while (1)
	{
		sss++;
		for (i = mid; i <= MAX; i++)
			for (j = mid; j <= MAX; j++)
				Now2[i][j] = 0;
		tag = 0;
		for (i = mid; i <= MAX; i++)
			for (j = mid; j <= MAX; j++)
				if (Now1[i][j] > 3)
				{
					tag = 1;
					x = Now1[i][j] / 4;
					Now2[i][j] += Now1[i][j] % 4;
					Now2[i - 1][j] += x;
					Now2[i + 1][j] += x;
					Now2[i][j - 1] += x;
					Now2[i][j + 1] += x;
				}
				
				else
					Now2[i][j] += Now1[i][j];
		for (i = mid; i <= MAX; i++)
		{
			if (Now1[mid + 1][i] > 3)
				Now2[mid][i] += Now1[mid + 1][i] / 4;
			if (Now1[i][mid + 1] > 3)
				Now2[i][mid] += Now1[i][mid + 1] / 4;
		}
		
		for (i = mid; i <= MAX; i++)
			for (j = mid; j <= MAX; j++)
				Now1[i][j] = Now2[i][j];
		if (tag == 0)
			break;
	}
	
	for (i = 1; i <= t; i++)
	{
		scanf("%d %d", &x, &y);
		if (x < 0)
			x = 0 - x;
		if (y < 0)
			y = 0 - y;
		if (x + mid > 200 || y + mid > 200)
			printf("0\n");
		else
			printf("%d\n", Now1[x + mid][y + mid]);
	}
	
	return 0;
}