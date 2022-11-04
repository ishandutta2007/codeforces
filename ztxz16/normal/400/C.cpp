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

int n, m, nn, mm, x, y, z, p, i, j, xx, yy, temp;

int main()
{
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p), nn = n, mm = m;
	x &= 3;
	y &= 1;
	z &= 3;
	for (i = 1; i <= p; i++)
	{
		scanf("%d %d", &xx, &yy);
		for (j = 1; j <= x; j++)
			temp = yy, yy = n - xx + 1, xx = temp, swap(n, m);
		if (y)
			yy = m - yy + 1;
		for (j = 1; j <= z; j++)
			temp = xx, xx = m - yy + 1, yy = temp, swap(n, m);
		printf("%d %d\n", xx, yy);
		n = nn, m = mm;
	}
	
	return 0;
}