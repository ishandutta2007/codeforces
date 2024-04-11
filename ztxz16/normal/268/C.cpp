#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i;

int main()
{
	scanf("%d %d", &n, &m);
	if (n < m)
	{
		printf("%d\n", n + 1);
		for (i = 0; i <= n; i++)
			printf("%d %d\n", n - i, i);
	}
	
	else
	{
		printf("%d\n", m + 1);
		for (i = 0; i <= m; i++)
			printf("%d %d\n", i, m - i);
	}
	return 0;
}