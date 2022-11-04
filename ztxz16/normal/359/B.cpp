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

int n, k, i;

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		if (k > 0)
			printf("%d %d ", (i << 1), ((i << 1) - 1)), k--;
		else
			printf("%d %d ", ((i << 1) - 1), (i << 1));
	printf("\n");
	return 0;
}