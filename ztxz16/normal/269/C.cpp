#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, c, h, t, i, x, y;
int e[500005], succ[500005], last[500005], val[500005], sum;
int list[500005], S[500005], Now[500005];
int hash[500005];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		val[sum] = val[sum - 1] = c;
		S[a] += c;
		S[b] += c;
		if (a == 1)
			Now[b] += c, hash[sum - 1] = 1;
		if (b == 1)
			Now[a] += c, hash[sum] = 1;
	}
	
	for (i = 2; i < n; i++)
		if ((Now[i] << 1) == S[i])
			list[++t] = i;
	for (h = 1; h <= t; h++)
	{
		x = list[h];
		for (y = last[x]; y != 0; y = succ[y])
		{
			if ((y & 1) == 0)
			{
				if (hash[y - 1] == 1)
					continue;
			}
			
			else
			{
				if (hash[y + 1] == 1)
					continue;
			}
			
			hash[y] = 1;
			Now[e[y]] += val[y];
			if (e[y] != n && (Now[e[y]] << 1) == S[e[y]])
				list[++t] = e[y];
		}
	}
	
	for (i = 1; i <= sum; i += 2)
	{
		if (hash[i] == 1)
			printf("0\n");
		else
			printf("1\n");
	}
	
	return 0;
}