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

int x, k, pp;
double f[205][205], p;

int main()
{
    scanf("%d %d %d", &x, &k, &pp);
    p = pp / 100.0;
    for (int i = 0; i <= k; i++)
    {
		for (int j = 0; j <= k; j++)
		{
			if (!i)
				for (int l = x + j; l % 2 == 0; l /= 2)
					f[0][j] += 1.0;
			else
			{
				f[i][j] += (f[i - 1][j + 1] * (1.0 - p));
				if (!(j & 1))
					f[i][j] += (p * (f[i - 1][j >> 1] + 1.0));
			}
		}
	}
	
	printf("%.10f\n", f[k][0]);
	return 0;
}