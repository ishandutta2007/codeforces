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

char ans[3005][3005];
int n, i, x, y, ymin, ymax, now;

int main()
{
	scanf("%d", &n);
	x = 0, y = ymin = ymax = 1500;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &now);
		if (i & 1)
		{
			y--;
			while (now--)
				ans[y][x] = '/', x++, y--;
			ymin = min(y + 1, ymin);
		}
		
		else
		{
			y++;
			while (now--)
				ans[y][x] = '\\', x++, y++;
			ymax = max(y - 1, ymax);
		}
	}
	
	x--;
	for (y = ymin; y <= ymax; y++)
		for (i = 0; i <= x; i++)
		{
			if (ans[y][i] == 0)
				ans[y][i] = ' ';
			if (i == x)
				printf("%c\n", ans[y][i]);
			else
				printf("%c", ans[y][i]);
		}
	return 0;
}