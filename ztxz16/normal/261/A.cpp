#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int m, n, Sum, Now, Min, i, a[100005], q[100005];

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	scanf("%d", &m);
	Min = 10000000;
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &q[i]);
		if (q[i] < Min)
			Min = q[i];
	}
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for (i = 1; i <= n; i++)
		if ((i - 1) % (Min + 2) < Min)
			Sum += a[i];
	printf("%d\n", Sum);
	return 0;
}