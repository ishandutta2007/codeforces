#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int n, a, b, i, tot, list[400005], x[400005], hash[400005], Ans[400005];
int e[400005], succ[400005], last[400005], sum;
int tag, l2[400005], hash2[400005], h3[400005], t3, du[400005];

void dfs(int i);
int check();
void print();

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= (n << 1); i++)
	{
		scanf("%d %d", &a, &b);
		du[a]++, du[b]++;
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		if (a == 1)
			list[++tot] = b;
		if (b == 1)
			list[++tot] = a;
	}
	
	for (i = 1; i <= n; i++)
		if (du[i] != 4)
		{
			printf("-1\n");
			return 0;
		}
		
	Ans[1] = 1;
	l2[1] = 2, l2[2] = 3, l2[3] = n, l2[4] = n - 1;
	dfs(1);
	printf("-1\n");
	return 0;
}

void dfs(int i)
{
	int x;
	if (i > 4)
	{
		if (check() == 1)
			print();
		return;
	}
	
	for (x = 1; x <= tot; x++)
	{
		if (hash2[x] == 1)
			continue;
		hash2[x] = 1;
		Ans[l2[i]] = list[x];
		dfs(i + 1);
		hash2[x] = 0;
	}
	
	return;
}

int check()
{
	int i, s, xx, y, Now;
	for (i = 4; i < n - 1; i++)
		Ans[i] = 0;
	t3++;
	for (i = 1; i <= n; i++)
		h3[Ans[i]] = t3;
	for (i = 2; i <= n; i++)
	{
		if (i == 2)
			x[1] = n;
		else
			x[1] = i - 2;
		x[2] = i - 1;
		if (i == n)
			x[3] = 1, x[4] = 2;
		else if (i == n - 1)
			x[3] = n, x[4] = 1;
		else
			x[3] = i + 1, x[4] = i + 2;
		Now = Ans[i], s = 0, tag++;
		hash[Ans[x[1]]] = hash[Ans[x[2]]] = hash[Ans[x[3]]] = hash[Ans[x[4]]] = tag;
		for (xx = last[Now]; xx != 0; xx = succ[xx])
			if (hash[e[xx]] != tag)
				s++, y = e[xx];
		if (Ans[x[4]] != 0 && s > 0)
			return 0;
		if (s > 1)
			return 0;
		if (Ans[x[4]] == 0)
		{
			if (h3[y] == t3)
				return 0;
			Ans[x[4]] = y;
			h3[y] = t3;
		}
	}
	
	return 1;
}

void print()
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", Ans[i]);
	printf("\n");
	exit(0);
	return;
}