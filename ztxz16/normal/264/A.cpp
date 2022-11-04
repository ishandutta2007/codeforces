#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

char str[1000005];
int len, i;
int list1[1000005], list2[1000005], tot1, tot2;

int main()
{
	gets(str + 1);
	for (i = 1; str[i] != 0; i++);
	len = i - 1;
	for (i = 1; i <= len; i++)
	{
		if (str[i] == 'l')
			list2[++tot2] = i;
		else
			list1[++tot1] = i;
	}
	
	for (i = 1; i <= tot1; i++)
		printf("%d\n", list1[i]);
	for (i = tot2; i >= 1; i--)
		printf("%d\n", list2[i]);	
	return 0;
}