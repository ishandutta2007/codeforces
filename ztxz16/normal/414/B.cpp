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

const int mo = 1000000007;

int n, k, i, j, l, ans;
int f[2005][2005];

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		f[1][i] = 1;
	for (i = 1; i < k; i++)
	{
		for (j = 1; j <= n; j++)
			for (l = j; l <= n; l += j)
				(f[i + 1][l] += f[i][j]) %= mo;
	}
	
	for (i = 1; i <= n; i++)
		(ans += f[k][i]) %= mo;
	printf("%d\n", ans);
	return 0;
}