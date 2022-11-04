#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, N, m, i, x, y, op[1000005], a[1000005];
int Left[1000005], Right[1000005], Val[1000005];

void Make(int l, int r, int i);
int Ask(int i, int x, int y);

int main()
{
	for (i = 2; i <= 1000000; (i <<= 1))
		op[i] = 1 - op[(i >> 1)];
	scanf("%d %d", &n, &m);
	N = (1 << n);
	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	Make(1, N, 1);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", Ask(1, x, y));
	}
	
	return 0;
}

void Make(int l, int r, int i)
{
	int mid = (l + r) >> 1, size = (r - l + 1), lc, rc;
	Left[i] = l, Right[i] = r;
	if (l == r)
	{
		Val[i] = a[l];
		return;
	}
	
	lc = (i << 1), rc = (lc | 1);
	Make(l, mid, lc);
	Make(mid + 1, r, rc);
	if (op[size] == 1)
		Val[i] = (Val[lc] | Val[rc]);
	else
		Val[i] = (Val[lc] ^ Val[rc]);
	return;
}

int Ask(int i, int x, int y)
{
	int size = (Right[i] - Left[i] + 1), lc, rc;
	if (Left[i] > x || Right[i] < x)
		return Val[i];
	if (size == 1)
		return Val[i] = y;
	lc = (i << 1), rc = (lc | 1);
	if (op[size] == 1)
		return Val[i] = (Ask(lc, x, y) | Ask(rc, x, y));
	else
		return Val[i] = (Ask(lc, x, y) ^ Ask(rc, x, y)); 
}