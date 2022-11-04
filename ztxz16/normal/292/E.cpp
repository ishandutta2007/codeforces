#include <stdio.h>
#include <stdlib.h>

int left[400005], right[400005], tag[400005];
int x, y, k, a[100005], b[100005], kind;
int n, m, i, Ans;

void make(int l, int r, int i);
void cover(int l, int r, int i, int c);
void Ask(int l, int r, int i);

int main()
{
	scanf("%d %d", &n, &m);
	make(1, n, 1);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &kind);
		if (kind == 1)
		{
			scanf("%d %d %d", &x, &y, &k);
			cover(y, y + k - 1, 1, x - y);
		}
		
		if (kind == 2)
		{
			scanf("%d", &x);
			Ask(x, x, 1);
			if (Ans == 16161616)
				printf("%d\n", b[x]);
			else
				printf("%d\n", a[x + Ans]);
		}
	}
	
	return 0;
}

void make(int l, int r, int i)
{
	int mid = ((l + r) >> 1);
	left[i] = l, right[i] = r;
	tag[i] = 16161616;
	if (l == r)
		return;
	make(l, mid, (i << 1));
	make(mid + 1, r, ((i << 1) | 1));
	return;
}

void cover(int l, int r, int i, int c)
{
	int lc, rc;
	if (l > right[i] || r < left[i])
		return;
	if (l <= left[i] && r >= right[i])
	{
		tag[i] = c;
		return;
	}
	
	lc = (i << 1);
	rc = (lc | 1);
	if (tag[i] != 16161616)
	{
		tag[lc] = tag[i];
		tag[rc] = tag[i];
		tag[i] = 16161616;
	}
	
	cover(l, r, lc, c);
	cover(l, r, rc, c);
	return;
}

void Ask(int l, int r, int i)
{
	int lc, rc;
	if (l > right[i] || r < left[i])
		return;
	if (l <= left[i] && r >= right[i])
	{
		Ans = tag[i];
		return;
	}
	
	lc = (i << 1);
	rc = (lc | 1);
	if (tag[i] != 16161616)
	{
		tag[lc] = tag[i];
		tag[rc] = tag[i];
		tag[i] = 16161616;
	}
	
	Ask(l, r, lc);
	Ask(l, r, rc);
	return;
}