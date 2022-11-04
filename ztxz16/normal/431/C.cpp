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

const int mo = 1000000007;
int n, kk, d, i, j, k, l, x, ans;
int f[105][105][105];

int main()
{
	scanf("%d %d %d", &n, &kk, &d);
	f[0][0][0] = 1;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
			for (k = 0; k <= d; k++)
			{
				if (f[i][j][k] == 0)
					continue;
				x = f[i][j][k];
				for (l = 1; l <= kk && j + l <= n; l++)
				{
					int now = min(max(l, k), d);
					f[i + 1][j + l][now] += x, f[i + 1][j + l][now] %= mo;
				}
			}
	}
	
	for (i = 0; i <= n; i++)
		ans = (ans + f[i][n][d]) % mo;
	printf("%d\n", ans);
	return 0;
}