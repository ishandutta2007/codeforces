#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, j, k, x, Ans, xx;
int ok[105][105], map[105][105];
int hash[105];

void dfs(int i);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		xx += k;
		for (j = 1; j <= k; j++)
			scanf("%d", &x), ok[i][x] = 1;
	}
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= m; k++)
				if (ok[i][k] + ok[j][k] == 2)
					map[i][j] = map[j][i] = 1;
	for (i = 1; i <= n; i++)
		if (hash[i] == 0)
			Ans++, dfs(i);
	if (xx == 0)
		printf("%d\n", Ans);
	else
		printf("%d\n", Ans - 1);
	return 0;
}

void dfs(int i)
{
	int j;
	if (hash[i] == 1)
		return;
	hash[i] = 1;
	for (j = 1; j <= n; j++)
		if (map[i][j] == 1)
			dfs(j);
	return;
}