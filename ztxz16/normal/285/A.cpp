#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, i;

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k; i++)
		printf("%d ", n - i + 1);
	for (i = 1; i <= n - k; i++)
		printf("%d ", i);
	return 0;
}