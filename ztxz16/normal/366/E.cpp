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

int n, m, k, s, i, j, x, y, ans;
int Max[16][16], Now[16], temp[16];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for (i = 1; i <= k; i++)
		Max[i][0] = Max[i][1] = Max[i][2] = Max[i][3] = -2000000000;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &x);
			Max[x][0] = max(Max[x][0], 0 - i - j);
			Max[x][1] = max(Max[x][1], 0 - i + j);
			Max[x][2] = max(Max[x][2], 0 + i - j);
			Max[x][3] = max(Max[x][3], 0 + i + j);
		}
	ans = 0;
	scanf("%d", &y);
	for (i = 2; i <= s; i++)
	{
		scanf("%d", &x);
		ans = max(ans, Max[x][3] + Max[y][0]);
		ans = max(ans, Max[x][2] + Max[y][1]);
		ans = max(ans, Max[x][1] + Max[y][2]);
		ans = max(ans, Max[x][0] + Max[y][3]);
		y = x;
		
	}
	
	printf("%d\n", ans);
	return 0;
}