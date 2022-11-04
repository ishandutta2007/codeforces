#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a[10005], tot, i;
char str[10005];

int main()
{
	gets(str + 1);
	for (i = 1; str[i] != 0; i += 2)
		a[++tot] = str[i] - 48;
	sort(a + 1, a + tot + 1);
	for (i = 1; i <= tot; i++)
		if (i == tot)
			printf("%d\n", a[i]);
		else
			printf("%d+", a[i]);
	return 0;
}