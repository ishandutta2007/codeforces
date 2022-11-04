#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 10000000

using namespace std;

int i, j, n, ss[1000005], tot;
char hash[10000005];

int main()
{
	for (i = 2; i * i <= MAX; i++)
	{
		if (hash[i] == 1)
			continue;
		for (j = i * i; j <= MAX; j += i)
			hash[j] = 1;
	}
	
	for (i = 2; i <= MAX; i++)
		if (hash[i] == 0)
			ss[++tot] = i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		printf("%d ", ss[i]);
	printf("\n");
	return 0;
}