#include <stdio.h>
#include <stdlib.h>

int n, m, h, t, i, a, b, x, xx, now, Now, s;
int e[200005], last[200005], succ[200005], sum;
int du[200005], hash[200005];

void print(int u, int v);

int main()
{
	scanf("%d %d %d %d", &n, &m, &h, &t);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
		du[a]++, du[b]++;
	}
	
	for (i = 1; i <= n; i++)
	{
		if (du[i] <= h)
			continue;
		for (x = last[i]; x != 0; x = succ[x])
			hash[e[x]] = i;
		for (x = last[i]; x != 0; x = succ[x])
		{
			now = e[x];
			if (du[now] <= t)
				continue;
			Now = du[i];
			s = du[now];
			for (xx = last[now]; xx != 0; xx = succ[xx])
			{
				if (e[xx] == i)
					continue;
				if (hash[e[xx]] == i)
				{
					if (Now > h + 1)
						Now--;
					else
						s--;
				}
				
				if (s <= t)
					break;
			}
			
			if (s > t)
				print(i, now);
		}
	}
	
	printf("NO\n");
	return 0;
}

void print(int u, int v)
{
	int x, y, s = 0, tag = n + 1;
	int i;
	printf("YES\n%d %d\n", u, v);
	for (x = last[v]; x != 0; x = succ[x])
		hash[e[x]] = tag;
	y = du[v];
	for (x = last[u]; x != 0; x = succ[x])
	{
		if (e[x] == v)
			continue;
		if (hash[e[x]] == tag)
		{
			if (y > t + 1)
				printf("%d ", e[x]), y--, s++, hash[e[x]] = tag + 1;
		}
		
		else
			printf("%d ", e[x]), s++;
		if (s == h)
			break;
	}
	
	printf("\n");
	s = 0;
	for (x = last[v]; x != 0; x = succ[x])
	{
		if (e[x] == u)
			continue;
		if (hash[e[x]] == tag)
			printf("%d ", e[x]), s++;
		if (s == t)
			break;
	}
	
	exit(0);
	return;
}