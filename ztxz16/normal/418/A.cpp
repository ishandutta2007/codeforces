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

int n, k, i, j, x;

int main()
{
	scanf("%d %d", &n, &k);
	x = n * (n - 1) / 2;
	if (k * n > x)
	{
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n", n * k);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= k; j++)
			printf("%d %d\n", i, (i + j - 1) % n + 1);
	return 0;
}