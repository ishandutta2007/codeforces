#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, j, Max;
int a[5005], f[5005];
double b[5005];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d %lf", &a[i], &b[i]);
	f[1] = 1, Max = 1;
	for (i = 2; i <= n; i++)
	{
		f[i] = 1;
		for (j = 1; j < i; j++)
			if (a[j] <= a[i] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
		if (f[i] > Max)
			Max = f[i];
	}
	
	printf("%d\n", n - Max);
	return 0;
}