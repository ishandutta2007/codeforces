#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int i, s[1005];
char str[1000005];

int main()
{
	gets(str + 1);
	for (i = 1; str[i] != 0; i++)
		s[str[i]]++;
	if (s['x'] > s['y'])
		for (i = 1; i <= s['x'] - s['y']; i++)
			printf("x");
	else
		for (i = 1; i <= s['y'] - s['x']; i++)
			printf("y");
	printf("\n");
	return 0;
}