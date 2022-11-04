#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, j, a, b, now, s1, s2;
int e[100005], succ[100005], last[100005], sum;
int hash[160], h2[160];
int list[50][50];

void dfs(int i);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i<= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	for (i = 1; i <= n; i++)
	{
		if (hash[i] == 1)
			continue;
		now++;
		hash[i] = 1, dfs(i);
		if (list[now][0] > 3)
		{
			printf("-1\n");
			return 0;
		}
		
		if (list[now][0] == 1)
			s1++;
		if (list[now][0] == 2)
			s2++;
	}
	
	if (s2 > s1)
	{
		printf("-1\n");
		return 0;
	}
	
	for (i = 1; i <= now; i++)
	{
		if (list[i][0] == 2)
		{
			printf("%d %d ", list[i][1], list[i][2]);
			for (j = 1; j <= now; j++)
				if (h2[j] == 0 && list[j][0] == 1)
				{
					h2[j] = 1, printf("%d\n", list[j][1]);
					break;
				}
		}
		
		if (list[i][0] == 3)
			printf("%d %d %d\n", list[i][1], list[i][2], list[i][3]);
	}
	
	int N = 0;
	for (i = 1; i <= now; i++)
	{
		if (h2[i] == 0 && list[i][0] == 1)
		{
			N++;
			printf("%d ", list[i][1]);
			if (N == 3)
				N = 0, printf("\n");
		}
	}
	
	return 0;
}

void dfs(int i)
{
	int x;
	list[now][++list[now][0]] = i;
	for (x = last[i]; x != 0; x = succ[x])
	{
		if (hash[e[x]] == 1)
			continue;
		hash[e[x]] = 1;
		dfs(e[x]);
	}
	
	return;
}