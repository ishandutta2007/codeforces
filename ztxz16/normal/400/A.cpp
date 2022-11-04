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

int test, ans[105], i, j, k, tot;
char str[105];

int main()
{
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", str + 1);
		tot = 0;
		for (i = 1; i <= 12; i++)
		{
			if (12 % i)
				continue;
			for (j = 1; j <= i; j++)
			{
				for (k = j; k <= 12 && str[k] != 'O'; k += i);
				if (k > 12)
					break;
			}
			
			if (j <= i)
				ans[++tot] = i;
		}
		
		printf("%d", tot);
		for (i = tot; i >= 1; i--)
			printf(" %dx%d", 12 / ans[i], ans[i]);
		printf("\n");
	}
	
	return 0;
}