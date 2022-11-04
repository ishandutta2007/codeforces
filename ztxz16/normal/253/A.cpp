#include <stdio.h>
#include <stdlib.h>

int n, m, i;

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	if (n < m)
	{
		for (i = 1; i <= n; i++)
			printf("GB");
		for (i = 1; i <= m - n; i++)
			printf("G");
	}
	
	else
	{
		for (i = 1; i <= m; i++)
			printf("BG");
		for (i = 1; i <= n - m; i++)
			printf("B");
	}
	
	printf("\n");
	return 0;
}