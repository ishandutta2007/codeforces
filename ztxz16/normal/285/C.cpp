#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int i, n, a[300005];

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long s = 0;
	for (i = 1; i <= n; i++)
		s += abs(i - a[i]);
	printf("%I64d\n", s);
	return 0;
}