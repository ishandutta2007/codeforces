#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, a, b, c, s;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a + b + c >= 2)
			s++;
	}
	
	printf("%d\n", s);
	return 0;
}