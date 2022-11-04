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

int i, j, tag;
char str[16];

int main()
{
	tag = 1;
	for (i = 1; i <= 8; i++)
	{
		gets(str + 1);
		for (j = 2; j <= 8; j++)
			if (str[j] == str[j - 1])
				tag = 0;
	}
	
	if (tag == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}