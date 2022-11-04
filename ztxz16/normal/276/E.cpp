#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, q, i, a, b, l, r;
int e[200005], succ[200005], last[200005], sum;
int tcolor, color[200005], scolor[200005];
int kind, v, x, d, Sum[200005];
int A[200005], B[200005], Number[200005];

void dfs(int i, int f);
void Add(int x[], int a, int b);
int Ask(int x[], int a);

int main()
{
	scanf("%d %d", &n, &q);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
		e[++sum] = a, succ[sum] = last[b], last[b] = sum;
	}
	
	Number[0] = -1;
	dfs(1, 0);
	for (i = 1; i <= tcolor; i++)
		scolor[i] = scolor[i - 1] + Sum[i];
	for (i = 1; i <= q; i++)
	{
		scanf("%d", &kind);
		if (kind == 0)
		{
			scanf("%d %d %d", &v, &x, &d);
			if (v == 1)
				Add(A, 1, x), Add(A, d + 2, 0 - x);
			else
			{
				if (Number[v] <= d)
					Add(A, 1, x), Add(A, d - Number[v] + 2, 0 - x), l = d - Number[v] + 1;
				else
					l = Number[v] - d;
				r = Number[v] + d;
				if (l < 1)
					l = 1;
				if (r > Sum[color[v]])
					r = Sum[color[v]];
				if (l > r)
					continue;
				l += scolor[color[v] - 1];
				r += scolor[color[v] - 1];
				Add(B, l, x);
				Add(B, r + 1, 0 - x);
			}
		}
		
		else
		{
			scanf("%d", &v);
			if (v == 1)
				printf("%d\n", Ask(A, 1));
			else
				printf("%d\n", Ask(B, scolor[color[v] - 1] + Number[v]) + Ask(A, Number[v] + 1));
		}
	}
	
	return 0;
}

void dfs(int i, int f)
{
	int x;
	if (f == 1)
		color[i] = ++tcolor;
	else if (f != 0)
		color[i] = color[f];
	Sum[color[i]]++;
	Number[i] = Number[f] + 1;
	for (x = last[i]; x != 0; x = succ[x])
		if (e[x] != f)
			dfs(e[x], i);
	return;
}

void Add(int x[], int a, int b)
{
	int i;
	for (i = a; i <= n; i += (i & (0 - i)))
		x[i] += b;
	return;
}

int Ask(int x[], int a)
{
	int i, ret = 0;
	for (i = a; i > 0; i -= (i & (0 - i)))
		ret += x[i];
	return ret;
}