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

int m, x, y, s[10005];

int main()
{
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		s[i] = s[i - 1] + x;
	}
	
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= m; i++)
		if (s[i] >= x && s[i] <= y && s[m] - s[i] >= x && s[m] - s[i] <= y)
		{
			printf("%d\n", i + 1);
			return 0;
		}
		
	printf("0\n");
	return 0;
}