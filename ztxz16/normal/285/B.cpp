#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, s, t, i, p[100005], tot, hash[100005];

int main()
{
	scanf("%d %d %d", &n, &s, &t);
	for (i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	if (s == t)
		printf("0\n");
	else
	{
		hash[s] = 1;
		while (1)
		{
			s = p[s], tot++;
			if (s == t)
			{
				printf("%d\n", tot);
				return 0;
			}
			
			if (hash[s] == 1)
			{
				printf("-1\n");
				return 0;
			}
			
			hash[s] = 1;
		}
	}
	
	return 0;
}