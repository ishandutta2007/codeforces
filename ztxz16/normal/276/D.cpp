#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long mi[105], i, l, r, temp, Ans;

int main()
{
	mi[0] = 1;
	for (i = 1; i <= 62; i++)
		mi[i] = mi[i - 1] + mi[i - 1];
	scanf("%I64d %I64d", &l, &r);
	if (l == r)
	{
		printf("0\n");
		return 0;
	}
	
	for (i = 62; i >= 0; i--)
	{
		if ((r & mi[i]) == 0)
			continue;
		if ((l & mi[i]) > 0)
			continue;
		break;
	}
	
	printf("%I64d\n", mi[i] + mi[i] - 1);
	return 0;
}