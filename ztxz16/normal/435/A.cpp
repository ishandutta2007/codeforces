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

int n, m, x, ans, now, i;

int main()
{
	scanf("%d %d", &n, &m);
	now = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (now + x <= m)
			now += x;
		else
			now = x, ans++;
	}
	
	ans++;
	printf("%d\n", ans);
	return 0;
}