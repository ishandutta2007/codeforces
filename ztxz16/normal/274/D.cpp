#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Tp
{
	int val, tag;
};

Tp xx;
vector <Tp> map[100005];

int cmp(Tp a, Tp b)
{
	return a.val < b.val;
}

int n, m, tot, i, j, k, sum, du[1000005];
int e[1000005], succ[1000005], last[1000005];
int zl[1000005], h, t, Now, x;
int Ans[100005];

void Add(int a, int b);

int main()
{
	scanf("%d %d", &n, &m);
	tot = m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &xx.val), xx.tag = j, map[i].push_back(xx);
	for (i = 1; i <= n; i++)
	{
		sort(map[i].begin(), map[i].end(), cmp);
		for (j = 0; j < m; j++)
			if (map[i][j].val > -1)
				break;
		if (j < m)
		{
			tot++;
			Add(map[i][j].tag, tot);
			for (j++; j < m; j++)
			{
				if (map[i][j].val == map[i][j - 1].val)
					Add(map[i][j].tag, tot);
				else
				{
					for (k = j; k < m; k++)
					{
						if (map[i][k].val != map[i][j].val)
							break;
						Add(tot, map[i][k].tag);
					}
					
					tot++;
					Add(map[i][j].tag, tot);
				}
			}	
		}
	}
	
	for (i = 1; i <= tot; i++)
		if (du[i] == 0)
			zl[++t] = i;
	for (h = 1; h <= t; h++)
	{
		Now = zl[h];
		if (Now <= m)
			Ans[++Ans[0]] = Now;
		for (x = last[Now]; x != 0; x = succ[x])
		{
			du[e[x]]--;
			if (du[e[x]] == 0)
				zl[++t] = e[x];
		}
	}
	
	if (Ans[0] != m)
		printf("-1\n");
	else
	{
		for (i = 1; i <= m; i++)
			printf("%d ", Ans[i]);
		printf("\n");
	}
	
	return 0;
}

void Add(int a, int b)
{
	e[++sum] = b, succ[sum] = last[a], last[a] = sum;
	du[b]++;
	return;
}