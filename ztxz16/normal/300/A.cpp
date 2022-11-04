#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, x, list1[1005], list2[1005], list3[1005], t1, t2, t3;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x == 0)
			list3[++t3] = x;
		else if (x > 0)
			list2[++t2] = x;
		else
			list1[++t1] = x;
	}
	
	if (t2 == 0)
		list2[++t2] = list1[t1], list2[++t2] = list1[t1 - 1], t1 -= 2;
	if ((t1 & 1) == 0)
		list3[++t3] = list1[t1], t1--;
	printf("%d ", t1);
	for (i = 1; i <= t1; i++)
		printf("%d ", list1[i]);
	printf("\n");
	printf("%d ", t2);
	for (i = 1; i <= t2; i++)
		printf("%d ", list2[i]);
	printf("\n");
	printf("%d ", t3);
	for (i = 1; i <= t3; i++)
		printf("%d ", list3[i]);
	printf("\n");
	return 0;
}