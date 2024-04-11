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

int n, m, a, b, i, j, Ans, Now, du[105], ok[105][105], list[105], Hash[105];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a, &b), du[a]++, du[b]++, ok[a][b] = ok[b][a] = 1;
	Ans = 0;
	while (1)
	{
		list[0] = 0;
		for (i = 1; i <= n; i++)
			if (Hash[i] == 0 && du[i] == 1)
				list[++list[0]] = i;
		for (i = 1; i <= list[0]; i++)
		{
			Now = list[i];
			Hash[Now] = 1;
			for (j = 1; j <= n; j++)
				if (ok[Now][j] == 1)
					du[j]--;
		}
		
		if (list[0] == 0)
			break;
		Ans++;
	}
	
	printf("%d\n", Ans);
	return 0;
}