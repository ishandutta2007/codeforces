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

int n, m, k, i, j, ans[2005];
char str[2005][2005];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++)
		scanf("%s", str[i] + 1);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (str[i][j] == 'U')
			{
				if (i & 1)
					ans[j]++;
			}
			
			else if (str[i][j] == 'L')
			{
				if (j - i + 1>= 1 && j - i + 1 <= m)
					ans[j - i + 1]++;
			}
			
			else if (str[i][j] == 'R')
			{
				if (j + (i - 1) >= 1 && j + (i - 1) <= m)
					ans[j + (i - 1)]++;
			}
		}
	for (i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}