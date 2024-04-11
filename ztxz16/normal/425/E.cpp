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
#define mo 1000000007

int FASTBUFFER;

using namespace std;

int n, k, i, j, l, len, s, x, ans;
int mi[1000005];
int f[505][505];

int sumi(int a, int b);

int main()
{
	mi[0] = 1;
	for (i = 1; i <= 1000000; i++)
		mi[i] = mi[i - 1] * 2 % mo;
	scanf("%d %d", &n, &k);
	if (k == 0)
	{
		printf("1\n");
		return 0;
	}
	
	f[0][0] = 1;
	for (i = 1; i <= k; i++)
		for (j = 1; j <= n; j++)
		{
			f[i][j] = 0;
			for (l = 0; l < j; l++)
			{
				if (f[i - 1][l] == 0)
					continue;
				len = j - l;
				s = (n - j) * len + len;
				x = mi[s];
				x -= mi[(n - j) * len];
				x %= mo;
				while (x < 0)
					x += mo;
				(f[i][j] += (long long)f[i - 1][l] * x % mo) %= mo;
			}
			
			if (i == k)
				(ans += f[i][j]) %= mo;
		}
	printf("%d\n", ans);
	return 0;
}

int sumi(int a, int b)
{
	int ret = 1, c = a;
	while (b)
	{
		if (b & 1)
			ret = (long long)ret * c % mo;
		c = (long long)c * c % mo;
		b >>= 1;
	}
	
	return ret;
}