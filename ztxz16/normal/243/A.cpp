#include <stdio.h>
#include <stdlib.h>

int n, i, j, x, Now, Ans, a[100005], hash[2000005];
int list[105], tag[105], next[21][100005];

void sort(int l, int r, int a[]);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			Ans = 1;
	}
	
	for (i = 0; i < 20; i++)
		next[i][n + 1] = n + 5;
	for (i = 0; i < 20; i++)
	{
		x = (1 << i);
		for (j = n; j >= 1; j--)
			if ((a[j] & x) > 0)
				next[i][j] = j;
			else
				next[i][j] = next[i][j + 1];
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < 20; j++)
			list[j] = next[j][i], tag[j] = j;
		sort(0, 19, list);
		if (list[0] == n + 5)
			continue;
		Now = (1 << tag[0]);
		for (j = 1; j < 20; j++)
		{
			if (list[j] == n + 5)
				break;
			if (list[j] != list[j - 1])
				hash[Now] = 1;
			Now += (1 << tag[j]);
		}
		
		hash[Now] = 1;
	}
	
	for (i = 1; i <= 2000000; i++)
		Ans += hash[i];
	printf("%d\n", Ans);
	return 0;
}

void sort(int l, int r, int a[])
{
	int i = l, j = r, k, mid;
	mid = a[l + rand() % (r - l + 1)];
	while (i <= j)
	{
		while (i <= j && a[i] < mid)
			i++;
		while (i <= j && a[j] > mid)
			j--;
		if (i <= j)
		{
			k = a[i], a[i] = a[j], a[j] = k;
			k = tag[i], tag[i] = tag[j], tag[j] = k;
			i++, j--;
		}
	}
	
	if (l < j) sort(l, j, a);
	if (i < r) sort(i, r, a);
	return;
}