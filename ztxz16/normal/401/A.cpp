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

int n, x, a, s, i;

int main()
{
	scanf("%d %d", &n, &x);
	for (i = 1; i <= n; i++)
		scanf("%d", &a), s += a;
	if (s < 0)
		s = 0 - s;
	if (s % x == 0)
		printf("%d\n", s / x);
	else
		printf("%d\n", s / x + 1);
	return 0;
}