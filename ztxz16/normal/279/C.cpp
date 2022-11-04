#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, l, r, f1[100005], f2[100005], a[100005];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f1[n] = f2[n] = n;
	for (i = n - 1; i >= 1; i--)
	{
		if (a[i + 1] >= a[i])
			f1[i] = f1[i + 1];
		else
			f1[i] = i;
		if (a[i + 1] <= a[i])
			f2[i] = f2[i + 1];
		else
			f2[i] = i;
	}
	
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &l, &r);
		if (f2[f1[l]] >= r)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}