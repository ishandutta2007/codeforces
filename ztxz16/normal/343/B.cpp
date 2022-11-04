#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int len, temp, i, sta[100005], tot;
char str[100005];

int main()
{
	gets(str + 1);
	len = strlen(str + 1), tot = 0;
	for (i = 1; i <= len; i++)
	{
		sta[++tot] = str[i];
		if (tot > 1 && sta[tot - 1] == str[i])
		{
			while (tot > 0 && sta[tot] == str[i])
				tot--;
		}
	}
	
	if (tot == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}