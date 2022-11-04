#include <stdio.h>
#include <stdlib.h>

int y, k, n, i, tag = 0;

int main()
{
	scanf("%d %d %d", &y, &k, &n);
	for (i = k; i <= n; i += k)
		if (i > y)
			printf("%d ", i - y), tag = 1;
	if (tag == 0)
		printf("-1\n");
	else printf("\n");
	return 0;
}