#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, kind, x1, y1, x2, y2, v;
int A[1005][1005][5];

void Add(int a, int b, int v);
int Ask(int a, int b);

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &kind);
		if (kind == 1)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			printf("%d\n", Ask(x2, y2) ^ Ask(x1 - 1, y1 - 1) ^ Ask(x1 - 1, y2) ^ Ask(x2, y1 - 1));
		}
		
		else
		{
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
			Add(x1, y1, v);
			Add(x1, y2 + 1, v);
			Add(x2 + 1, y1, v);
			Add(x2 + 1, y2 + 1, v);
		}
	}
	
	return 0;
}

void Add(int a, int b, int v)
{
	int i, j;
	for (i = a; i <= n; i += (i & (0 - i)))
		for (j = b; j <= n; j += (j & (0 - j)))
		{
			A[i][j][0] ^= v;
			if ((a & 1) == 1)
				A[i][j][1] ^= v;
			if ((b & 1) == 1)
				A[i][j][2] ^= v;
			if (((a * b) & 1) == 1)
				A[i][j][3] ^= v;
		}
	return;
}

int Ask(int a, int b)
{
	int ret = 0;
	int i, j;
	for (i = a; i > 0; i -= (i & (0 - i)))
		for (j = b; j > 0; j -= (j & (0 - j)))
		{
			ret ^= A[i][j][3];
			if ((a & 1) == 0)
				ret ^= A[i][j][2];
			if ((b & 1) == 0)
				ret ^= A[i][j][1];
			if ((((a + 1) * (b + 1)) & 1) == 1)
				ret ^= A[i][j][0];
		}
	return ret;
}