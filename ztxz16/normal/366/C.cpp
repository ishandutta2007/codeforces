#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, k, w[105], v[105], a, b, i, j, f[105][200005];

int main()
{
//	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (i = 0; i <= 200000; i++)
		f[0][i] = -1616161616;
	f[0][100000] = 0;
	for (i = 1; i <= n; i++)
	{
		a = v[i] * k - w[i], b = w[i];
		//printf("%d %d\n", a, b);
		for (j = 200000; j >= 0; j--)
			if (j - a >= 0 && j - a <= 200000 && f[i - 1][j - a] + b > f[i - 1][j])
				f[i][j] = f[i - 1][j - a] + b;
			else
				f[i][j] = f[i - 1][j];
	}
	
	if (f[n][100000] == 0)
		f[n][100000] = -1;
	printf("%d\n", f[n][100000]);
	return 0;
}