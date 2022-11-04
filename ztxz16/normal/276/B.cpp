#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

char str[100005], x;
int hash[100005];
int i, sum;

int main()
{
	gets(str);
	for (i = 0; str[i] != 0; i++)
		hash[str[i]]++;
	for (x = 'a'; x <= 'z'; x++)
		if ((hash[x] & 1) == 1)
			sum++;
	if (sum <= 1)
		printf("First\n");
	else if ((sum & 1) == 1)
		printf("First\n");
	else
		printf("Second\n");
	return 0;
}