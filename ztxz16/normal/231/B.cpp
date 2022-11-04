#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, d, l, i, sur[105], Ans[105];

int main()
{
	scanf("%d %d %d", &n, &d, &l);
	if (d > 0)
	{
		for (i = 1; i <= n; i++)
			if ((i & 1) == 1)
				sur[i] = l - 1, Ans[i] = 1;
			else
				sur[i] = 0, Ans[i] = 1;
		if ((n & 1) == 1)
			sur[n]++, d--;
		while (d > 0)
		{
			for (i = 1; i <= n; i++)
				if (sur[i] > 0)
					break;
			if (i > n)
				break;
			sur[i]--, Ans[i]++;
			d--;
		}
	
		if (d > 0)
			printf("-1\n");
		else
		{
			for (i = 1; i <= n; i++)
				printf("%d ", Ans[i]);
			printf("\n");
		}
	}
	
	else
	{
		d = 0 - d;
		for (i = 1; i <= n; i++)
			if ((i & 1) == 1)
				sur[i] = 0, Ans[i] = 1;
			else
				sur[i] = l - 1, Ans[i] = 1;
		if ((n & 1) == 1)
			d++;
		while (d > 0)
		{
			for (i = 1; i <= n; i++)
				if (sur[i] > 0)
					break;
			if (i > n)
				break;
			sur[i]--, Ans[i]++;
			d--;
		}
	
		if (d > 0)
			printf("-1\n");
		else
		{
			for (i = 1; i <= n; i++)
				printf("%d ", Ans[i]);
			printf("\n");
		}
	}
	
	return 0;
}