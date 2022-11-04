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

int n, a[100005];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		if (n % i)
			continue;
		if (n / i < 3)
			continue;
		int tag = 0;
		for (int j = 1; j <= i; j++)
		{
			tag = 1;
			for (int k = j; k <= n; k += i)
			{
				if (!a[k])
				{
					tag = 0;
					break;
				}
			}
			
			if (tag)
				break;
		}
		
		if (tag)
		{
			printf("YES\n");
			return 0;
		}
	}
	
	printf("NO\n");
	return 0;
}