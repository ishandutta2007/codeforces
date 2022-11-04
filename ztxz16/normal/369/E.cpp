#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 1000000

using namespace std;

struct Node
{
	int l, r, type, tag;
	
	friend bool operator < (Node a, Node b)
	{
		return a.l > b.l || (a.l == b.l && a.type < b.type);
	}
}a[1000005];

int n, m, i, j, tt, tot, b[1000005], ans[1000005];
int A[1000005];

void Add(int a, int b);
int Ask(int a);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &a[i].l, &a[i].r), a[i].type = 1;
	tt = n;
	for (i = 1; i <= m; i++)
	{
		ans[i] = n;
		scanf("%d", &tot);
		for (j = 1; j <= tot; j++)
			scanf("%d", &b[j]);
		b[tot + 1] = 0, b[tot + 2] = MAX + 1, tot += 2;
		sort(b + 1, b + tot + 1);
		for (j = 2; j <= tot; j++)
			if (b[j - 1] + 1 <= b[j] - 1)
			{
				a[++tt].l = b[j - 1] + 1;
				a[tt].r = b[j] - 1;
				a[tt].type = 2;
				a[tt].tag = i;
			}
	}
	
	sort(a + 1, a + tt + 1);
	for (i = 1; i <= tt; i++)
	{
		if (a[i].type == 1)
			Add(a[i].r, 1);
		else
			ans[a[i].tag] -= Ask(a[i].r);
	}
	
	for (i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}

void Add(int a, int b)
{
	for (int i = a; i <= MAX; i += (i & (0 - i)))
		A[i] += b;
}

int Ask(int a)
{
	int ret = 0, i;
	for (i = a; i > 0; i -= (i & (0 - i)))
		ret += A[i];
	return ret;
}