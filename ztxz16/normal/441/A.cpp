#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, v, tot, a[105];

int main()
{
	scanf("%d %d", &n, &v);
	for (int i = 1; i <= n; i++)
	{
		int k, Min = OO;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++)
		{
			int x;
			scanf("%d", &x);
			Min = min(Min, x);
		}
		
		if (v > Min)	
			a[++tot] = i;
	}
	
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}