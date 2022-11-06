#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;
int n, m, i, j, x, Ans;

int main()
{
	scanf("%d %d", &n, &m);
	Ans = 4;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			if (x == 1)
			{
				if (i == 1 || i == n || j == 1 || j == m)
					Ans = 2;
			}
		}
	printf("%d\n", Ans);
	return 0;
}