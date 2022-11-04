#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, j, l, r, mid, a[1005][1005];
int Hash[1005][1005], list[1005], tot, tag;

int check(int Ans);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	l = 0, r = 1000000000;
	while (l < r)
	{
		mid = ((l + r + 1) >> 1);
		if (check(mid) == 1)
			l = mid;
		else
			r = mid - 1;
	}
		
	printf("%d\n", l);
	return 0;
}

int check(int Ans)
{
	int i, j, k;
	tag++;
	for (i = 1; i <= n; i++)
	{
		tot = 0;
		for (j = 1; j <= m; j++)
			if (a[i][j] >= Ans)
				list[++tot] = j;
		for (j = 1; j < tot; j++)
			for (k = j + 1; k <= tot; k++)
				if (Hash[list[j]][list[k]] == tag)
					return 1;
				else
					Hash[list[j]][list[k]] = tag;
	}
	
	return 0;
}