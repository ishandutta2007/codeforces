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

int n, k, t, need;

int main()
{
	scanf("%d %d %d", &n, &k, &t);
	need = 0;
	while (1)
	{
		if (t * k * n >= need * 100 && (need + 1) * 100 > t * k * n)
			break;
		need++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", min(need, k));
		need -= min(need, k);
	}
	
	printf("\n");
	return 0;
}