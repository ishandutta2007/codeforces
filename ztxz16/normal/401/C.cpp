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

int n, m, i;

int main()
{
	scanf("%d %d", &n, &m);
	if (n > m + 1 || n < (m - 1) / 2)
	{
		printf("-1\n");
		return 0;
	}
	
	n -= (m - 1) / 2;
	if (n)
		putchar('0'), n--;
	for (i = 1; i <= m; i++)
	{
		putchar('1');
		if ((i & 1) || (i == m))
		{
			if (n)
				putchar('0'), n--;
		}
		
		else
			putchar('0');
	}
	
	putchar('\n');
	return 0;
}