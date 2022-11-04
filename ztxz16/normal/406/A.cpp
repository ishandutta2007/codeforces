#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

int n, i, j, q, type, a[1005][1005], s;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	s = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			s ^= (a[i][j] * a[j][i]);
	scanf("%d", &q);
	for (i = 1; i <= q; i++)
	{
		scanf("%d", &type);
		if (type < 3)
			scanf("%d", &type), s = 1 - s;
		else
			printf("%d", s);
	}
	
	printf("\n");
	return 0;
}