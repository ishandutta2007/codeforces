#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, i, tag, s, du[100005];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a, &b), du[a]++, du[b]++;
	tag = 1;
	for (i = 1; i <= n; i++)
		if (du[i] != 2)
			tag = 0;
	if (tag == 1)
	{
		printf("ring topology\n");
		return 0;
	}
	
	tag = 1, s = 0;
	for (i = 1; i <= n; i++)
	{
		if (du[i] > 2)
			tag = 0;
		if (du[i] == 1)
			s++;
	}
	
	if (s == 2 && tag == 1)
	{
		printf("bus topology\n");
		return 0;
	}
	
	tag = 1, s = 0;
	for (i = 1; i <= n; i++)
	{
		if (du[i] != 1 && du[i] != n - 1)
			tag = 0;
		if (du[i] == n - 1)
			s++;
	}
	
	if (s == 1 && tag == 1)
	{
		printf("star topology\n");
		return 0;
	}
	
	printf("unknown topology\n");
	return 0;
}